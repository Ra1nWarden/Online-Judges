#include <cstdio>
#include <algorithm>

using namespace std;

const int maxn = 10000;
long long v[maxn+5];
long long dp[maxn+5][2];
int n;

int main() {
  int tc;
  scanf("%d", &tc);
  for(int kase = 1; kase <= tc; kase++) {
    scanf("%d", &n);
    if(n == 0) {
      printf("Case %d: 0\n", kase);
      continue;
    }
    for(int i = 0; i < n; i++)
      scanf("%lld", &v[i]);
    dp[0][0] = 0;
    dp[0][1] = v[0];
    for(int i = 1; i < n; i++) {
      dp[i][0] = max(dp[i-1][0], dp[i-1][1]);
      dp[i][1] = dp[i-1][0] + v[i];
    }
    printf("Case %d: %lld\n", kase, max(dp[n-1][0], dp[n-1][1]));
  }
  return 0;
}
