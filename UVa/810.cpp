#include <cstdio>
#include <cstring>
#include <queue>
#define MAXN 25
#define MAXL 11

using namespace std;

char name[MAXN];
char end[] = "END";
int r, c, x, y, u, f;
int board[MAXL][MAXL];
bool visited[7][7][MAXL][MAXL];
int left[7][7];

struct Node {
  int u, f, x, y;
  Node() {}
  Node(int u, int f, int x, int y) : u(u), f(f), x(x), y(y) {}
  bool operator<(const Node& rhs) const {
    if(u != rhs.u)
      return u < rhs.u;
    if(f != rhs.f)
      return f < rhs.f;
    if(x != rhs.x)
      return x < rhs.x;
    if(y != rhs.y)
      return y < rhs.y;
    return false;
  }
  bool operator==(const Node& rhs) const {
    return x == rhs.x && y == rhs.y && u == rhs.u && f == rhs.f;
  }
  bool operator!=(const Node& rhs) const {
    return !(*this == rhs);
  }
};
Node parent[7][7][MAXN][MAXN];
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};
typedef pair<int, int> Point;

Node rotate(Node node, int dir) {
  int xx = node.x + dx[dir];
  int yy = node.y + dy[dir];
  int ff, uu;
  switch(dir) {
  case 0:
    uu = node.f;
    ff = 7 - node.u;
    break;
  case 1:
    ff = node.f;
    uu = left[node.u][node.f];
    break;
  case 2:
    ff = node.u;
    uu = 7 - node.f;
    break;
  case 3:
    ff = node.f;
    uu = 7 - left[node.u][node.f];
    break;
  }
  return Node(uu, ff, xx, yy);
}

int main() {
  left[1][2] = 4;
  left[1][3] = 2;
  left[1][4] = 5;
  left[1][5] = 3;
  left[2][1] = 3;
  left[2][4] = 1;
  left[2][3] = 6;
  left[2][6] = 4;
  left[3][1] = 5;
  left[3][2] = 1;
  left[3][6] = 2;
  left[3][5] = 6;
  left[4][1] = 2;
  left[4][2] = 6;
  left[4][5] = 1;
  left[4][6] = 5;
  left[5][1] = 4;
  left[5][3] = 1;
  left[5][4] = 6;
  left[5][6] = 3;
  left[6][2] = 3;
  left[6][4] = 2;
  left[6][5] = 4;
  left[6][3] = 5;
  while(scanf("%s", name) != EOF) {
    if(strcmp(end, name) == 0)
      break;
    scanf("%d %d %d %d %d %d", &r, &c, &x, &y, &u, &f);
    for(int i = 1; i <= r; i++) {
      for(int j = 1; j <= c; j++) {
	scanf("%d", &board[i][j]);
      }
    }
    memset(visited, false, sizeof visited);
    Node start_node(u, f, x, y);
    visited[u][f][x][y] = true;
    queue<Node> q;
    q.push(start_node);
    bool ok = false;
    Node end_node;
    while(!q.empty()) {
      Node node = q.front();
      q.pop();
      for(int i = 0; i < 4; i++) {
	int xx = node.x + dx[i];
	int yy = node.y + dy[i];
	if(xx <= 0 || xx > r || yy <= 0 || yy > c) {
	  continue;
	}
	if(board[xx][yy] == 0)
	  continue;
	if(board[xx][yy] != -1 && board[xx][yy] != node.u)
	  continue;
	Node new_node = rotate(node, i);
	if(new_node.x == x && new_node.y == y) {
	  ok = true;
	  end_node = node;
	  break;
	}
	if(visited[new_node.u][new_node.f][new_node.x][new_node.y]) {
	  continue;
	}
	parent[new_node.u][new_node.f][new_node.x][new_node.y] = node;
	visited[new_node.u][new_node.f][new_node.x][new_node.y] = true;
	q.push(new_node);
      }
      if(ok) {
	break;
      }
    }
    printf("%s", name);
    if(ok) {
      vector<Point> points;
      points.push_back(make_pair(start_node.x, start_node.y));
      while(end_node != start_node) {
	points.push_back(make_pair(end_node.x, end_node.y));
	end_node = parent[end_node.u][end_node.f][end_node.x][end_node.y];
      }
      points.push_back(make_pair(start_node.x, start_node.y));
      for(int i = 0; i < points.size(); i++) {
	if(i % 9 == 0) {
	  printf("\n  ");
	}
	printf("(%d,%d)", points[points.size() - 1 - i].first, points[points.size() - 1 - i].second);
	if(i != points.size() - 1)
	  printf(",");
	else
	  printf("\n");
      }
    } else {
      printf("\n  No Solution Possible\n");
    }
  }
  return 0;
}
