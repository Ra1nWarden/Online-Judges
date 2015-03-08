#include <cstdio>
#include <cstring>
#define MAXN 21

using namespace std;

int v[2*MAXN][MAXN];
long long dp[2*MAXN][MAXN][501];
int n, s;

long long f(int i, int j, int sum) {
  if(dp[i][j][sum] != -1)
    return dp[i][j][sum];
  if(v[i][j] > sum)
    return dp[i][j][sum] = 0;
  if(i == 2*n - 2)
    return dp[i][j][sum] = (v[i][j] == sum ? 1 : 0);
  if(i < n - 1) {
    long long res = 0;
    if(j > 0)
      res += f(i+1, j - 1, sum - v[i][j]);
    if(j < n - i - 1)
      res += f(i+1, j, sum - v[i][j]);
    return dp[i][j][sum] = res;
  } else {
    long long res = f(i+1, j, sum - v[i][j]);
    res += f(i+1, j+1, sum - v[i][j]);
    return dp[i][j][sum] = res;
  }
}

int main() {
  while(scanf("%d %d", &n, &s) != EOF && (n || s)) {
    for(int i = 0; i < 2*n -1; i++) {
      int len;
      if(i < n)
	len = n - i;
      else
	len = 2 + i - n;
      for(int j = 0; j < len; j++)
	scanf("%d", &v[i][j]);
    }
    memset(dp, -1, sizeof dp);
    long long res = 0;
    for(int i = 0; i < n; i++) {
      if(f(0, i, s) > 0) {
	res += f(0, i, s);
      }
    }
    printf("%lld\n", res);
    for(int i = 0; i < n; i++) {
      if(f(0, i, s) > 0) {
	printf("%d ", i);
	int prev = i;
	int sum = s - v[0][i];
	for(int j = 1; j < n; j++) {
	  if(prev > 0 && f(j, prev - 1, sum) > 0) {
	    sum = sum - v[j][prev - 1];
	    prev = prev - 1;
	    printf("L");
	  } else {
	    //printf("%d row prev %d sum is %d f=%d\n", j, prev, sum, f(j, prev, sum));
	    sum = sum - v[j][prev];
	    printf("R");
	  }
	}
	for(int j = n; j < 2 * n -1; j++) {
	  if(f(j, prev, sum) > 0) {
	    sum -= v[j][prev];
	    printf("L");
	  } else {
	    sum -= v[j][prev+1];
	    prev = prev + 1;
	    printf("R");
	  }
	}
	break;
      }
    }
    printf("\n");
  }
  return 0;
}
