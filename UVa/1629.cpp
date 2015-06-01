#include <cstdio>
#include <cstring>
#include <algorithm>
#define MAXN 21
#define INF 100000

using namespace std;

bool board[MAXN][MAXN];
int prefix[MAXN][MAXN];
int dp[MAXN][MAXN][MAXN][MAXN];
int n, m, k;

void init_prefix() {
  for(int i = 0; i < n; i++) {
    for(int j = 0; j < m; j++) {
      prefix[i][j] = board[i][j] ? 1 : 0;
      if(i > 0)
	prefix[i][j] += prefix[i-1][j];
      if(j > 0)
	prefix[i][j] += prefix[i][j-1];
      if(i > 0 && j > 0)
	prefix[i][j] -= prefix[i-1][j-1];
      //printf("prefix[%d][%d]=%d\n", i, j, prefix[i][j]);
    }
  }
}

int count(int x1, int y1, int x2, int y2) {
  int ans = prefix[x2][y2];
  if(x1 > 0) {
    ans -= prefix[x1 - 1][y2];
  }
  if(y1 > 0) {
    ans -= prefix[x2][y1 - 1];
  }
  if(x1 > 0 && y1 > 0)
    ans += prefix[x1 - 1][y1 - 1];
  //printf("count (%d, %d) to (%d, %d) is %d\n", x1, y1, x2, y2, ans);
  return ans;
}

int f(int x1, int y1, int x2, int y2) {
  if(dp[x1][y1][x2][y2] != -1)
    return dp[x1][y1][x2][y2];
  if(count(x1, y1, x2, y2) <= 1)
    return dp[x1][y1][x2][y2] = 0;
  int ans = INF;
  for(int i = x1; i < x2; i++) {
    if(count(x1, y1, i, y2) > 0 && count(i+1, y1, x2, y2) > 0) {
      ans = min(ans, f(x1, y1, i, y2) + f(i+1, y1, x2, y2) + y2 - y1 + 1);
    }
  }
  for(int j = y1; j < y2; j++) {
    if(count(x1, y1, x2, j) > 0 && count(x1, j+1, x2, y2) > 0) {
      ans = min(ans, f(x1, y1, x2, j) + f(x1, j+1, x2, y2) + x2 - x1 + 1);
    }
  }
  return dp[x1][y1][x2][y2] = ans;
}

int main() {
  int kase = 1;
  while(scanf("%d %d %d", &n, &m, &k) != EOF) {
    memset(board, false, sizeof board);
    for(int i = 0; i < k; i++) {
      int x, y;
      scanf("%d %d", &x, &y);
      board[x-1][y-1] = true;
    }
    init_prefix();
    memset(dp, -1, sizeof dp);
    printf("Case %d: %d\n", kase++, f(0, 0, n-1, m-1));
  }
  return 0;
}
