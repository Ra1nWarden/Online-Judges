#include <cstdio>
#include <cstring>

using namespace std;

const int maxn = 1000;
int mat[maxn+1][maxn+1];
int dp[maxn+1][maxn+1][2];
int n, m;

int main() {
  while(scanf("%d%d", &n, &m) != EOF) {
    memset(dp, -1, sizeof dp);
    for(int i = 0; i < n; i++) {
      for(int j = 0; j < m; j++) {
	scanf("%d", &mat[i][j]);
      }
    }
    for(int i = 0; i < n; i++) {
      for(int j = 0; j < m; j++) {
	if(i == 0 && j == 0) {
	  dp[i][j][0] = -1;
	  dp[i][j][1] = 0;
	  continue;
	}
	if(i > 0) {
	  if(dp[i-1][j][1] > -1) {
	    int prod = dp[i-1][j][1] + mat[i-1][j] * mat[i][j];
	    if(dp[i][j][0] == -1 || prod < dp[i][j][0])
	      dp[i][j][0] = prod;
	  }
	  if(dp[i-1][j][0] > -1) {
	    int prod = dp[i-1][j][0];
	    if(dp[i][j][1] == -1 || prod < dp[i][j][1])
	      dp[i][j][1] = prod;
	  }
	}
	if(j > 0) {
	  if(dp[i][j-1][1] > -1) {
	    int prod = dp[i][j-1][1] + mat[i][j-1] * mat[i][j];
	    if(dp[i][j][0] == -1 || prod < dp[i][j][0])
	      dp[i][j][0] = prod;
	  }
	  if(dp[i][j-1][0] > -1) {
	    int prod = dp[i][j-1][0];
	    if(dp[i][j][1] == -1 || prod < dp[i][j][1])
	      dp[i][j][1] = prod;
	  }
	}
      }
    }
    printf("%d\n", dp[n-1][m-1][0]);
  }
  return 0;
}
