#include <cstdio>
#include <queue>
#include <map>
#include <cmath>
#define MAXN 55
#define INF 2000000000

using namespace std;

struct Node {
  int x, y, k;
  double dist;
  Node(int x, int y, int k, double dist) : x(x), y(y), k(k), dist(dist) {}
  bool operator<(const Node& rhs) const {
    return dist > rhs.dist;
  }
};

char board[MAXN][MAXN];
int n, m, k;
double min_dist[MAXN][MAXN];
bool visited[MAXN][MAXN];
int sx, sy, ex, ey;
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};

int main() {
  int tc;
  scanf("%d", &tc);
  while(tc--) {
    scanf("%d %d %d\n", &n, &m, &k);
    for(int i = 1; i <= n; i++)
      scanf("%s\n", board[i]+1);
    scanf("%d %d %d %d", &sx, &sy, &ex, &ey);
    for(int i = 1; i <= n; i++)
      for(int j = 1; j <= m; j++) {
	min_dist[i][j] = INF;
	visited[i][j] = false;
      }
    priority_queue<Node> pq;
    min_dist[sx][sy] = 0;
    if(k > 0) {
      pq.push(Node(sx, sy, k, 0));
    }
    while(!pq.empty()) {
      Node u = pq.top();
      pq.pop();
      if(visited[u.x][u.y])
	continue;
      visited[u.x][u.y] = true;
      for(int i = 0; i < 4; i++) {
	int xx = u.x + dx[i];
	int yy = u.y + dy[i];
	if(xx < 1 || xx > m || yy < 1 || yy > n)
	  continue;
	if(board[xx][yy] == '#')
	  continue;
	double kk = u.k - 1;
	double new_dist = u.dist + abs((int) (board[u.x][u.y] - '0') - (int) (board[xx][yy] - '0')) * 1.0 / u.k;
	if(new_dist < min_dist[xx][yy]) {
	  min_dist[xx][yy] = new_dist;
	  pq.push(Node(xx, yy, kk, new_dist));
	}
      }
    }
    if(min_dist[ex][ey] == INF)
      printf("No Answer\n");
    else 
      printf("%.2lf\n", min_dist[ex][ey]);
  }
  return 0;
}
