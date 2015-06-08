#include <cstdio>
#include <cstring>
#define MAXN 1130
#define MAXP 190
#define MAXK 15

using namespace std;

bool check[MAXN+5];
int prime[MAXN];
int pi;
int dp[MAXN][MAXP][MAXK];

void init() {
  pi = 0;
  memset(check, false, sizeof check);
  for(int i = 2; i <= MAXN; i++) {
    if(!check[i])
      prime[pi++] = i;
    for(int j = 0; j < pi; j++) {
      if(prime[j] * i > MAXN)
	break;
      check[prime[j]*i] = true;
      if(i % prime[j] == 0)
	break;
    }
  }
}

int f(int num, int i, int cnt) {
  if(dp[num][i][cnt] != -1)
    return dp[num][i][cnt];
  if(prime[i] * cnt > num)
    return dp[num][i][cnt] = 0;
  if(cnt == 0)
    return dp[num][i][cnt] = num == 0 ? 1 : 0;
  int ans = 0;
  for(int ii = i; ii < pi; ii++) {
    if(prime[ii] > num)
      break;
    ans += f(num - prime[ii], ii + 1, cnt-1);
  }
  return dp[num][i][cnt] = ans;
}

int main() {
  init();
  memset(dp, -1, sizeof dp);
  int n, k;
  while(scanf("%d %d", &n, &k) != EOF && (n || k)) {
    printf("%d\n", f(n, 0, k));
  }
  return 0;
}
