#include <cstdio>
#include <cstring>

using namespace std;

const int maxn = 21;
typedef unsigned long long ULL;
ULL dp[maxn+1][maxn+1];

void init() {
  memset(dp, 0, sizeof dp);
  dp[1][0] = 1;
  for(int i = 2; i <= maxn; i++) {
    for(int j = 0; j < i; j++) {
      dp[i][j] = dp[i-1][j];
      if(j)
	dp[i][j] += dp[i-1][j-1] * (i - 1);
    }
  }
}

int main() {
  init();
  int n, k;
  while(scanf("%d%d", &n, &k) != EOF && (n || k)) {
    printf("%llu\n", dp[n][k]);
  }
  return 0;
}
