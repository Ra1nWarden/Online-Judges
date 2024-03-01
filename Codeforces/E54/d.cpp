#include <cstdio>
#include <queue>
#include <vector>
#include <cstring>

using namespace std;

const int maxm = 300000;
int n, m, k;
int xv[maxm+5], yv[maxm+5], wv[maxm+5];
vector<int> adjMat[maxm+5];
bool vis[maxm+5];
vector<int> ans;

struct Node {
  long long len;
  int v;
  int e;
  Node(long long len, int v, int e) : len(len), v(v), e(e) {}
  bool operator<(const Node& rhs) const {
    return rhs.len < len;
  }
};

int main() {
  scanf("%d %d %d", &n, &m, &k);
  for(int i = 1; i <= m; i++) {
    scanf("%d %d %d", &xv[i], &yv[i], &wv[i]);
    adjMat[xv[i]].push_back(i);
    adjMat[yv[i]].push_back(i);
  }
  priority_queue<Node> pq;
  pq.push(Node(0, 1, 0));
  memset(vis, false, sizeof vis);
  while(!pq.empty() && ans.size() < k) {
    Node u = pq.top();
    pq.pop();
    if(vis[u.v]) {
      continue;
    }
    vis[u.v] = true;
    if(u.e != 0) {
      ans.push_back(u.e);
    }
    for(int i = 0; i < adjMat[u.v].size(); i++) {
      int ei = adjMat[u.v][i];
      int v = xv[ei] == u.v ? yv[ei] : xv[ei];
      if(vis[v])
	continue;
      pq.push(Node(u.len + wv[ei], v, ei));
    }
  }
  printf("%d\n", ans.size());
  for(int i = 0; i < ans.size(); i++) {
    if(i)
      printf(" ");
    printf("%d", ans[i]);
  }
  printf("\n");
  return 0;
}
