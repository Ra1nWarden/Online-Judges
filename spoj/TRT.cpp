#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int maxn = 2000;
long long v[maxn+5];
long long dp[maxn+5];
int n;

int main() {
  scanf("%d", &n);
  for(int i = 0; i < n; i++)
    scanf("%lld", &v[i]);
  memset(dp, 0, sizeof dp);
  for(int len = 0; len < n; len++) {
    for(int i = 0; i < n - len; i++) {
      dp[i] = max((n - len) * v[i] + dp[i + 1], dp[i] + (n - len) * v[i + len]);
    }
  }
  printf("%lld\n", dp[0]);
  return 0;
}
