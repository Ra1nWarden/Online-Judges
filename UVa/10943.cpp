#include <cstdio>
#include <cstring>

using namespace std;

const int maxn = 100;
const int mod = 1000000;
int dp[maxn+1][maxn+1];

int f(int n, int k) {
  if(dp[n][k] != -1)
    return dp[n][k];
  if(k == 1)
    return dp[n][k] = 1;
  int ans = 0;
  for(int i = 0; i <= n; i++) {
    ans += f(n - i, k - 1);
    ans %= mod;
  }
  return dp[n][k] = ans;
}

int main() {
  memset(dp, -1, sizeof dp);
  int n, k;
  while(scanf("%d%d", &n, &k) != EOF && (n || k)) {
    printf("%d\n", f(n, k));
  }
  return 0;
}
