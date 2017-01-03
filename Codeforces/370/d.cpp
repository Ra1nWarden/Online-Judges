#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int mod = 1000000007;
const int offset = 200100;
const int maxn = offset * 2;
int dp[2][maxn+5];
int pre[maxn+5];
int a, b, k, t;

int main() {
  scanf("%d %d %d %d", &a, &b, &k, &t);
  int mindiff = a - b - 2 * k * t + offset;
  int maxdiff = a - b + 2 * k * t + offset;
  memset(dp, 0, sizeof dp);
  dp[0][a-b+offset] = 1;
  for(int ii = 1; ii <= t; ii++) {
    int i = ii & 1;
    int cur = 0;
    memset(pre, 0, sizeof pre);
    for(int j = mindiff; j <= maxdiff; j++) {
      cur = ((long long) cur + dp[i^1][j]) % mod;
      pre[j] = cur;
    }
    int window = 0;
    int mult = 2 * k + 1;
    for(int j = a - b - 2 * k * ii + offset; j <= a - b - 2 * k * ii + 2 * k + offset; j++) {
      window = ((long long) window + (mult * 1LL * dp[i^1][j]) % mod) % mod;
      mult--;
    }
    for(int j = a - b - 2 * k * ii + offset; j <= a - b + 2 * k * ii + offset; j++) {
      dp[i][j] = window;
      window = ((long long) window + pre[min(j + 2 * k + 1, maxdiff)] - pre[j]) % mod;
      window = ((long long) window - pre[j] + pre[max(mindiff - 1, j - 2 * k - 1)] + mod) % mod;
    }
  }
  int ans = 0;
  int i = t & 1;
  for(int j = 1 + offset; j <= a - b + 2 * k * t + offset; j++) {
    ans = ((long long) ans + dp[i][j]) % mod;
  }
  printf("%d\n", ans);
  return 0;
}
