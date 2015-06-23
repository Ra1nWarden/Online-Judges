#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>
#define MAXM 105
#define MAXN 2600
#define INF 100000

using namespace std;

int board[MAXM][MAXM];
int n, m;
int node[MAXM][MAXM][2];

struct Edge {
  int from, to, cap, flow, cost; // No need for cost if only using maximum flow algorithm
  Edge(int u, int v, int c, int f);
};

struct EdmondsKarp {
  int n, m; // Number of nodes and edges
  vector<Edge> edges; // Edges vector that saves information of all edges
  vector<int> graph[MAXN]; // Adjacency list that saves index to edges vector
  int a[MAXN]; // Minimum flow in the augmenting path from source to i
  int p[MAXN]; // Parent pointer array to retrieve path (This saves the index of edges NOT vertices)
  // Initialization
  void init(int n);
  // Add an edge
  void addEdge(int from, int to, int cap);
  // Run Edmond Karp's algorithm to find the maximum flow from s to t
  int maxFlow(int s, int t);
};

int main() {
  int tc;
  scanf("%d", &tc);
  while(tc--) {
    memset(board, 0, sizeof board);
    scanf("%d %d", &m, &n);
    int p;
    scanf("%d", &p);
    for(int i = 0; i < p; i++) {
      int x, y;
      scanf("%d %d", &x, &y);
      board[x][y] = 1;
    }
    int w;
    scanf("%d", &w);
    for(int i = 0; i < w; i++) {
      int x, y;
      scanf("%d %d", &x, &y);
      board[x][y] = 2;
    }
    int M = 1;
    for(int i = 1; i <= m; i++) {
      int j = 1;
      while(j <= n) {
	while(j<=n && board[i][j] != 2)
	  node[i][j++][0] = M;
	M++;
	while(j<=n && board[i][j] == 2)
	  j++;
      }
    }
    int N = M+1;
    for(int j = 1; j <= n; j++) {
      int i = 1;
      while(i <= m) {
	while(i <= m && board[i][j] != 2)
	  node[i++][j][1] = N;
	N++;
	while(i <= m && board[i][j] == 2)
	  i++;
      }
    }
    N -= M;
    EdmondsKarp mf;
    mf.init(M+N+2);
    int s = 0;
    int t = M+N+1;
    for(int i = 1; i <= M; i++) {
      mf.addEdge(s, i, 1);
    }
    for(int i = M+1; i <= M+N; i++) {
      mf.addEdge(i, t, 1);
    }
    for(int i = 1; i <= m; i++) {
      for(int j = 1; j <= n; j++) {
	if(board[i][j] == 1)
	  mf.addEdge(node[i][j][0], node[i][j][1], 1);
      }
    }
    printf("%d\n", mf.maxFlow(0, M+N+1));
  }
  return 0;
}

Edge::Edge(int u, int v, int c, int f) : from(u), to(v), cap(c), flow(f) {}

void EdmondsKarp::init(int n) {
  for(int i = 0; i < n; i++) {
    graph[i].clear();
  }
  edges.clear();
  this->n = n;
}

void EdmondsKarp::addEdge(int from, int to, int cap) {
  edges.push_back(Edge(from, to, cap, 0));
  edges.push_back(Edge(to, from, 0, 0)); // Remember to add a back edge
  m = edges.size();
  graph[from].push_back(m-2);
  graph[to].push_back(m-1);
}

int EdmondsKarp::maxFlow(int s, int t) {
  int flow = 0;
  while(true) {
    memset(a, 0, sizeof a);
    queue<int> q;
    q.push(s);
    a[s] = INF;
    while(!q.empty()) {
      int x = q.front();
      q.pop();
      for(int i = 0; i < graph[x].size(); i++) {
	Edge& e = edges[graph[x][i]];
	if(!a[e.to] && e.cap > e.flow) {
	  p[e.to] = graph[x][i];
	  a[e.to] = min(a[x], e.cap - e.flow);
	  q.push(e.to);
	}
      }
      if(a[t])
	break;
    }
    if(!a[t])
      break;
    for(int u = t; u != s; u = edges[p[u]].from) {
      edges[p[u]].flow += a[t];
      edges[p[u]^1].flow -= a[t];
    }
    flow += a[t];
  }
  return flow;
}
