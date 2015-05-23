#include <cstring>
#include <cstdio>
#include <vector>
#include <queue>
#define MAXN 55
#define INF 2000000000

using namespace std;

int w, h;
char board[MAXN][MAXN];
int d, f, b;
int dx[] = {-1, 0, 0, 1};
int dy[] = {0, 1, -1, 0};

struct Edge {
  int from, to, cap, flow;
  Edge(int u, int v, int c, int f) : from(u), to(v), cap(c), flow(f) {}
};

struct Maxflow {
  int m, n;
  vector<Edge> edges;
  vector<int> graph[MAXN*MAXN];
  int a[MAXN*MAXN];
  int p[MAXN*MAXN];
  void init(int n) {
    this->n = n;
    for(int i = 0; i < n; i++)
      graph[i].clear();
    edges.clear();
  }
  void addEdge(int from, int to, int cap) {
    edges.push_back(Edge(from, to, cap, 0));
    edges.push_back(Edge(to, from, 0, 0));
    m = edges.size();
    graph[from].push_back(m - 2);
    graph[to].push_back(m - 1);
  }
  int maxflow(int s, int t) {
    int flow = 0;
    while(true) {
      memset(a, 0, sizeof a);
      a[s] = INF;
      queue<int> q;
      q.push(s);
      while(!q.empty()) {
	int u = q.front();
	q.pop();
	for(int i = 0; i < graph[u].size(); i++) {
	  Edge& e = edges[graph[u][i]];
	  if(a[e.to] == 0 && e.cap > e.flow) {
	    a[e.to] = min(a[u], e.cap - e.flow);
	    p[e.to] = graph[u][i];
	    q.push(e.to);
	  }
	}
      }
      if(a[t] == 0)
	break;
      flow += a[t];
      for(int u = t; u != s; u = edges[p[u]].from) {
	edges[p[u]].flow += a[t];
	edges[p[u]^1].flow -= a[t];
      }
    }
    return flow;
  }
};

Maxflow mf;

int main() {
  int tc;
  scanf("%d", &tc);
  while(tc--) {
    scanf("%d %d", &w, &h);
    scanf("%d %d %d\n", &d, &f, &b);
    for(int i = 0; i < h; i++)
      scanf("%s\n", board[i]);
    int cost = 0;
    for(int i = 0; i < h; i++) {
      for(int j = 0; j < w; j++) {
	if(i == 0 || i == h-1 || j == 0 || j == w-1) {
	  if(board[i][j] == '.') {
	    board[i][j] = '#';
	    cost += f;
	  }
	}
      }
    }
    mf.init(w * h + 2);
    for(int i = 0; i < h; i++) {
      for(int j = 0; j < w; j++) {
	if(i == 0 || i == h-1 || j == 0 || j == w-1) {
	  mf.addEdge(0, i * w + j + 1, INF);
	} else {
	  if(board[i][j] == '#') {
	    mf.addEdge(0, i * w + j + 1, d);
	  } else {
	    mf.addEdge(i * w + j + 1, w * h + 1, f);
	  }
	}
	for(int di = 0; di < 4; di++) {
	  int ii = i + dx[di];
	  int jj = j + dy[di];
	  if(ii > -1 && ii < h && jj > -1 && jj < w) {
	    mf.addEdge(i * w + j + 1, ii * w + jj + 1, b);
	  }
	}
      }
    }
    printf("%d\n", cost + mf.maxflow(0, w * h + 1));
  }
  return 0;
}
