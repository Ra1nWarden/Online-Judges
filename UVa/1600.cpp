#include <cstdio>
#include <queue>
#include <cstring>
#define MAXN 21

using namespace std;

int m, n, k;
int board[MAXN][MAXN];
bool visited[MAXN][MAXN][MAXN];

struct Node {
  int x, y, e;
  Node(int x, int y, int e) : x(x), y(y), e(e) {}
  bool operator<(const Node& rhs) const {
    if(x != rhs.x)
      return x < rhs.x;
    if(y != rhs.y)
      return y < rhs.y;
    if(e != rhs.e)
      return e < rhs.e;
    return false;
  }
};

typedef pair<Node, int> QNode;
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};

int main() {
  int tc;
  scanf("%d", &tc);
  while(tc--) {
    scanf("%d %d %d", &m, &n, &k);
    for(int i = 0; i < m; i++) {
      for(int j = 0; j < n; j++) {
	scanf("%d", &board[i][j]);
      }
    }
    memset(visited, false, sizeof visited);
    Node start(0, 0, k);
    QNode startNode = make_pair(start, 0);
    int ans = -1;
    queue<QNode> q;
    q.push(startNode);
    visited[0][0][k] = true;
    while(!q.empty()) {
      QNode u = q.front();
      q.pop();
      Node u_node = u.first;
      int step = u.second;
      if(u_node.x == m - 1 && u_node.y == n - 1) {
	ans = step;
	break;
      }
      for(int i = 0; i < 4; i++) {
	int xx = u_node.x + dx[i];
	int yy = u_node.y + dy[i];
	if(xx < 0 || xx >= m || yy < 0 || yy >= n) {
	  continue;
	}
	if(board[xx][yy]) {
	  if(u_node.e > 0) {
	    if(!visited[xx][yy][u_node.e - 1]) {
	      visited[xx][yy][u_node.e - 1] = true;
	      Node v(xx, yy, u_node.e - 1);
	      q.push(make_pair(v, step+1));
	    }
	  }
	} else {
	  if(!visited[xx][yy][k]) {
	    visited[xx][yy][k] = true;
	    Node v(xx, yy, k);
	    q.push(make_pair(v, step+1));
	  }
	}
      }
    }
    printf("%d\n", ans);
  }
  return 0;
}
