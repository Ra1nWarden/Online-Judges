#include <cstdio>
#include <algorithm>
#define MAXN 105
#define INF 2000000000

using namespace std;

int n;
int v[MAXN][MAXN];
int dp[MAXN];

int main() {
  while(scanf("%d", &n) != EOF) {
    for(int i = 0; i < n; i++) {
      for(int j = 0; j < n; j++) {
	scanf("%d", &v[i][j]);
	if(j > 0)
	  v[i][j] += v[i][j-1];
	if(i > 0)
	  v[i][j] += v[i-1][j];
	if(i > 0 && j > 0)
	  v[i][j] -= v[i-1][j-1];
      }
    }
    int ans = -INF;
    for(int k = 1; k <= n; k++) {
      for(int i = 0; i < n; i++) {
	for(int j = k-1; j < n; j++) {
	  int sum = v[i][j];
	  if(j - k > -1)
	    sum -= v[i][j-k];
	  if(i == 0) {
	    dp[j] = sum;
	  } else {
	    int sumcpy = sum;
	    sum -= dp[j];
	    dp[j] = min(dp[j], sumcpy);
	  }
	  ans = max(ans, sum);
	}
      }
    }
    printf("%d\n", ans);
  }
  return 0;
}
