#include <cstdio>
#include <algorithm>
#define MAXN 32

using namespace std;

double dp[MAXN];
int n;
double t;

int main() {
  while(scanf("%d %lf\n", &n, &t) != EOF && (n || t)) {
    dp[n] = (1 << n);
    for(int i = n-1; i > -1; i--) {
      double p0 = max(t, (1 << i) / dp[i+1]);
      double p1 = (p0 - t) / (1 - t);
      dp[i] = (1 << i) * p1 + (1 + p0) / 2 * dp[i+1] * (1 - p1);
    }
    printf("%.3f\n", dp[0]);
  }
  return 0;
}
