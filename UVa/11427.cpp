#include <cstdio>
#include <cstring>

using namespace std;

const int maxn = 100;
double dp[maxn+5][maxn+5];
int n;
double p;

int main() {
  int tc;
  scanf("%d", &tc);
  for(int kase = 1; kase <= tc; kase++) {
    int a, b, n;
    scanf("%d/%d %d", &a, &b, &n);
    p = (double) a / b;
    memset(dp, 0, sizeof dp);
    dp[0][0] = 1, dp[0][1] = 0;
    for(int i = 1; i <= n; i++) {
      for(int j = 0; j <= i * a / b; j++) {
	dp[i][j] = dp[i-1][j] * (1 - p);
	if(j)
	  dp[i][j] += dp[i-1][j-1] * p;
      }
    }
    double q = 0;
    for(int i = 0; i <= n * a / b; i++)
      q += dp[n][i];
    printf("Case #%d: %d\n", kase, (int) (1 / q));
  }
  return 0;
}
