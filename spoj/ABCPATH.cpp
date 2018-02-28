#include <cstdio>
#include <cstring>
#include <utility>
#include <queue>

using namespace std;

const int maxn = 50;
char mat[maxn][maxn+5];
bool vis[maxn][maxn+5];
int dx[] = {-1, -1, -1, 0, 0, 1, 1, 1};
int dy[] = {-1, 0, 1, -1, 1, -1, 0, 1};
int h, w;
typedef pair<int, int> Node;

int main() {
  int tc = 1;
  while(true) {
    scanf("%d%d\n", &h, &w);
    if(h == 0 && w == 0)
      break;
    for(int i = 0; i < h; i++)
      scanf("%s\n", mat[i]);
    memset(vis, false, sizeof vis);
    queue<Node> q;
    for(int i = 0; i < h; i++) {
      for(int j = 0; j < w; j++) {
	if(mat[i][j] == 'A') {
	  q.push(make_pair(i, j));
	  vis[i][j] = true;
	}
      }
    }
    int ans = 0;
    while(!q.empty()) {
      Node u = q.front();
      q.pop();
      int x = u.first;
      int y = u.second;
      ans = max(ans, (mat[x][y] - 'A') + 1);
      for(int i = 0; i < 8; i++) {
	int xx = x + dx[i];
	int yy = y + dy[i];
	if(xx < 0 || xx >= h || yy < 0 || yy >= w)
	  continue;
	if(mat[xx][yy] - mat[x][y] != 1)
	  continue;
	if(!vis[xx][yy]) {
	  vis[xx][yy] = true;
	  q.push(make_pair(xx, yy));
	}
      }
    }
    printf("Case %d: %d\n", tc++, ans);
  }
  return 0;
}
