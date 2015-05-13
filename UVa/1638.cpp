#include <cstdio>
#define MAXN 22

using namespace std;

long long dp[MAXN][MAXN][MAXN];

int main() {
  dp[1][1][1] = 1;
  dp[1][0][0] = dp[1][0][1] = dp[1][1][0] = 0;
  for(int i = 2; i <= 20; i++) {
    for(int j = 1; j <= i; j++) {
      for(int k = 1; k <= i; k++) {
	if(j + k > i + 1)
	  dp[i][j][k] = 0;
	else
	  dp[i][j][k] = dp[i-1][j-1][k] + dp[i-1][j][k-1] + dp[i-1][j][k] * (i - 2);
      }
    }
  }
  int tc;
  scanf("%d", &tc);
  while(tc--) {
    int n, l, r;
    scanf("%d %d %d", &n, &l, &r);
    printf("%lld\n", dp[n][l][r]);
  }
  return 0;
}
