#include <cstdio>
#include <set>
#include <vector>
#include <cstring>
#include <queue>

using namespace std;

typedef pair<int, int> Edge;
const int maxn = 300000;
Edge edges[maxn+5];
int n, k, d;
vector<int> adjMat[maxn+5];
bool cut[maxn+5];
struct Node {
  int node, prev;
};

int main() {
  scanf("%d%d%d", &n, &k, &d);
  int v;
  queue<Node> q;
  set<int> vis;
  for(int i = 0; i < k; i++) {
    scanf("%d", &v);
    q.push(Node {v, 0});
  }
  for(int i = 1; i < n; i++) {
    scanf("%d %d", &edges[i].first, &edges[i].second);
    adjMat[edges[i].first].push_back(i);
    adjMat[edges[i].second].push_back(i);
  }
  set<int> ans;
  while(!q.empty()) {
    Node u = q.front();
    q.pop();
    if(vis.count(u.node)) {
      continue;
    }
    vis.insert(u.node);
    for(int i = 0; i < adjMat[u.node].size(); i++) {
      int e = adjMat[u.node][i];
      int uu = edges[e].first == u.node ? edges[e].second : edges[e].first;
      if(uu == u.prev) {
	continue;
      }
      if(vis.count(uu)) {
	ans.insert(e);
      } else {
	q.push(Node {uu, u.node});
      }
    }
  }
  printf("%d\n", ans.size());
  bool start = true;
  for(set<int>::iterator itr = ans.begin(); itr != ans.end(); itr++) {
    if(!start)
      printf(" ");
    printf("%d", *itr);
    start = false;
  }
  printf("\n");
  return 0;
}
