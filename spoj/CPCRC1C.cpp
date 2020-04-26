#include <cstdio>
#include <sstream>

using namespace std;

long long dp[10][2];

long long f(long long n) {
  long long ans = 0;
  if(n < 10LL) {
    for(long long i = 1LL; i <= n; i++)
      ans += i;
    return ans;
  }

  long long mod = 1LL;
  long long len = 0;
  while(mod <= n) {
    mod *= 10;
    len++;
  }
  mod /= 10;
  len--;

  long long dig = n / mod;

  //printf("dig is %lld len is %lld mod is %lld\n", dig, len, mod);
  ans = dp[len][1] * dig + f(dig-1) * mod + dig * ((n % mod) + 1) + f(n % mod);
  //printf("f(%lld) = %lld\n", n, ans);
  return ans;
}

void init() {
  dp[0][0] = 0;
  dp[0][1] = 0;
  long long mult = 1LL;
  for(int i = 1; i < 10; i++) {
    dp[i][0] = dp[i-1][1] * 9LL + mult * 45;
    mult *= 10;
    dp[i][1] = dp[i-1][1] + dp[i][0];
    //printf("dp[%d]=%lld %lld\n", i, dp[i][0], dp[i][1]);
  }
}

int main() {
  init();
  long long a, b;
  while(scanf("%lld %lld", &a, &b) != EOF) {
    if(a == -1LL && b == -1LL)
      break;
    if(a == 0)
      a = 1LL;
    printf("%lld\n", f(b) - f(a-1));
  }
  return 0;
}
