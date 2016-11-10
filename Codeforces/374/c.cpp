#include <cstdio>
#include <stack>
#include <cstring>
#include <vector>

using namespace std;

const int maxn = 5000, maxm = 5000;

struct Edge {
  int u, v, t;
};

Edge edges[maxm+5];
vector<int> adjMat[maxn+5];
int dp[maxn+5][maxn+5];
vector<int> ans;
int n, m, t;

void dfs(int cur, int len, vector<int>& path) {
  if(len > t)
    return;
  if(cur == n) {
    if(path.size() > ans.size()) {
      ans = path;
    }
    return;
  }
  if(dp[cur][path.size()] != -1 && len >= dp[cur][path.size()]) {
    return;
  }
  dp[cur][path.size()] = len;
  for(int i = 0; i < adjMat[cur].size(); i++) {
    Edge& e = edges[adjMat[cur][i]];
    path.push_back(e.v);
    dfs(e.v, len + e.t, path);
    path.pop_back();
  }
}

int main() {
  scanf("%d%d%d", &n, &m, &t);
  for(int i = 0; i < m; i++) {
    int u, v, l;
    scanf("%d%d%d", &u, &v, &l);
    edges[i] = Edge{u, v, l};
    adjMat[u].push_back(i);
  }
  vector<int> v;
  v.push_back(1);
  memset(dp, -1, sizeof dp);
  dfs(1, 0, v);
  printf("%d\n", ans.size());
  for(int i = 0; i < ans.size(); i++) {
    if(i)
      printf(" ");
    printf("%d", ans[i]);
  }
  printf("\n");
  return 0;
}
