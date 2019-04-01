#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int maxn = 100;
const int maxk = 100;
int dp[maxk+5][maxn+5];
int n, k;

int find_min(int cur, int next) {
  if(cur == -1)
    return next;
  return min(cur, next);
}

int main() {
  int tc;
  scanf("%d", &tc);
  while(tc--) {
    scanf("%d %d", &n, &k);
    memset(dp, -1, sizeof dp);
    int p;
    dp[0][0] = 0;
    for(int i = 1; i <= k; i++) {
      scanf("%d", &p);
      if(p == -1)
	continue;
      for(int nn = 0; nn < n; nn++) {
	for(int kk = 0; kk+i <= k; kk++) {
	  if(dp[kk][nn] == -1)
	    continue;
	  dp[kk+i][nn+1] = find_min(dp[kk+i][nn+1], dp[kk][nn]+p);
	}
      }
    }
    int ans = -1;
    for(int i = 1; i <= n; i++) {
      if(dp[k][i] == -1)
	continue;
      ans = find_min(ans, dp[k][i]);
    }
    printf("%d\n", ans);
  }
  return 0;
}
