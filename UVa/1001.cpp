#include <cstdio>
#include <utility>
#include <queue>
#include <cstring>
#include <cmath>
#define MAXN 105
#define INF 200000000

using namespace std;

int n;
int x[MAXN], y[MAXN], z[MAXN], r[MAXN];

struct Edge {
  int from, to;
  double dist;
  Edge(int u, int v, double d);
};

typedef pair<double, int> HeapNode; // A type that saves (distance, index) for the priority_queue in Dijkstra's algorithm
struct Dijkstra {
  int n, m; // n is the number of vertices and m is the number of edges
  vector<Edge> edges; // Edges vector
  vector<int> graph[MAXN]; // Adjacency list that saves index to edges vector
  bool visited[MAXN]; // Visited mark array
  double d[MAXN]; // Distance array
  int p[MAXN]; // Parent array for path restoration
  // Initialization
  void init(int n);
  // Add an edge
  void addEdge(int from, int to, double d);
  // Run dijkstra from source s to desintaion t and save path
  double dijkstra(int s, int t);
};

int main() {
  int kase = 1;
  while(scanf("%d", &n) != EOF && n != -1) {
    for(int i = 1; i <= n; i++) {
      scanf("%d %d %d %d", &x[i], &y[i], &z[i], &r[i]);
    }
    scanf("%d %d %d", &x[0], &y[0], &z[0]);
    scanf("%d %d %d", &x[n+1], &y[n+1], &z[n+1]);
    r[0] = r[n+1] = 0;
    Dijkstra sol;
    sol.init(n+2);
    for(int i = 0; i <= n+1; i++) {
      for(int j = i+1; j <= n+1; j++) {
	double dist = max(sqrt(pow(x[i] - x[j], 2) + pow(y[i] - y[j], 2) + pow(z[i] - z[j], 2)) - r[i] - r[j], 0.0) * 10;
	sol.addEdge(i, j, dist);
	sol.addEdge(j, i, dist);
      }
    }
    printf("Cheese %d: Travel time = %.0f sec\n", kase++, sol.dijkstra(0, n+1));
  }
  return 0;
}

Edge::Edge(int u, int v, double d) : from(u), to(v), dist(d) {}

void Dijkstra::init(int n) {
  this->n = n;
  for(int i = 0; i < n; i++)
    graph[i].clear();
  edges.clear();
}

void Dijkstra::addEdge(int from, int to, double d) {
  edges.push_back(Edge(from, to, d));
  m = edges.size();
  graph[from].push_back(m-1);
}

double Dijkstra::dijkstra(int s, int t) {
  priority_queue<HeapNode, vector<HeapNode>, greater<HeapNode> > pq;
  for(int i = 0; i < n; i++)
    d[i] = INF;
  d[s] = 0;
  memset(visited, false, sizeof visited);
  pq.push(make_pair(0.0, s));
  while(!pq.empty()) {
    HeapNode node = pq.top();
    pq.pop();
    int u = node.second;
    if(u == t) {
      int entry = t;
      while(entry != s) {
	entry = p[entry];
      }
      return d[u];
    }
    if(visited[u])
      continue;
    visited[u] = true;
    for(int i = 0; i < graph[u].size(); i++) {
      Edge& e = edges[graph[u][i]];
      if(d[e.to] > d[u] + e.dist) {
	d[e.to] = d[u] + e.dist;
	p[e.to] = u;
	pq.push(make_pair(d[e.to], e.to));
      }
    }
  }
  return INF; // Not reachable
}

