#include <cstdio>
#include <cstring>
#include <algorithm>
#include <functional>
#define MAXM 31
#define MAXN 101
#define INF 500000

using namespace std;

int n, m;
int v[MAXM];
int dp[MAXM][MAXN][2];
int x;

int f(int i, int j, int k) {
  if(dp[i][j][k] != -1)
    return dp[i][j][k];
  if(i == 0) {
    return j <= 0 ? 0 : INF;
  }
  if(j <= 0)
    return 0;
  if(k == 0)
    return min(f(i-1, j, 0), f(i-1, j, 1));
  else {
    if(v[i-1] < x)
      return dp[i][j][k] = INF;
    else
      return dp[i][j][k] = min(f(i-1, j-(v[i-1]/x), 0), f(i-1, j-(v[i-1]/x), 1)) + v[i-1];
  }
}

bool ok(int avg) {
  int ans = 0;
  for(int i = 0; i < m; i++) {
    ans += v[i] / avg;
  }
  return ans >= n;
}

int main() {
  while(scanf("%d %d", &n, &m) != EOF && (n || m)) {
    int sum = 0;
    for(int i = 0; i < m; i++) {
      scanf("%d", &v[i]);
      sum += v[i];
    }
    sort(v, v+m, greater<int>());
    int left = 0;
    int right = sum / n;
    while(left != right) {
      int mid = ((left + right) >> 1) + 1;
      if(ok(mid))
	left = mid;
      else
	right = mid - 1;
    }
    x = left;
    memset(dp, -1, sizeof dp);
    int y;
    if(x != 0)
      y = min(f(m, n, 0), f(m, n, 1));
    else
      y = 0;
    printf("%d %d\n", x, y);
  }
  return 0;
}
