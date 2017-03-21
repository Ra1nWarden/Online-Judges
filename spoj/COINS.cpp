#include <cstdio>
#include <algorithm>

using namespace std;

const int maxn = 500000000;
long long dp[maxn+5];

void init() {
  dp[0] = 0;
  for(int i = 1; i <= maxn; i++) {
    dp[i] = max((long long) i, dp[i/2] + dp[i/4] + dp[i/3]);
  }
}

int main() {
  init();
  int n;
  while(scanf("%d", &n) != EOF) {
    printf("%lld\n", max((long long) n, dp[n/2] + dp[n/3] + dp[n/4]));
  }
  return 0;
}
