#include <cstdio>
#include <vector>
#include <cstring>
#include <stack>
#include <utility>

using namespace std;

const int maxn = 100000;
int n, m, t;
int v[maxn+5];
vector<int> adjMat[maxn+5];
vector<int> parent[maxn+5];
int vis[maxn+5];
int sorted[maxn+5];

void dfs(int u) {
  vis[u] = 1;
  for(int i = 0; i < adjMat[u].size(); i++) {
    int uu = adjMat[u][i];
    if(vis[uu] != -1) {
      continue;
    }
    dfs(uu);
  }
  sorted[--t] = u;
}

void toposort() {
  t = n;
  for(int i = 0; i < n; i++) {
    if(vis[i] == -1) {
      dfs(i);
    }
  }
}

int main() {
  scanf("%d%d", &n, &m);
  for(int i = 0; i < n; i++)
    scanf("%d", &v[i]);
  while(m--) {
    int u, v;
    scanf("%d%d", &u, &v);
    adjMat[v].push_back(u);
    parent[u].push_back(v);
  }

  int ans = 0;
  memset(vis, -1, sizeof vis);

  toposort();

  memset(vis, -1, sizeof vis);
  for(int i = 0; i < n; i++) {
    int u = sorted[i];
    vis[u] = v[u];
    for(int j = 0; j < parent[u].size(); j++) {
      int uu = parent[u][j];
      if(v[uu] == v[u]) {
	vis[u] = max(vis[u], vis[uu]);
      } else if(v[uu]) {
	vis[u] = max(vis[u], vis[uu]);
      } else {
	vis[u] = max(vis[u], vis[uu] + 1);
      }
    }
    //printf("vis[%d]=%d\n", u, vis[u]);
    ans = max(ans, vis[u]);
  }

  printf("%d\n", ans);

  return 0;
}
