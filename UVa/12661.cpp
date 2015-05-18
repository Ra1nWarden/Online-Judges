#include <cstdio>
#include <queue>
#include <cstring>
#define MAXN 305
#define INF 1000000000

using namespace std;

struct Edge {
  int from, to, t1, t2, t3;
  Edge(int u, int v, int a, int b, int t) : from(u), to(v), t1(a), t2(b), t3(t) {}
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
      graph[u].push_back(edges.size() - 1);
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
      if(visited[u])
	continue;
      visited[u] = true;
      for(int i = 0; i < graph[u].size(); i++) {
	Edge& e = edges[graph[u][i]];
	if(e.t3 <= e.t1) {
	  int left = d[u] % (e.t1 + e.t2);
	  int cost = INF;
	  if(e.t1 - left >= e.t3) {
	    cost = e.t3;
	  } else {
	    cost = e.t1 + e.t2 - left + e.t3;
	  }
	  if(d[e.to] > cost + d[u]) {
	    d[e.to] = cost + d[u];
	    pq.push(make_pair(cost + d[u], e.to));
	  }
	}
      }
    }
    printf("Case %d: %d\n", kase++, d[t]);
  }
  return 0;
    
}
