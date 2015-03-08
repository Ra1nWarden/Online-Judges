#include <cstdio>
#include <cstring>
#include <algorithm>
#define MAXN 1005
#define INF 2e9

using namespace std;

int dp[5][5][MAXN];
int n;
int v[MAXN];

int main() {
  while(true) {
    n = 0;
    while(true) {
      scanf("%d", &v[n]);
      if(v[n] == 0)
	break;
      n++;
    }
    if(n == 0)
      break;
    memset(dp, -1, sizeof dp);
    for(int i = 0; i < 5; i++) {
      for(int j = 0; j < 5; j++) {
	if(i != 0 && j != 0)
	  dp[i][j][1] = INF;
	else if(i == 0) {
	  dp[i][j][1] = j == v[0] ? 2 : INF;
	} else {
	  dp[i][j][1] = i == v[0] ? 2 : INF;
	}
      }
    }
    for(int k = 2; k <= n; k++) {
      for(int i = 0; i < 5; i++) {
	for(int j = 0; j < 5; j++) {
	  dp[i][j][k] = INF;
	  if(i != v[k-1] && j != v[k-1])
	    dp[i][j][k] = INF;
	  else if(i == v[k-1]) {
	    for(int ii = 0; ii < 5; ii++) {
	      if(ii == 0) {
		dp[i][j][k] = min(dp[i][j][k], dp[ii][j][k-1] + 2);
	      } else if(ii == i) {
		dp[i][j][k] = min(dp[i][j][k], dp[ii][j][k-1] + 1);
	      }else if(abs(ii - i) == 2) {
		dp[i][j][k] = min(dp[i][j][k], dp[ii][j][k-1] + 4);
	      } else {
		dp[i][j][k] = min(dp[i][j][k], dp[ii][j][k-1] + 3);
	      }
	    }
	  } else {
	    for(int jj = 0; jj < 5; jj++) {
	      if(jj == 0) {
		dp[i][j][k] = min(dp[i][j][k], dp[i][jj][k-1] + 2);
	      } else if(jj == j) {
		dp[i][j][k] = min(dp[i][j][k], dp[i][jj][k-1] + 1);
	      } else if(abs(jj - j) == 2) {
		dp[i][j][k] = min(dp[i][j][k], dp[i][jj][k-1] + 4);
	      } else {
		dp[i][j][k] = min(dp[i][j][k], dp[i][jj][k-1] + 3);
	      }
	    }
	  }
	}
      }
    }
    int res = INF;
    for(int i = 0; i < 5; i++) {
      for(int j = 0; j < 5; j++) {
	if(i != v[n-1] && j != v[n-1])
	  continue;
	res = min(res, dp[i][j][n]);
      }
    }
    printf("%d\n", res);
  }
  return 0;
}
