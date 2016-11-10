#include <cstdio>
#include <cstring>
#include <utility>
#include <algorithm>
#include <queue>

using namespace std;

int n, m, k;
const int maxn = 50;
char str[maxn+5][maxn+5];
int visited[maxn+5][maxn+5];

struct Node {
  int total, color;
  bool operator<(const Node& rhs) const {
    return total < rhs.total;
  }
};

Node nodes[maxn*maxn+5];
int ni;
typedef pair<int, int> Point;
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};
bool change[maxn*maxn+5];

int main() {
  scanf("%d%d%d\n", &n, &m, &k);
  for(int i = 0; i < n; i++)
    scanf("%s\n", str[i]);
  memset(visited, 0, sizeof visited);
  ni = 0;
  int l = 0;
  int vis = 1;
  for(int i = 0; i < n; i++) {
    for(int j = 0; j < m; j++) {
      if(str[i][j] == '.' && visited[i][j] == 0) {
	bool ok = i != 0 && i != n - 1 && j != 0 && j != m - 1;
	int size = 0;
	visited[i][j] = vis;
	size++;
	queue<Point> q;
	q.push(make_pair(i, j));
	while(!q.empty()) {
	  Point u = q.front();
	  q.pop();
	  for(int k = 0; k < 4; k++) {
	    int xx = u.first + dx[k];
	    int yy = u.second + dy[k];
	    if(xx < 0 || yy < 0 || xx >= n || yy >= m)
	      continue;
	    if(str[xx][yy] == '*' || visited[xx][yy])
	      continue;
	    if(xx == 0 || yy == 0 || xx == n -1 || yy == m - 1) {
	      ok = false;
	    }
	    visited[xx][yy] = vis;
	    size++;
	    q.push(make_pair(xx, yy));
	  }
	}
	if(ok) {
	  l++;
	  nodes[ni++] = Node{size, vis};
	}
	vis++;
      }
    }
  }
  sort(nodes, nodes+ni);
  memset(change, false, sizeof change);
  int sum = 0;
  for(int i = 0; i < l - k; i++) {
    change[nodes[i].color] = true;
    sum += nodes[i].total;
  }
  printf("%d\n", sum);
  for(int i = 0; i < n; i++) {
    for(int j = 0; j < m; j++) {
      if(str[i][j] == '*')
	printf("*");
      else if(change[visited[i][j]])
	printf("*");
      else
	printf(".");
    }
    printf("\n");
  }
  return 0;
}
