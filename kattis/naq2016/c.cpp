#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>

using namespace std;

const int maxn = 100;
const int inf = 2000000000;

struct Edge {
  int from, to, dist;
  Edge(int u, int v, int d);
};

struct HeapNode {
  int d, v, i;
  bool operator<(const HeapNode& rhs) const {
    if(d != rhs.d) {
      return d > rhs.d;
    }
    return v < rhs.v;
  }
};

struct Dijkstra {
  int n, m; // n is the number of vertices and m is the number of edges
  vector<Edge> edges; // Edges vector
  vector<int> graph[maxn+5]; // Adjacency list that saves index to edges vector
  bool visited[maxn+5]; // Visited mark array
  int d[maxn+5]; // Distance array
  int p[maxn+5]; // Pick up array
  // Initialization
  void init(int n);
  // Add an edge
  void addEdge(int from, int to, int d);
  // Run dijkstra from source s to dest t
  pair<int, int> dijkstra(int s, int t);
};

Dijkstra d;
int v[maxn+5];

int main() {
  int n;
  scanf("%d", &n);
  d.init(n);
  for(int i = 1; i <= n; i++) {
    scanf("%d", &v[i]);
  }
  int m;
  scanf("%d", &m);
  while(m--) {
    int a, b, c;
    scanf("%d%d%d", &a, &b, &c);
    d.addEdge(a, b, c);
    d.addEdge(b, a, c);
  }
  pair<int, int> ans = d.dijkstra(1, n);
  if(ans.first == inf) {
    printf("impossible\n");
  } else {
    printf("%d %d\n", ans.first, ans.second);
  }
  return 0;
}

Edge::Edge(int u, int v, int d) : from(u), to(v), dist(d) {}

void Dijkstra::init(int n) {
  this->n = n;
  for(int i = 0; i < n; i++)
    graph[i].clear();
  edges.clear();
}

void Dijkstra::addEdge(int from, int to, int d) {
  edges.push_back(Edge(from, to, d));
  m = edges.size();
  graph[from].push_back(m-1);
}

pair<int, int> Dijkstra::dijkstra(int s, int t) {
  memset(p, 0, sizeof p);
  priority_queue<HeapNode> pq;
  for(int i = 1; i <= n; i++)
    d[i] = inf;
  d[s] = 0;
  p[s] = v[s];
  memset(visited, false, sizeof visited);
  pq.push(HeapNode {0, v[s], s});
  while(!pq.empty()) {
    HeapNode node = pq.top();
    pq.pop();
    int u = node.i;
    //printf("u=%d\n", u);
    if(u == t) {
      return make_pair(node.d, node.v);
    }
    if(visited[u])
      continue;
    visited[u] = true;
    for(int i = 0; i < graph[u].size(); i++) {
      Edge& e = edges[graph[u][i]];
      //printf("checking %d\n", e.to);
      if(d[e.to] > d[u] + e.dist || (d[e.to] == d[u] + e.dist && p[u] + v[e.to] > p[e.to])) {
	d[e.to] = d[u] + e.dist;
	p[e.to] = p[u] + v[e.to];
	//printf("pushing %d\n", e.to);
	pq.push(HeapNode {d[e.to], p[e.to], e.to});
      }
    }
  }
  return make_pair(inf, 0); // Not reachable
}
