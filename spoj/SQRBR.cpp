#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int maxn = 19;
bool v[maxn * 2 + 5];
int dp[maxn * 2 + 5][maxn + 5];
int n, k;

int main() {
  int tc;
  scanf("%d", &tc);
  while(tc--) {
    scanf("%d%d", &n, &k);
    memset(v, false, sizeof v);
    while(k--) {
      int idx;
      scanf("%d", &idx);
      v[idx] = true;
    }
    memset(dp, 0, sizeof dp);
    dp[0][0] = 1;
    for(int i = 1; i <= 2 * n; i++) {
      for(int j = 0; j <= min(i, n); j++) {
	if(v[i]) {
	  dp[i][j] = j > 0 ? dp[i-1][j-1] : 0;
	} else {
	  dp[i][j] = dp[i-1][j+1];
	  if(j)
	    dp[i][j] += dp[i-1][j-1];
	}
      }
    }
    printf("%d\n", dp[2*n][0]);
  }
  return 0;
}
