#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int mod = 998244353;
const int maxn = 1000;
int dp[2][4][maxn*2+5];

int add(int a, int b, int c, int d) {
  return ((a + b) % mod + (c + d) % mod) % mod;
}

int main() {
  int n, k;
  scanf("%d %d", &n, &k);
  memset(dp, 0, sizeof dp);
  dp[1][0][1] = dp[1][3][1] = 1;
  dp[1][1][2] = dp[1][2][2] = 1;
  for(int i = 2; i <= n; i++) {
    for(int j = 1; j <= min(2 * i, k); j++) {
      int ii = i&1;
      dp[ii][0][j] = add(dp[ii^1][0][j], dp[ii^1][1][j], dp[ii^1][2][j], (j > 1 ? dp[ii^1][3][j-1] : 0));
      dp[ii][1][j] = add((j > 1 ? dp[ii^1][0][j-1] : 0), dp[ii^1][1][j], (j > 2 ? dp[ii^1][2][j-2] : 0), (j > 1 ? dp[ii^1][3][j-1] : 0));
      dp[ii][2][j] = add((j > 1 ? dp[ii^1][0][j-1] : 0), (j > 2 ? dp[ii^1][1][j-2] : 0), dp[ii^1][2][j], (j > 1 ? dp[ii^1][3][j-1] : 0));
      dp[ii][3][j] = add((j > 1 ? dp[ii^1][0][j-1] : 0), dp[ii^1][1][j], dp[ii^1][2][j], dp[ii^1][3][j]);
    }
  }
  printf("%d\n", add(dp[n&1][0][k], dp[n&1][1][k], dp[n&1][2][k], dp[n&1][3][k]));
  return 0;
}
