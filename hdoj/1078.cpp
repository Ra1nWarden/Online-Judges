#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
#define MAXN 105

using namespace std;

int v[MAXN][MAXN];
int n, k;
int dp[MAXN][MAXN];
int dx[] = {-1, 0, 0, 1};
int dy[] = {0, 1, -1, 0};

typedef pair<int, int> Point;

int main() {
  while(scanf("%d %d", &n, &k) != EOF && n != -1 && k != -1) {
    for(int i = 0; i < n; i++) {
      for(int j = 0; j < n; j++) {
	scanf("%d", &v[i][j]);
      }
    }
    memset(dp, 0, sizeof dp);
    dp[0][0] = v[0][0];
    int ans = v[0][0];
    queue<Point> q;
    q.push(make_pair(0, 0));
    while(!q.empty()) {
      Point next = q.front();
      q.pop();
      int i = next.first;
      int j = next.second;
      for(int dir = 0; dir < 4; dir++) {
	for(int step = 1; step <= k; step++) {
	  int x = i + step * dx[dir];
	  int y = j + step * dy[dir];
	  if(x < 0 || y < 0 || x >= n || y >= n) {
	    break;
	  }
	  if(v[x][y] > v[i][j] && dp[x][y] < dp[i][j] + v[x][y]) {
	    dp[x][y] = dp[i][j] + v[x][y];
	    ans = max(ans, dp[x][y]);
	    q.push(make_pair(x, y));
	  }
	}
      }
    }
    printf("%d\n", ans);
  }
  return 0;
}
