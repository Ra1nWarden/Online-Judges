#include <cstdio>
#include <cstring>
#include <algorithm>
#define MAXN 5005

using namespace std;

long long prefix_sum[MAXN];
long long dp[MAXN][MAXN];

int main() {
  int n, m, k;
  scanf("%d %d %d", &n, &m, &k);
  prefix_sum[0] = 0;
  for(int i = 1; i <= n; i++) {
    scanf("%I64d", &prefix_sum[i]);
    prefix_sum[i] += prefix_sum[i-1];
  }
  
  for(int i = 0; i <= n; i++) {
    for(int j = 0; j <= k; j++) {
      dp[i][j] = -1;
    }
  }

  dp[0][0] = 0;
  for(int i = 0; i <= n; i++) {
    for(int j = 0; j <= k; j++) {
      if(dp[i][j] != -1) {
	if(i < n)
	  dp[i+1][j] = max(dp[i+1][j], dp[i][j]);
	if(j < k && i + m <= n) {
	  dp[i+m][j+1] = max(dp[i+m][j+1], dp[i][j] + prefix_sum[i+m] - prefix_sum[i]);
	}
      }
    }
  }
  printf("%I64d\n", dp[n][k]);
  return 0;
}
