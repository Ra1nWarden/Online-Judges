#include <cstdio>

using namespace std;

const int maxn = 1000000;
long long dp[maxn+5];
long long s[maxn+5];

int main() {
  s[0] = 0;
  for(int i = 1; i <= maxn; i++) {
    s[i] = s[i-1] + i;
  }
  dp[0] = 0;
  for(int i = 1; i <= maxn; i++) {
    dp[i] = dp[i-1];
    dp[i] += s[i];
    dp[i] += s[i/2] * 2;
    if(i % 2 == 0) {
      dp[i] -= i / 2;
    }
  }
  int tc;
  scanf("%d", &tc);
  while(tc--) {
    int x;
    scanf("%d", &x);
    printf("%lld\n", dp[x]);
  }
  return 0;
}
