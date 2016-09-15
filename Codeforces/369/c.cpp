#include <cstdio>
#include <algorithm>

using namespace std;

typedef long long LL;
const int maxn = 100;
LL dp[maxn+5][maxn+5][maxn+5];
LL mat[maxn+5][maxn+5];
int n, m, k;
LL v[maxn+5];
const LL inf = 1000000000000000000LL;

int main() {
  scanf("%d%d%d", &n, &m, &k);
  for(int i = 1; i <= n; i++) {
    scanf("%I64d", &v[i]);
  }
  for(int i = 1; i <= n; i++) {
    for(int j = 1; j <= m; j++) {
      scanf("%I64d", &mat[i][j]);
    }
  }
  for(int i = 0; i <= n; i++) {
    for(int j = 0; j <= m; j++) {
      for(int l = 0; l <= k; l++) {
	dp[i][j][l] = inf;
      }
    }
  }
  // first i items with l beauty and j as the last color

  if(v[1] == 0) {
    for(int j = 1; j <= m; j++) {
      dp[1][j][1] = mat[1][j];
    }
  } else {
    dp[1][v[1]][1] = 0;
  }
  for(int i = 2; i <= n; i++) {
    if(v[i] != 0) {
      for(int j = 1; j <= m; j++) {
	for(int l = 1; l <= k; l++) {
	  if(j == v[i]) {
	    dp[i][v[i]][l] = min(dp[i][v[i]][l], dp[i-1][j][l]);
	  } else {
	    dp[i][v[i]][l+1] = min(dp[i][v[i]][l+1], dp[i-1][j][l]);
	    //printf("dp[%d][%d][%d]=%I64d\n", i, v[i], l+1, dp[i][v[i]][l+1]);
	  }
	}
      }
    } else {
      for(int j = 1; j <= m; j++) {
	for(int jj = 1; jj <= m; jj++) {
	  for(int l = 1; l <= k; l++) {
	    if(j == jj) {
	      dp[i][j][l] = min(dp[i][j][l], dp[i-1][jj][l] + mat[i][j]);
	    } else {
	      dp[i][j][l+1] = min(dp[i][j][l+1], dp[i-1][jj][l] + mat[i][j]);
	    }
	  }
	}
      }
    }
  }
  LL ans = inf;
  for(int j = 1; j <= m; j++) {
    //printf("dp[%d][%d][%d]=%I64d\n", n, j, k, dp[n][j][k]);
    ans = min(ans, dp[n][j][k]);
  }
  if(ans == inf)
    ans = -1;
  printf("%I64d\n", ans);
  return 0;
}
