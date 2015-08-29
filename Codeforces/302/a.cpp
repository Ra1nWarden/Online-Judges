#include <cstdio>
#define MAXN 501

using namespace std;

int n, m, b, mod;
int v[MAXN];
int dp[2][MAXN][MAXN];

int main() {
  scanf("%d%d%d%d", &n, &m, &b, &mod);
  for(int i = 0; i < n; i++) {
    scanf("%d", &v[i]);
  }
  dp[0][0][0] = 1;
  for(int i = 1; i <= n; i++) {
    for(int j = 0; j <= m; j++) {
      for(int k = 0; k <= b; k++) {
	dp[i&1][j][k] = dp[(i&1)^1][j][k];
	if(j > 0 && k >= v[i-1])
	  dp[i&1][j][k] += dp[i&1][j-1][k-v[i-1]];
	dp[i&1][j][k] %= mod;
      }
    }
  }

  int ans = 0;
  for(int i = 0; i <= b; i++) {
    ans += dp[n&1][m][i];
    ans %= mod;
  }
  printf("%d\n", ans);
  return 0;
}
