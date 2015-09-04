#include <cstring>
#include <cstdio>
#include <algorithm>
#define MAXN 1010
#define MAXM 25

using namespace std;

int n, m;
int v[MAXN];
int mv[MAXM];
int dp[MAXN][MAXM];
int prefix[MAXN];
int m_prefix[MAXM];

int main() {
  while(scanf("%d", &n) != EOF && n) {
    scanf("%d", &m);
    m_prefix[0] = 0;
    for(int i = 1; i <= m; i++) {
      scanf("%d", &mv[i]);
      m_prefix[i] = m_prefix[i-1] + mv[i];
    }
    prefix[0] = 0;
    for(int i = 1; i <= n; i++) {
      scanf("%d", &v[i]);
      prefix[i] = prefix[i-1] + v[i];
    }
    memset(dp, 0, sizeof dp);
    for(int j = 1; j <= m; j++) {
      for(int i = m_prefix[j]; i <= n; i++) {
	dp[i][j] = max(dp[i-1][j], dp[i-mv[j]][j-1] + prefix[i] - prefix[i-mv[j]]);
	//printf("%d vs %d dp[%d][%d]=%d\n", dp[i-1][j],  dp[i-mv[j]][j-1] + prefix[i] - prefix[i-mv[j]], i, j, dp[i][j]);
      }
    }
    printf("%d\n", dp[n][m]);
  }
  return 0;
}
