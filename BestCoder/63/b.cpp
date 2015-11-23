#include <cstdio>
#include <cstring>

using namespace std;

const int maxn = 100;
int v[maxn+5];
int n;
int dp[maxn+5][maxn+5];
int k;

int main() {
  while(scanf("%d%d", &n, &k) != EOF) {
    for(int i = 1; i <= n; i++) {
      scanf("%d", &v[i]);
    }
    memset(dp, 0, sizeof dp);
    for(int len = 1; len <= k; len++) {
      if(len == 1) {
	for(int i = 1; i <= n; i++) {
	  dp[i][len] = 1;
	}
      } else {
	for(int i = len - 1; i <= n; i++) {
	  if(dp[i][len-1] == 0)
	    continue;
	  for(int j = i + 1; j <= n; j++) {
	    if(v[j] > v[i]) {
	      dp[j][len] += dp[i][len-1];
	    }
	  }
	}
      }
    }
    int ans = 0;
    for(int i = 1; i <= n; i++)
      ans += dp[i][k];
    printf("%d\n", ans);
  }
  return 0;
}
