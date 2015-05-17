#include <cstdio>
#include <vector>
#include <queue>
#include <cstring>
#define MAXV 2005
#define INF 2000000000

using namespace std;

struct Edge {
  int from, to, cap, flow, cost;
  Edge(int u, int v, int c, int f, int w) : from(u), to(v), cap(c), flow(f), cost(w) {}
};

int m, n;
vector<Edge> edges;
vector<int> graph[MAXV];
int d[MAXV];
int a[MAXV];
int p[MAXV];
bool inq[MAXV];

void init(int nn) {
  n = nn;
  for(int i = 1; i <= n; i++)
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
  for(int i = 1; i <= n; i++)
    d[i] = INF;
  d[s] = 0;
  p[s] = 0;
  memset(inq, false, sizeof inq);
  memset(a, 0, sizeof a);
  inq[s] = true;
  a[s] = INF;
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
  cost += d[t] * a[t];
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

int main() {
  int v, e;
  while(scanf("%d %d", &v, &e) != EOF) {
    init((v << 1) | 1);
    for(int i = 0; i < e; i++) {
      int aa, bb, cc;
      scanf("%d %d %d", &aa, &bb, &cc);
      if(aa == 1) {
	addEdge(aa, bb << 1, 1, cc);
      } else {
	if(aa != v)
	  addEdge((aa << 1) | 1, bb << 1, 1, cc);
	else
	  addEdge(aa << 1, bb << 1, 1, cc);
      }
    }
    for(int i = 2; i < v; i++) {
      addEdge((i << 1), (i << 1) | 1, 1, 0);
    }
    addEdge((v << 1), (v << 1) | 1, 2, 0);
    int cost;
    mcmf(1, (v << 1) | 1, cost);
    printf("%d\n", cost);
  }
  return 0;
}
