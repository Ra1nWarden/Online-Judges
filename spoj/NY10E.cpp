#include <cstdio>

using namespace std;

const int maxn = 64;
long long dp[10][maxn+5];

void init() {
  dp[9][1] = 1LL;
  for(int d = 8; d >= 0; d--)
    dp[d][1] = dp[d+1][1] + 1;
  for(int len = 2; len <= maxn; len++) {
    for(int d = 9; d >= 0; d--) {
      dp[d][len] = dp[d][len-1];
      if(d < 9)
	dp[d][len] += dp[d+1][len];
    }
  }
}

int main() {
  init();
  int tc;
  scanf("%d", &tc);
  while(tc--) {
    int kase, len;
    scanf("%d %d", &kase, &len);
    printf("%d %lld\n", kase, dp[0][len]);
  }
  return 0;
}
