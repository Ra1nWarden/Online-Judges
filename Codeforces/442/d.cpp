#include <cstdio>
#include <queue>
#include <cstring>

using namespace std;

const int maxn = 1000;
const int dx[] = {-1, 0, 1, 0};
const int dy[] = {0, 1, 0, -1};
char mat[maxn+5][maxn+5];
int n, m, k, x1, y1, x2, y2;
typedef pair<int, int> Coord;
typedef pair<Coord, int> Node;
int vis[maxn+5][maxn+5][4];

int main() {
  scanf("%d%d%d\n", &n, &m, &k);
  for(int i = 0; i < n; i++)
    scanf("%s\n", mat[i]);
  scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
  memset(vis, -1, sizeof vis);
  queue<Node> q;
  for(int i = 0; i < 4; i++) {
    q.push(make_pair(make_pair(x1-1, y1-1), i));
    vis[x1-1][y1-1][i] = 0;
  }
  while(!q.empty()) {
    Node u = q.front();
    q.pop();
    for(int i = 0; i < 4; i++) {
      for(int d = 1; d <= k; d++) {
	int xx = u.first.first + dx[i] * d;
	int yy = u.first.second + dy[i] * d;
	if(xx < 0 || yy < 0 || xx >= n || yy >= m || vis[xx][yy][i] != -1 || mat[xx][yy] == '#') {
	  break;
	}
	vis[xx][yy][i] = vis[u.first.first][u.first.second][u.second] + 1;
	q.push(make_pair(make_pair(xx, yy), i));
      }
    }
  }
  int ans = -1;
  for(int i = 0; i < 4; i++) {
    if(vis[x2-1][y2-1][i] != -1) {
      ans = ans == -1 ? vis[x2-1][y2-1][i] : min(ans, vis[x2-1][y2-1][i]);
    }
  }
  printf("%d\n", ans);
  return 0;
}
