#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int maxn = 2000;
int v[2][maxn+5];
int dp[maxn+5][maxn+5];
int n[2];

void scanline(int i) {
  n[i] = 0;
  while(true) {
    scanf("%d", &v[i][n[i]]);
    if(!v[i][n[i]])
      break;
    n[i]++;
  }
}

int main() {
  int tc;
  scanf("%d", &tc);
  while(tc--) {
    scanline(0);
    int ans = 0;
    while(true) {
      scanline(1);
      if(n[1] == 0)
	break;
      memset(dp, 0, sizeof dp);
      for(int s = 2; s <= n[0] + n[1]; s++) {
	for(int i = max(1, s - n[1]); i <= n[0]; i++) {
	  int j = s - i;
	  dp[i][j] = max(dp[i][j-1], dp[i-1][j]);
	  if(v[0][i-1] == v[1][j-1]) {
	    dp[i][j] = max(dp[i][j], dp[i-1][j-1] + 1);
	  }
	}
      }
      ans = max(ans, dp[n[0]][n[1]]);
    }
    printf("%d\n", ans);
  }
  return 0;
}
