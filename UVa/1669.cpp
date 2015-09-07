#include <stack>
#include <vector>
#include <cstdio>
#include <map>
#define MAXN 100010

using namespace std;

struct Edge {
  int u, v, w;
};

Edge edges[MAXN];
vector<int> adjList[MAXN];
int n;
typedef pair<int, int> Key;
map<Key, int> dp;

int f(int u, int fa) {
  Key k = make_pair(u, fa);
  if(dp.count(k))
    return dp[k];
  int ans = 1;
  for(int i = 0; i < adjList[u].size(); i++) {
    Edge& e = edges[adjList[u][i]];
    int v = e.u == u ? e.v : e.u;
    if(v == fa)
      continue;
    ans += f(v, u);
  }
  return dp[k] = ans;
}

int main() {
  int tc;
  scanf("%d", &tc);
  for(int kase = 1; kase <= tc; kase++) {
    dp.clear();
    scanf("%d", &n);
    for(int i = 1; i <= n; i++)
      adjList[i].clear();
    for(int i = 0; i < n - 1; i++) {
      scanf("%d%d%d", &edges[i].u, &edges[i].v, &edges[i].w);
      adjList[edges[i].u].push_back(i);
      adjList[edges[i].v].push_back(i);
    }
    long long ans = 0;
    for(int i = 0; i < n - 1; i++) {
      ans += 2 * 1LL * edges[i].w * min(f(edges[i].u, edges[i].v), n - f(edges[i].u, edges[i].v));
    }
    printf("Case #%d: %lld\n", kase, ans);
  }
  return 0;
}
