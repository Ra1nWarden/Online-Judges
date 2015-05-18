#include <cstdio>
#include <queue>
#include <cstring>
#define MAXN 305
#define INF 1000000000

using namespace std;

struct Edge {
  int u, v, a, b, t;
  Edge(int uu, int vv, int aa, int bb, int tt) : u(uu), v(vv), a(aa), b(bb), t(tt) {}
};

int n, m, s, t;
bool visited[MAXN];
vector<int> graph[MAXN];
vector<Edge> edges;
int d[MAXN];

typedef pair<int, int> HeapNode;

int main() {
  int kase = 1;
  while(scanf("%d %d %d %d", &n, &m, &s, &t) != EOF) {
    for(int i = 1; i <= n; i++)
      graph[i].clear();
    edges.clear();
    for(int i = 0; i < m; i++) {
      int u, v, a, b, time;
      scanf("%d %d %d %d %d", &u, &v, &a, &b, &time);
      edges.push_back(Edge(u, v, a, b, time));
      edges.push_back(Edge(v, u, a, b, time));
      graph[u].push_back(edges.size() - 2);
      graph[v].push_back(edges.size() - 1);
    }
    memset(visited, false, sizeof visited);
    for(int i = 1; i <= n; i++)
      d[i] = INF;
    d[s] = 0;
    priority_queue<HeapNode, vector<HeapNode>, greater<HeapNode> > pq;
    pq.push(make_pair(0, s));
    while(!pq.empty()) {
      HeapNode next = pq.top();
      pq.pop();
      int u = next.second;
      int cst = next.first;
      if(visited[u])
	continue;
      visited[u] = true;
      for(int i = 0; i < graph[u].size(); i++) {
	Edge& e = edges[graph[u][i]];
	if(e.t <= e.a) {
	  int left = cst % (e.a + e.b);
	  int cost = INF;
	  if(e.a - left >= e.t) {
	    cost = e.t;
	  } else {
	    cost = e.a + e.b - left + e.t;
	  }
	  if(d[e.v] > cost + d[u]) {
	    d[e.v] = cost + d[u];
	    pq.push(make_pair(cost + d[u], e.v));
	  }
	}
      }
    }
    printf("Case %d: %d\n", kase++, d[t]);
  }
  return 0;
    
}
