#include <cstdio>
#include <algorithm>
#include <cstring>
#define MAXN 55
#define MAXC 180*MAXN+5

using namespace std;

int n;
int v[MAXN];
int dp[MAXN][MAXC];
int dpv[MAXN][MAXC];
int t;

int main() {
  int tc;
  scanf("%d", &tc);
  for(int kase = 1; kase <= tc; kase++) {
    memset(dp, -1, sizeof dp);
    memset(dpv, -1, sizeof dpv);
    scanf("%d %d", &n, &t);
    for(int i = 0; i < n; i++)
      scanf("%d", &v[i]);
    t = min(t, 180 * n + 1);
    for(int j = 0; j <= t; j++) {
      dp[0][j] = 0;
      dpv[0][j] = 0;
    }

    int maxval = 0;
    int ans = 0;
    for(int i = 1; i <= n; i++) {
      for(int j = 1; j <= t; j++) {
	if(v[i-1] < j) {
	  dp[i][j] = max(dp[i-1][j], dp[i-1][j-v[i-1]] + 1);
	  dpv[i][j] = max(dpv[i][j], dpv[i-1][j-v[i-1]] + v[i-1]);
	}
	else {
	  dp[i][j] = dp[i-1][j];
	  dpv[i][j] = dpv[i-1][j];
	}
	if(dpv[i][j] > maxval) {
	  maxval = dpv[i][j];
	  ans = dp[i][j];
	}
      }
    }
    
    printf("Case %d: %d %d\n", kase, ans + 1, maxval + 678);
  }
  return 0;
}
