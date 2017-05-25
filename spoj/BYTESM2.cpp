#include <cstdio>
#include <algorithm>

using namespace std;

const int maxn = 100;
int v[maxn+5][maxn+5];
int dp[maxn+5][maxn+5];
int h, w;

int main() {
  int tc;
  scanf("%d", &tc);
  while(tc--) {
    scanf("%d%d", &h, &w);
    for(int i = 0; i < h; i++) {
      for(int j = 0; j < w; j++) {
	scanf("%d", &v[i][j]);
      }
    }
    for(int j = 0; j < w; j++) {
      dp[0][j] = v[0][j];
    }
    for(int i = 1; i < h; i++) {
      for(int j = 0; j < w; j++) {
	dp[i][j] = dp[i-1][j] + v[i][j];
	if(j > 0)
	  dp[i][j] = max(dp[i][j], dp[i-1][j-1] + v[i][j]);
	if(j < w - 1)
	  dp[i][j] = max(dp[i][j], dp[i-1][j+1] + v[i][j]);
      }
    }
    int ans = 0;
    for(int j = 0; j < w; j++) {
      ans = max(ans, dp[h-1][j]);
    }
    printf("%d\n", ans);
  }
  return 0;
}
