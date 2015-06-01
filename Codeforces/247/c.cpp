#include <cstdio>
#include <algorithm>
#include <cstring>
#define MOD 1000000007
#define MAXN 101

using namespace std;

int dp[MAXN][2];
int n, k, d;

int f(int sum, int flag) {
  if(dp[sum][flag] != -1)
    return dp[sum][flag];
  if(sum == 0) {
    return dp[sum][flag] = flag ? 0 : 1;
  }
  if(flag) {
    if(sum < d) {
      return dp[sum][flag] = 0;
    }
    int ans = 0;
    for(int i = 1; i <= min(sum, k); i++) {
      if(i >= d) {
	ans = (ans + f(sum - i, 0)) % MOD;
      } else {
	ans = (ans + f(sum - i, 1)) % MOD;
      }
    }
    return dp[sum][flag] = ans;
  } else {
    int ans = 0;
    for(int i = 1; i <= min(sum, k); i++) {
      ans = (ans + f(sum - i, 0)) % MOD;
    }
    return dp[sum][flag] = ans;
  }
}

int main() {
  scanf("%d %d %d", &n, &k, &d);
  memset(dp, -1, sizeof dp);
  printf("%d\n", f(n, 1));
  return 0;
}
