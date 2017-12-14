#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int maxn = 2000;
int dp[maxn][maxn][3];

int f(int h, int a, int s) {
  if(h <= 0 || a <= 0)
    return 0;
  if(dp[h][a][s] != -1)
    return dp[h][a][s];
  int ans = 0;
  if(s != 0) {
    ans = max(ans, f(h + 3, a + 2, 0) + 1);
  }
  if(s != 1) {
    ans = max(ans, f(h - 5, a - 10, 1) + 1);

  }
  if(s != 2) {
    ans = max(ans, f(h - 20, a + 5, 2) + 1);
  }
  return dp[h][a][s] = ans;
}

int main() {
  memset(dp, -1, sizeof dp);
  int tc;
  scanf("%d", &tc);
  while(tc--) {
    int h, a;
    scanf("%d%d", &h, &a);
    printf("%d\n", max(f(h, a, 0), max(f(h, a, 1), f(h, a, 2))) - 1);
  }
  return 0;
}
