#include <cstdio>
#include <vector>
#include <queue>
#include <cstring>
#include <set>
#define MAXM 1050
#define MAXN 15
#define INF 200000

using namespace std;

int n, m;
char nums[MAXM][MAXN];

struct Edge {
  int from, to, cap, flow, cost; // No need for cost if only using maximum flow algorithm
  Edge(int u, int v, int c, int f);
};

struct EdmondsKarp {
  int n, m; // Number of nodes and edges
  vector<Edge> edges; // Edges vector that saves information of all edges
  vector<int> graph[MAXM]; // Adjacency list that saves index to edges vector
  int a[MAXM]; // Minimum flow in the augmenting path from source to i
  int p[MAXM]; // Parent pointer array to retrieve path (This saves the index of edges NOT vertices)
  // Initialization
  void init(int n);
  // Add an edge
  void addEdge(int from, int to, int cap);
  // Run Edmond Karp's algorithm to find the maximum flow from s to t
  int maxFlow(int s, int t);
};

bool oddCount(int num) {
  int cnt = 0;
  for(int i = 0; i < n; i++) {
    if(((1 << i) & num) != 0)
      cnt++;
  }
  return cnt % 2;
}

bool inSet(int num) {
  for(int i = 0; i < m; i++) {
    bool ok = true;
    for(int j = 0; j < n; j++) {
      if(nums[i][n-1-j] == '*')
	continue;
      if(((1 << j) & num) == 0 && nums[i][n-1-j] == '1') {
	ok = false;
	break;
      }
      if(((1 << j) & num) != 0 && nums[i][n-1-j] == '0') {
	ok = false;
	break;
      }
    }
    if(ok)
      return true;
  }
  return false;
}

int main() {
  while(scanf("%d %d\n", &n, &m) != EOF && (n || m)) {
    for(int i = 0; i < m; i++) {
      scanf("%s\n", nums[i]);
    }
    EdmondsKarp maxflow;
    maxflow.init((1 << n) + 5);
    int s = (1 << n);
    int t = s+1;
    set<int> nodes;
    int total = 0;
    for(int i = 0; i < (1 << n); i++) {
      if(inSet(i))
	total++;
      if(oddCount(i) && inSet(i) && nodes.count(i) == 0) {
	nodes.insert(i);
	maxflow.addEdge(s, i, 1);
	for(int j = 0; j < n; j++) {
	  int ii = i^(1 << j);
	  if(inSet(ii)) {
	    maxflow.addEdge(i, ii, 1);
	    if(nodes.count(ii) == 0) {
	      maxflow.addEdge(ii, t, 1);
	      nodes.insert(ii);
	    }
	  }
	}
      }
    }
    printf("%d\n", total - maxflow.maxFlow(s, t));
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
