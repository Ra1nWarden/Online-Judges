#include <cstdio>
#include <algorithm>

using namespace std;

const int maxn = 100000;
int v[maxn+5];
long long dp[maxn+5];
int n;

int main() {
  scanf("%d", &n);
  for(int i = 1; i <= n; i++)
    scanf("%d", &v[i]);
  dp[0] = 0;
  for(int i = 1; i <= n; i++) {
    int t = v[i];
    dp[i] = dp[i-1] + 20;
    int ai = lower_bound(v+1, v+n+1, max(0, t - 89)) - v - 1;
    dp[i] = min(dp[i], dp[ai] + 50);
    ai = lower_bound(v+1, v+n+1, max(0, t - 1439)) - v - 1;
    dp[i] = min(dp[i], dp[ai] + 120);
    printf("%I64d\n", dp[i] - dp[i-1]);
  }
  return 0;
}
