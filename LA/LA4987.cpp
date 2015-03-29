#include <cstdio>
#include <algorithm>
#define MAXN 4005
#define INF 20000000000000LL

using namespace std;
int teams[MAXN], shelters[MAXN];
int n, m;
long long dp[MAXN][MAXN][2];
int v[MAXN];

int main() {
  while(scanf("%d", &n) != EOF) {
    for(int i = 0; i < n; i++)
      scanf("%d", &teams[i]);
    scanf("%d", &m);
    for(int i = 0; i < m; i++)
      scanf("%d", &shelters[i]);

    for(int i = 1; i <= n; i++)
      dp[i][0][0] = dp[i][0][1] = INF;

    for(int j = 1; j <= m; j++)
      dp[0][j][0] = dp[0][j][1] = INF;
    
    dp[0][1][1] = dp[0][0][0] = dp[0][0][1] = 0;
    
    for(int i = 1; i <= n; i++) {
      for(int j = 1; j <= m; j++) {
    	if(m - j > n - i) {
    	  dp[i][j][0] = dp[i][j][1] = INF;
    	  continue;
    	}
    	dp[i][j][0] = min(dp[i-1][j-1][0], dp[i-1][j][1] ) + abs(teams[i-1] - shelters[j-1]);
    	dp[i][j][1] = min(dp[i-1][j][1] + abs(teams[i-1] - shelters[j-1]), dp[i][j-1][0]);
    	//printf("teams[i-1] = %d shelters[j-1] = %d   abs is %d    dp[%d][%d][0] = %d     dp[%d][%d][1] = %d\n", teams[i-1], shelters[j-1], abs(teams[i-1] - shelters[j-1]), i, j, dp[i][j][0], i, j, dp[i][j][1]);
      }
    }
    printf("%lld\n", dp[n][m][0]);
    int i = n -1;
    int j = m;
    v[i] = j;
    i--;
    for(; i > 0; i--) {
      if(j > 0 && dp[i+1][j-1][1] == dp[i+1][j][1]) {
    	j--;
      }
      v[i] = j;
    }
    v[0] = 1;

    for(int i = 0; i < n; i++) {
      if(i != 0)
	printf(" ");
      printf("%d", v[i]);
    }
    printf("\n");
  }
  return 0;
}
