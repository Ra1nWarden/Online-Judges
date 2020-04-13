#include <cstdio>
#include <queue>
#include <functional>
#include <vector>
#include <cstring>

using namespace std;

const int maxn = 100000;
const int maxm = 100000;
const int inf = 1e9;
int n, m, start, end;

struct Edge {
  int a, b, len;
};

Edge edges[maxm+5];
vector<int> adjMat[maxn+5];

struct Node {
  int idx, dist;
  bool operator>(const Node& rhs) const {
    return dist > rhs.dist;
  }
  Node(int a, int b) : idx(a), dist(b) {} 
};

int dists[maxn+5];

int dijkstra() {
  for(int i = 1; i <= n; i++)
    dists[i] = inf;
  priority_queue<Node, vector<Node>, greater<Node> > pq;
  pq.push(Node(start, 0));
  while(!pq.empty()) {
    Node u = pq.top();
    pq.pop();
    if(dists[u.idx] <= u.dist)
      continue;
    for(int i = 0; i < adjMat[u.idx].size(); i++) {
      int ei = adjMat[u.idx][i];
      int v = edges[ei].a == u.idx ? edges[ei].b : edges[ei].a;
      if(u.dist + edges[ei].len < dists[v])
	pq.push(Node(v, u.dist + edges[ei].len));
    }
    dists[u.idx] = u.dist;
    if(u.idx == end)
      return u.dist;
  }
  return dists[end];
}

int main() {
  int tc;
  scanf("%d", &tc);
  while(tc--) {
    scanf("%d%d%d%d", &n, &m, &start, &end);
    for(int i = 1; i <= n; i++)
      adjMat[i].clear();
    for(int i = 0; i < m; i++) {
      scanf("%d%d%d", &edges[i].a, &edges[i].b, &edges[i].len);
      adjMat[edges[i].a].push_back(i);
      adjMat[edges[i].b].push_back(i);
    }
    int ans = dijkstra();
    if(ans == inf) {
      printf("NONE\n");
    } else {
      printf("%d\n", ans);
    }
  }
  return 0;
}
