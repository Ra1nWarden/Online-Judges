#include <algorithm>
#include <cstdio>
#define MAXN 105
#define INF 2000000000

using namespace std;

int cv[MAXN];
int pv[MAXN];
int dp[MAXN];
int prefix[MAXN];
int n;

int main() {
  int tc;
  scanf("%d", &tc);
  while(tc--) {
    scanf("%d", &n);
    prefix[0] = 0;
    for(int i = 1; i <= n; i++) {
      scanf("%d%d", &cv[i], &pv[i]);
      prefix[i] = prefix[i-1] + cv[i];
      dp[i] = (10 + prefix[i]) * pv[i];
    }
    for(int i = 1; i <= n; i++) {
      for(int j = 1; j < i; j++) {
	dp[i] = min(dp[i], dp[j] + (prefix[i] - prefix[j] + 10) * pv[i]);
      }
    }
    printf("%d\n", dp[n]);
  }
  return 0;
}
