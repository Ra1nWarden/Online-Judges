#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int maxn = 1000;
const int maxc = 10000;
int n, W, B, X;
int cv[maxn+5];
int cvs[maxn+5];
int cost[maxn+5];
long long dp[maxn+5][maxc+5];

int main() {
  scanf("%d%d%d%d", &n, &W, &B, &X);
  for(int i = 0; i < n; i++)
    scanf("%d", &cv[i]);
  for(int i = 0; i < n; i++)
    scanf("%d", &cost[i]);
  int pre = 0;
  for(int i = 0; i < n; i++) {
    pre += cv[i];
    cvs[i] = pre;
  }

  memset(dp, -1, sizeof dp);

  int ans = 0;
  
  dp[0][0] = W;

  for(int s = 1; s <= cv[0] && s * 1LL * cost[0] <= W; s++) {
    dp[0][s] = W - s * 1LL * cost[0];
    ans = max(ans, s);
  }

  for(int i = 1; i < n; i++) {
    for(int s = 0; s <= cvs[i]; s++) {
      for(int ss = 0; ss <= min(cv[i], s); ss++) {
	if(dp[i-1][s-ss] == -1)
	  continue;
	long long val = min(dp[i-1][s-ss] + X, B * 1LL * (s - ss) + W);
	if(val >= ss * 1LL * cost[i]) {
	  dp[i][s] = max(dp[i][s], val - ss * 1LL * cost[i]);
	}
      }
      if(dp[i][s] != -1) {
	ans = max(ans, s);
      }
    }
  }
  printf("%d\n", ans);
  return 0;
}
