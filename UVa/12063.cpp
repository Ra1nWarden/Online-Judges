#include <cstdio>
#include <cstring>
#define MAXN 70
#define MAXK 105

using namespace std;

int n, k;
long long dp[MAXN][MAXN][MAXK];
int remainder[2*MAXN];

void init_remainder() {
  remainder[0] = 1;
  for(int i = 1; i < n; i++)
    remainder[i] = (remainder[i-1] * 2) % k;
}

long long f(int x, int y, int r) {
  if(dp[x][y][r] != -1)
    return dp[x][y][r];
  if(x == 0)
    return dp[x][y][r] = (y == 0 && r == 0) ? 1 : 0;
  long long ans = 0;
  if(y > 0)
    ans += f(x-1, y-1, (r+k-remainder[x-1]) % k);
  ans += f(x-1, y, r);
  return dp[x][y][r] = ans;
}

int main() {
  int tc;
  scanf("%d", &tc);
  for(int kase = 1; kase <= tc; kase++) {
    scanf("%d %d", &n, &k);
    if(k == 0 || n % 2 == 1) {
      printf("Case %d: 0\n", kase);
      continue;
    }
    init_remainder();
    memset(dp, -1, sizeof dp);
    printf("Case %d: %lld\n", kase, f(n-1, n/2-1, k - remainder[n-1]));
  }
  return 0;
}
