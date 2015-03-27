#include <cstdio>
#define MAXN 2005

using namespace std;

double dp[MAXN][MAXN];

int main() {
  int n, t;
  double p;
  scanf("%d %lf %d", &n, &p, &t);
  for(int nn = 0; nn < n; nn++)
    dp[nn][0] = 0.0;
  dp[n][0] = 1.0;
  for(int tt = 1; tt <= t; tt++) {
    dp[n][tt] = dp[n][tt-1] * (1 - p);
    for(int nn = n - 1; nn > 0; nn--) {
      dp[nn][tt] = (1 - p) * dp[nn][tt-1] + p * dp[nn+1][tt-1];
    }
    dp[0][tt] = dp[0][tt-1] + p * dp[1][tt-1];
  }
  double res = 0.0;
  for(int nn = 0; nn <= n; nn++) {
    res += (dp[nn][t] * (n - nn));
  }
  printf("%.8f\n", res);
  return 0;
}
