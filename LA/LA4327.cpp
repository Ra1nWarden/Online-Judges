#include <cstdio>
#include <cstring>
#include <algorithm>
#define MAXN 110
#define MAXM 10010

using namespace std;

int n, m, time;
int v[MAXN][MAXM];
int t[MAXN][MAXM];
int dp[MAXN][MAXM];

int main() {
  while(scanf("%d %d %d", &n, &m, &time) != EOF && (n || m || time)) {
    memset(v, 0, sizeof v);
    memset(t, 0, sizeof t);
    for(int i = 1; i <= n + 1; i++) {
      for(int j = 1; j <= m; j++) {
	scanf("%d", &v[i][j]);
	v[i][j] += v[i][j-1];
      }
    }
    for(int i = 1; i <= n + 1; i++) {
      for(int j = 1; j <= m; j++) {
	scanf("%d", &t[i][j]);
	t[i][j] += t[i][j-1];
      }
    }
    memset(dp, 0, sizeof dp);
    int ans = 0;
    for(int i = 0; i <= n + 1; i++) {
      for(int j = 0; j <= m; j++) {
	for(int k = j; k <= m; k++) {
	  if(t[i][k] - t[i][j] > time)
	    break;
	  dp[i][j] = max(dp[i][j], v[i][k] - v[i][j] + (i == 0 ? 0 : dp[i-1][k]));
	  dp[i][k] = max(dp[i][k], v[i][k] - v[i][j] + (i == 0 ? 0 : dp[i-1][k]));
	}	
	if(i == n + 1) {
	  ans = max(ans, dp[i][j]);
	}
      }
    }
    printf("%d\n", ans);
  } 
  return 0;
}
