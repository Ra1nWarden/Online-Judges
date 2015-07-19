#include <cstdio>
#include <cstring>
#include <algorithm>
#define MAXN 1005

using namespace std;

long long dp[MAXN];
int v[MAXN];

int main() {
  int n;
  while(scanf("%d", &n) != EOF && n) {
    for(int i = 0; i < n; i++)
      scanf("%d", &v[i]);
    memset(dp, -1, sizeof dp);
    dp[0] = (long long) v[0];
    long long ans = dp[0];
    for(int i = 1; i < n; i++) {
      dp[i] = (long long) v[i];
      for(int j = 0; j < i; j++) {
	if(v[i] > v[j])
	  dp[i] = max(dp[i], dp[j] + v[i]);
      }
      ans = max(ans, dp[i]);
    }
    printf("%I64d\n", ans);
  }
  return 0;
}
