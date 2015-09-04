#include <algorithm>
#include <cstring>
#include <cstdio>
#define MAXN 205
#define MAXK 32

using namespace std;

int n, k;
int v[MAXN];
int dp[MAXN][MAXK];
int diff[MAXN][MAXN];
int post_fix[MAXN];
int pre_fix[MAXN];

void init() {
  for(int i = 1; i <= n; i++) {
    pre_fix[i] = 0;
    for(int j = 1; j < i; j++) {
      pre_fix[i] += v[i] - v[j];
    }
  }
  for(int i = n; i >= 1; i--) {
    post_fix[i] = 0;
    for(int j = i + 1; j <= n; j++) {
      post_fix[i] += v[j] - v[i];
    }
  }
  for(int i = 1; i <= n; i++) {
    for(int j = i+1; j <= n; j++) {
      int ans = 0;
      for(int k = i+1; k < j; k++) {
	ans += min(v[k] - v[i], v[j] - v[k]);
      }
      diff[i][j] = ans;
    }
  }
}

int main() {
  int kase = 1;
  while(~scanf("%d%d", &n, &k) && (n || k)) {
    for(int i = 1; i <= n; i++)
      scanf("%d", &v[i]);
    init();
    memset(dp, -1, sizeof dp);
    for(int j = 1; j <= k; j++) {
      for(int i = j; i <= n; i++) {
	if(j == 1) {
	  dp[i][j] = pre_fix[i];
	  continue;
	}
	for(int m = j - 1; m < i; m++) {
	  if(dp[i][j] == -1)
	    dp[i][j] = dp[m][j-1] + diff[m][i];
	  else
	    dp[i][j] = min(dp[i][j], dp[m][j-1] + diff[m][i]);
	}
      }
    }
    int ans = dp[k][k] + post_fix[k];
    for(int i = k+1; i <= n; i++)
      ans = min(ans, dp[i][k] + post_fix[i]);
    printf("Chain %d\n", kase++);
    printf("Total distance sum = %d\n\n", ans);
  }
  return 0;
}
