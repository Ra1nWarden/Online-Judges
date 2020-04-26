#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int maxt = 21;
const int maxa = 79;
int dp[maxt+5][maxa+5][2];
int t, a;

int main() {
  int tc;
  scanf("%d", &tc);
  while(tc--) {
    scanf("%d%d", &t, &a);
    memset(dp, -1, sizeof dp);
    int n;
    scanf("%d", &n);
    dp[0][0][0] = 0;
    int idx = 1;
    while(n--) {
      int tt, aa, w;
      scanf("%d%d%d", &tt, &aa, &w);
      // copy
      for(int i = 0; i <= t; i++)
	for(int j = 0; j <= a; j++)
	  dp[i][j][idx] = dp[i][j][idx^1];
      // update
      for(int i = 0; i <= t; i++) {
	for(int j = 0; j <= a; j++) {
	  if(dp[i][j][idx^1] == -1)
	    continue;
	  int updated = dp[i][j][idx^1] + w;
	  int ii = min(t, i + tt);
	  int jj = min(a, j + aa);
	  if(dp[ii][jj][idx] == -1)
	    dp[ii][jj][idx] = updated;
	  else
	    dp[ii][jj][idx] = min(dp[ii][jj][idx], updated);
	}
      }
      idx ^= 1;
    }
    printf("%d\n", dp[t][a][idx^1]);
  }
  return 0;
}
