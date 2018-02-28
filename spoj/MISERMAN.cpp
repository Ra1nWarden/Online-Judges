#include <cstdio>
#include <algorithm>

using namespace std;

int n, m;
const int maxn = 100;
int dp[maxn+5][2];

int main() {
  scanf("%d %d", &n, &m);
  int c;
  for(int i = 0; i < n; i++) {
    int k = i & 1;
    for(int j = 0; j < m; j++) {
      scanf("%d", &c);
      if(i == 0) {
	dp[j][k] = c;
	continue;
      }
      dp[j][k] = dp[j][k^1] + c;
      if(j > 0)
	dp[j][k] = min(dp[j][k], dp[j-1][k^1] + c);
      if(j < m - 1)
	dp[j][k] = min(dp[j][k], dp[j+1][k^1] + c);
    }
  }
  int ans = 2000000000;
  for(int j = 0; j < m; j++) {
    ans = min(ans, dp[j][(n-1)&1]);
  }
  printf("%d\n", ans);
  return 0;
}
