#include <cstdio>
#include <vector>
#include <cstring>
#include <queue>
#define INF 1000
#define MAXN 105

using namespace std;

struct Edge {
  int from, to, cap, flow; // No need for cost if only using maximum flow algorithm
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
  void reset();
};

int n, m;

int main() {
  while(scanf("%d %d", &n, &m) != EOF) {
    EdmondsKarp mf;
    mf.init(2*n);
    for(int i = 0; i < n; i++) {
      mf.addEdge(2*i, 2*i+1, 1);
    }
    for(int i = 0; i < m; i++) {
      int a, b;
      scanf(" (%d,%d)", &a, &b);
      mf.addEdge(2*a+1, 2*b, INF);
      mf.addEdge(2*b+1, 2*a, INF);
    }
    int ans = INF;
    for(int i = 0; i < n; i++) {
      for(int j = i+1; j < n; j++) {
	mf.reset();
	ans = min(ans, mf.maxFlow(i*2+1, j*2));
      }
    }
    if(ans == INF)
      ans = n;
    printf("%d\n", ans);
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

void EdmondsKarp::reset() {
  for(int i = 0; i < m; i++) {
    edges[i].flow = 0;
  }
}
