#include <iostream>
#include <sstream>
#include <algorithm>
#include <cstring>
#include <queue>
#include <utility>
#include <vector>
#include <string>
#include <cstdio>

using namespace std;

// @begin_lib
// @end_lib

const int MAXN = 100100;
const int inf = 1000000000;

struct Edge {
  int from, to, cap, flow, cost; // No need for cost if only using maximum flow algorithm
  Edge(int u, int v, int c, int f);
  Edge(int u, int v, int c, int f, int w); // Minimum cost maximum flow algorithm constructor
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

class FleetFunding {
public:
  int maxShips(int m, vector <int> k, vector <int> a, vector <int> b) {
    int total = 0;
    for(int i = 0; i < k.size(); i++) {
      total += k[i];
    }
    int l = 0, r = total / m;
    while(l != r) {
      int mid = ((l + r) >> 1) + 1;
      EdmondsKarp flow;
      flow.init(m + k.size() + 2);
      int s = 0, t = 1;
      for(int i = 0; i < k.size(); i++) {
	flow.addEdge(s, 2 + i, k[i]);
      }
      for(int i = 0; i < k.size(); i++) {
	for(int j = a[i]; j <= b[i]; j++) {
	  flow.addEdge(2 + i, j + 2 + k.size(), k[i]);
	}
      }
      for(int i = 3 + k.size(); i <= 2 + k.size() + m; i++) {
	flow.addEdge(i, t, mid);
      }
      int ans = flow.maxFlow(s, t);
      if(ans == mid * m) {
	l = mid;
      } else {
	r = mid - 1;
      }
    }
    return l;
  }
};

Edge::Edge(int u, int v, int c, int f) : from(u), to(v), cap(c), flow(f) {}
Edge::Edge(int u, int v, int c, int f, int w) : from(u), to(v), cap(c), flow(f), cost(w) {}

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
    a[s] = inf;
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

// @begin_tests
void _run_test(int m, vector< int > k, vector< int > a, vector< int > b, int res_expected, int test_no) {
int tc_res = (new FleetFunding)->maxShips(m, k, a, b);
if (tc_res == res_expected)
cout << "--- test " << test_no << ": ok ---" << endl;
else {
cout << "--- test " << test_no << ": failed ---" << endl;
cout << "expected: ";
cout << res_expected;
cout << endl << "got: ";
cout << tc_res;
cout << endl;
}
}
int main() {
int m;
vector< int > k;
vector< int > a;
vector< int > b;
int res_expected;
m = 3;
{int tmpa[] = {2, 2, 2};
k.assign(tmpa, tmpa + 3);}
{int tmpa[] = {1, 2, 1};
a.assign(tmpa, tmpa + 3);}
{int tmpa[] = {3, 3, 2};
b.assign(tmpa, tmpa + 3);}
res_expected = 2;
_run_test(m, k, a, b, res_expected, 0);
m = 1;
{int tmpa[] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
k.assign(tmpa, tmpa + 10);}
{int tmpa[] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1};
a.assign(tmpa, tmpa + 10);}
{int tmpa[] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1};
b.assign(tmpa, tmpa + 10);}
res_expected = 55;
_run_test(m, k, a, b, res_expected, 1);
m = 10;
{int tmpa[] = {2, 4, 6, 8, 10, 1, 3, 5, 7, 9};
k.assign(tmpa, tmpa + 10);}
{int tmpa[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
a.assign(tmpa, tmpa + 10);}
{int tmpa[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
b.assign(tmpa, tmpa + 10);}
res_expected = 1;
_run_test(m, k, a, b, res_expected, 2);
m = 84457;
{int tmpa[] = {374778, 169109, 529984, 498638, 29462, 465769, 29285, 394948, 307944, 459189, 349316, 766627, 686851, 404285, 850199, 359378, 3014, 248257, 558856, 27393, 32370, 574862, 337134, 965567, 32223, 935678, 389898, 973497, 990575, 483190, 122899, 857994, 991217, 149619, 415870};
k.assign(tmpa, tmpa + 35);}
{int tmpa[] = {92, 4997, 11, 28545, 933, 210, 2, 124, 114, 4513, 32959, 1, 57, 17, 13, 133, 1843, 41851, 3, 9296, 9757, 28, 3, 769, 10, 11102, 683, 6173, 11821, 3982, 214, 2, 4304, 439, 1998};
a.assign(tmpa, tmpa + 35);}
{int tmpa[] = {81034, 54474, 70239, 79597, 47317, 82938, 83883, 74652, 84033, 84422, 84456, 84457, 81095, 83743, 79210, 84255, 84455, 45596, 84456, 82959, 67062, 80330, 44090, 84445, 84454, 84450, 45931, 77190, 83025, 83567, 83639, 84333, 83355, 70982, 84456};
b.assign(tmpa, tmpa + 35);}
res_expected = 186;
_run_test(m, k, a, b, res_expected, 3);
m = 2;
{int tmpa[] = {1000000, 1000000, 1000000, 1000000, 1000000};
k.assign(tmpa, tmpa + 5);}
{int tmpa[] = {1, 1, 1, 2, 2};
a.assign(tmpa, tmpa + 5);}
{int tmpa[] = {1, 1, 2, 2, 2};
b.assign(tmpa, tmpa + 5);}
res_expected = 2500000;
_run_test(m, k, a, b, res_expected, 4);
}
// @end_tests

// Born in Emacs
