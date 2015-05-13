#include <cstring>
#include <cstdio>
#include <algorithm>
#define MAXN 1005
#define MOD 10056

using namespace std;

int c[MAXN][MAXN];
int dp[MAXN];

int f(int n) {
  if(dp[n] != -1)
    return dp[n];
  int ans = 0;
  for(int i = 1; i <= n; i++) {
    ans += c[n][i] * max(f(n - i), 1);
    ans %= MOD;
  }
  return dp[n] = ans;
}

int main() {
  for(int i = 1; i <= 1000; i++) {
    for(int j = 0; j <= i; j++) {
      if(i == j || j == 0)
	c[i][j] = 1;
      else
	c[i][j] = (c[i-1][j] + c[i-1][j-1]) % MOD;
    }
  }
  memset(dp, -1, sizeof dp);
  int tc;
  scanf("%d", &tc);
  for(int kase = 1; kase <= tc; kase++) {
    int n;
    scanf("%d", &n);
    printf("Case %d: %d\n", kase, f(n));
  }
  return 0;
}
