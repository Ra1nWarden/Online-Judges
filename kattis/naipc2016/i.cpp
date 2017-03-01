#include <cstdio>
#include <map>
#include <vector>
#include <cstring>

using namespace std;

const int maxn = 200000;
map<int, vector<int> > m;
int parent[maxn+5];
int rank[maxn+5];
int ancestor[maxn+5];
bool visited[maxn+5];
int n;
long long ans;

int make_set(int i) {
  parent[i] = i;
  rank[i] = i;
  return 0;
}

int find_set(int i) {
  return parent[i] == i ? i : parent[i] = find_set(i);
}

void union_set(int i, int j) {
  int ii = find_set(i);
  int jj = find_set(j);
  if(ii == jj)
    return;
  if(rank[ii] > rank[jj]) {
    parent[jj] = ii;
    rank[ii] += rank[jj];
  } else {
    parent[ii] = jj;
    rank[jj] += rank[ii];
  }
}

void lca(int u) {
  make_set(u);
  ancestor[u] = u;
  for(int i =0 ; i < m[u].size(); i++) {
    lca(m[u][i]);
    union_set(u, m[u][i]);
    ancestor[find_set(u)] = u;
  }
  visited[u] = true;
  for(int i = u + u; i <= n; i++) {
    if(visited[i]) {
      ans += depth[u] + depth[i] -  2 * depth[ancestor[find_set(i)]];
    }
  }
}

int main() {
  scanf("%d", &n);
  for(int i = 0; i < n - 1; i++) {
    int u, v;
    scanf("%d%d", &u, &v);
    m[u].push_back(v);
    m[v].push_back(u);
  }
  memset(visited, false, sizeof visited);
  ans = 0;
  lca(1);
  return 0;
}
