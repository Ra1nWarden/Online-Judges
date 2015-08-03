#include <iostream>
#include <cstring>
#include <vector>
#include <queue>
#define MAXN 250
#define INF 2000000000
#define MAXC 105

using namespace std;

int v[MAXC];
int vn;
int n;
string mat[MAXC];
bool border[MAXC];
int bn;

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

bool ok(int f) {
  EdmondsKarp mf;
  mf.init(2 * n + 2);
  int s = 2 * n, t = 2 * n + 1;
  for(int i = 0; i < n; i++) {
    if(v[i] > 0) {
      mf.addEdge(s, i << 1, v[i]);
      mf.addEdge(i << 1, (i << 1) | 1, v[i]);
      if(border[i]) {
	mf.addEdge(i << 1, t, f);
      } else {
	mf.addEdge(i << 1, t, 1);
      }
      for(int j = 0; j < n; j++) {
	if(mat[i][j] == 'Y' && v[j] > 0)
	  mf.addEdge((i << 1) | 1, j << 1, v[i]);
      }
    }
  }
  int flow = mf.maxFlow(s, t);
  return flow == vn - bn + bn * f;
}

int main() {
  ios::sync_with_stdio(false);
  int tc;
  cin >> tc;
  while(tc--) {
    cin >> n;
    vn = 0;
    for(int i = 0; i < n; i++) {
      cin >> v[i];
      if(v[i] > 0)
	vn++;
    }
    string line;
    getline(cin, line);
    for(int i = 0; i < n; i++) {
      getline(cin, mat[i]);
    }
    memset(border, false, sizeof border);
    for(int i = 0; i < n; i++) {
      if(v[i] == 0) {
	for(int j = 0; j < n; j++) {
	  if(mat[i][j] == 'Y' && v[j] > 0) {
	    border[j] = true;
	  }
	}
      }
    }
    bn = 0;
    for(int i = 0; i < n; i++)
      if(border[i])
	bn++;
    int lower = 1;
    int upper = 10000;
    while(lower != upper) {
      int mid = ((lower + upper) >> 1) + 1;
      if(ok(mid)) {
	lower = mid;
      } else {
	upper = mid - 1;
      }
    }
    cout << lower << endl;
  }
  return 0;
}
