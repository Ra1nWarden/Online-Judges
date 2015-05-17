#include <cstdio>
#include <vector>
#include <queue>
#include <cstring>
#define MAXV 210
#define INF 2000000000

using namespace std;

struct Edge {
  int from, to, cap, flow, cost;
  Edge(int u, int v, int c, int f, int w) : from(u), to(v), cap(c), flow(f), cost(w) {}
};

struct MCMF {
  int n, m;
  vector<int> graph[MAXV];
  vector<Edge> edges;
  bool inq[MAXV];
  int a[MAXV];
  int d[MAXV];
  int p[MAXV];
  void init(int n) {
    this->n = n;
    for(int i = 0; i < n; i++)
      graph[i].clear();
    edges.clear();
  }
  void addEdge(int from, int to, int cap, int cost) {
    edges.push_back(Edge(from, to, cap, 0, cost));
    edges.push_back(Edge(to, from, 0, 0, -cost));
    m = edges.size();
    graph[from].push_back(m-2);
    graph[to].push_back(m-1);
  }
  bool bellmanFord(int s, int t, int& flow, int& cost) {
    for(int i = 0; i < n; i++) {
      d[i] = INF;
    }
    memset(inq, false, sizeof inq);
    d[s] = 0;
    a[s] = INF;
    inq[s] = true;
    p[s] = -1;
    queue<int> q;
    q.push(s);
    while(!q.empty()) {
      int u = q.front();
      q.pop();
      inq[u] = false;
      for(int i = 0; i < graph[u].size(); i++) {
	Edge& e = edges[graph[u][i]];
	if(e.cap > e.flow && d[e.to] > d[u] + e.cost) {
	  d[e.to] = d[u] + e.cost;
	  p[e.to] = graph[u][i];
	  a[e.to] = min(a[u], e.cap - e.flow);
	  if(!inq[e.to]) {
	    q.push(e.to);
	    inq[e.to] = true;
	  }
	}
      }
    }
    if(d[t] == INF)
      return false;
    flow += a[t];
    cost += a[t] * d[t];
    for(int u = t; u != s; u = edges[p[u]].from) {
      edges[p[u]].flow += a[t];
      edges[p[u]^1].flow -= a[t];
    }
    return true;
  }
  int mcmf(int s, int t, int& cost) {
    int flow = 0;
    cost = 0;
    while(bellmanFord(s, t, flow, cost));
    return flow;
  }
};

MCMF sol;

int main() {
  int n;
  while(scanf("%d", &n) != EOF && n) {
    sol.init(n*2+2);
    for(int i = 1; i <= n; i++) {
      int v, w;
      while(scanf("%d", &v) != EOF && v) {
	scanf("%d", &w);
	sol.addEdge(i, v + n, 1, w);
      }
    }
    for(int i = 1; i <= n; i++) {
      sol.addEdge(0, i, 1, 0);
    }
    for(int i = n+1; i <= 2*n; i++) {
      sol.addEdge(i, 2*n+1, 1, 0);
    }
    int cost;
    int flow = sol.mcmf(0, n+n+1, cost);
    if(flow != n) {
      printf("N\n");
    } else {
      printf("%d\n", cost);
    }
  }
  return 0;
}
