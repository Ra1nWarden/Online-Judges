#include <cstdio>
#include <cstring>
#include <algorithm>
#define MAXN 205
#define INF 2e9

using namespace std;

char str[MAXN];
int dp[MAXN][MAXN];
int l;

int f(int i, int j) {
  //printf("calling f(%d, %d)\n", i, j);
  if(dp[i][j] != -1)
    return dp[i][j];
  if(i == j)
    return dp[i][j] = 1;
  int res = j - i + 1;
  for(int k = i; k < j; k++)
    res = min(res, f(i, k) + f(k+1, j));
  //printf("res is %d\n", res);
  int interval = j - i + 1;
  for(int k = 1; k <= interval / 2; k++) {
    if(interval % k == 0) {
      bool ok = true;
      for(int jj = 0; jj < k; jj++) {
	for(int ii = i; ii + k <= j; ii += k) {
	  if(str[ii + jj] != str[ii + jj + k]) {
	    ok = false;
	    break;
	  }
	}
	if(!ok)
	  break;
      }
      if(ok) {
	int repeat = interval / k;
	int add;
	if(repeat < 10)
	  add = 1;
	else if(repeat < 100)
	  add = 2;
	else
	  add = 3;
	//printf("add is %d, repeat length is %d\n", add, k);
	res = min(res, f(i, i+k-1) + 2 + add);
      }
    }
  }
  return dp[i][j] = res;
}

int main() {
  int tc;
  scanf("%d\n", &tc);
  while(tc--) {
    scanf("%s\n", str);
    l = strlen(str);
    memset(dp, -1, sizeof dp);
    //printf("here\n");
    printf("%d\n", f(0, l-1));
  }
  return 0;
}
