#include <cstdio>
#include <algorithm>
#include <utility>
#define MAXN 10010

using namespace std;

typedef pair<int, double> App;

double dp[MAXN];
int n, m;
App apps[MAXN];

int main() {
  while(~scanf("%d%d", &n, &m) && (n || m)) {
    for(int i = 1; i <= m; i++) {
      scanf("%d%lf", &apps[i].first, &apps[i].second);
      apps[i].second = 1 - apps[i].second;
    }
    for(int i = 0; i <= n; i++)
      dp[i] = 1;
    for(int i = 1; i <= m; i++) {
      for(int j = n; j >= apps[i].first; j--)
	dp[j] = min(dp[j], dp[j-apps[i].first] * apps[i].second);
    }
    printf("%.1f%%\n", (1 - dp[n])*100);
  }
  return 0;
}
