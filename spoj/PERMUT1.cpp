#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int maxn = 12;
const int maxk = 98;
int dp[maxn+5][maxk+5];

void init() {
  memset(dp, 0, sizeof dp);
  for(int n = 1; n <= maxn; n++) {
    for(int k = 0; k <= min(maxk, n * (n - 1) / 2); k++) {
      if(k == 0) {
	dp[n][k] = 1;
	continue;
      }
      for(int i = 0; i <= min(k, n - 1); i++) {
	dp[n][k] += dp[n-1][k-i];
      }
    }
  }
}

int main() {
  init();
  int tc;
  scanf("%d", &tc);
  while(tc--) {
    int n, k;
    scanf("%d %d", &n, &k);
    printf("%d\n", dp[n][k]);
  }
  return 0;
}
