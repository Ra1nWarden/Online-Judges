#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int maxk = 1000;
const int maxm = 50;

int dp[maxk+5];

int main() {
  int tc;
  scanf("%d", &tc);
  while(tc--) {
    int k, m;
    scanf("%d%d", &k, &m);
    memset(dp, -1, sizeof dp);
    dp[0] = 0;
    int a, b;
    while(m--) {
      scanf("%d%d", &a, &b);
      for(int i = k; i >= a; i--) {
	if(dp[i-a] == -1)
	  continue;
	dp[i] = max(dp[i], dp[i-a] + b);
      }
    }
    int ans = 0;
    for(int i = 0; i <= k; i++)
      ans = max(ans, dp[i]);
    printf("Hey stupid robber, you can get %d.\n", ans);
  }
  return 0;
}
