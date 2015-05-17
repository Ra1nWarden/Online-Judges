#include <queue>
#include <cstring>
#include <cstdio>
#include <vector>
#define MAXN 25
#define MAXV 45
#define MAXE 500
#define INF 2000000000

using namespace std;

int r, c;
int ans[MAXN][MAXN];
int rv[MAXN], cv[MAXN];

struct Edge {
  int from, to, cap, flow;
  Edge(int a, int b, int c, int d) : from(a), to(b), cap(c), flow(d) {}
};

struct Maxflow {
  int n, m;
  vector<int> graph[MAXV];
  vector<Edge> edges;
  int a[MAXV], p[MAXV];
  void init(int n) {
    for(int i = 0; i < n; i++)
      graph[i].clear();
    edges.clear();
    this->n = n;
  }
  void addEdge(int from, int to, int cap) {
    edges.push_back(Edge(from, to, cap, 0));
    edges.push_back(Edge(to, from, 0, 0));
    m = edges.size();
    graph[from].push_back(m-2);
    graph[to].push_back(m-1);
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
	  if(e.cap > e.flow && !a[e.to]) {
	    a[e.to] = min(a[u], e.cap - e.flow);
	    p[e.to] = graph[u][i];
	    q.push(e.to);
	  }
	}
	if(a[t] != 0)
	  break;
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
  for(int kase = 1; kase <= tc; kase++) {
    if(kase > 1)
      printf("\n");
    scanf("%d %d", &r, &c);
    int prev, cur;
    for(int i = 0; i < r; i++) {
      scanf("%d", &cur);
      if(i == 0)
	rv[i] = cur;
      else
	rv[i] = cur - prev;
      prev = cur;
    }
    for(int i = 0; i < c; i++) {
      scanf("%d", &cur);
      if(i == 0)
	cv[i] = cur;
      else
	cv[i] = cur - prev;
      prev = cur;
    }
    mf.init(r+c+2);
    for(int i = 1; i <= r; i++) {
      mf.addEdge(0, i, rv[i-1] - c);
    }
    for(int i = r+1; i <= r+c; i++) {
      mf.addEdge(i, r+c+1, cv[i-r-1] - r);
    }
    for(int i = 1; i <= r; i++) {
      for(int j = r+1; j <= r+c; j++) {
	mf.addEdge(i, j, 19);
      }
    }
    int flow = mf.maxflow(0, r+c+1);
    for(int i = 1; i <= r; i++) {
      for(int j = 0; j < mf.graph[i].size(); j++) {
	Edge& e = mf.edges[mf.graph[i][j]];
	if(e.to - r >= 1 && e.to -r <= c)
	  ans[i][e.to-r] = e.flow;
      }
    }
    printf("Matrix %d\n", kase);
    for(int i = 1; i <= r; i++) {
      for(int j = 1; j <= c; j++) {
	if(j > 1)
	  printf(" ");
	printf("%d", ans[i][j]+1);
      }
      printf("\n");
    }
  }
  return 0;
}
