#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>
#include <cmath>

using namespace std;

const int maxn = 100000;
int depth[maxn+5];
int parent[maxn+5][20];
int level, n, q;
vector<int> adjMat[maxn+5];

void init() {
  queue<int> qq;
  qq.push(1);
  depth[1] = 0;
  while(!qq.empty()) {
    int u = qq.front();
    qq.pop();
    for(int i = 0; i < adjMat[u].size(); i++) {
      int v = adjMat[u][i];
      if(depth[v] != -1)
	continue;
      depth[v] = depth[u] + 1;
      qq.push(v);
      parent[v][0] = u;
    }
  }
  for(level = 0; (1 << level) <= n - 1; level++) {}
  level--;
  for(int i = 1; i <= level; i++) {
    for(int j = 2; j <= n; j++) {
      parent[j][i] = parent[parent[j][i-1]][i-1];
    }
  }
}

int lca(int a, int b) {
  if(depth[a] < depth[b])
    swap(a, b);
  int diff = depth[a] - depth[b];
  for(int i = 0; (1 << i) <= diff; i++) {
    if(diff & (1 << i)) {
      a = parent[a][i];
    }
  }

  if(a == b)
    return a;

  for(int i = level; i >= 0; i--) {
    if(parent[a][i] != parent[b][i]) {
      a = parent[a][i];
      b = parent[b][i];
    }
  }

  return parent[a][0];
}

int dist(int s, int t) {
  int u = lca(s, t);
  int ans = abs(depth[u] - depth[s]) + abs(depth[u] - depth[t]) + 1;
  return ans;
}

int calc(int s, int t, int f) {
  int ans = (dist(s, f) + dist(f, t) - dist(s, t) + 1) / 2;
  return ans;
}

int main() {
  scanf("%d%d", &n, &q);
  memset(parent, 0, sizeof parent);
  memset(depth, -1, sizeof depth);
  int j;
  for(int i = 2; i <= n; i++) {
    scanf("%d", &j);
    adjMat[i].push_back(j);
    adjMat[j].push_back(i);
  }
  init();
  int a, b, c;
  while(q--) {
    scanf("%d%d%d", &a, &b, &c);
    int ans = 0;
    ans = max(ans, calc(a, b, c));
    ans = max(ans, calc(a, c, b));
    ans = max(ans, calc(b, c, a));
    printf("%d\n", ans);
  }
  return 0;
}
