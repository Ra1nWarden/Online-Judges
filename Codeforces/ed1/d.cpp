#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>

using namespace std;

const int maxn = 1000;
int n, m, k;
char board[maxn+5][maxn+5];
int visited[maxn+5][maxn+5];
vector<int> ans;
int vis;
int dx[4] = {0, -1, 0, 1};
int dy[4] = {-1, 0, 1, 0};
typedef pair<int, int> Point;

int visit(int x, int y) {
  queue<Point> q;
  visited[x][y] = vis;
  q.push(make_pair(x, y));
  int cnt = 0;
  while(!q.empty()) {
    Point u = q.front();
    q.pop();
    for(int dir = 0; dir < 4; dir++) {
      int xx = u.first + dx[dir];
      int yy = u.second + dy[dir];
      if(xx < 0 || xx >= n || yy < 0 || yy >= m || visited[xx][yy] != -1) {
	continue;
      }
      if(board[xx][yy] == '*') {
	cnt++;
      }
      else {
	visited[xx][yy] = vis;
	q.push(make_pair(xx, yy));
      } 
    }
  }
  vis++;
  ans.push_back(cnt);
  return cnt;
}

int main() {
  scanf("%d%d%d\n", &n, &m, &k);
  for(int i = 0; i < n; i++)
    scanf("%s\n", board[i]);
  memset(visited, -1, sizeof visited);
  vis = 0;
  for(int i = 0; i < k; i++) {
    int x, y;
    scanf("%d%d", &x, &y);
    x--, y--;
    if(visited[x][y] != -1)
      printf("%d\n", ans[visited[x][y]]);
    else
      printf("%d\n", visit(x, y));
  }
  return 0;
}
