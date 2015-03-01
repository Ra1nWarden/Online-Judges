#include <cstdio>
#include <vector>
#include <cstring>
#define MAXN 105
#define MAXV 205
#define INF 2e9

using namespace std;

vector<int> adjList[MAXN];
int n, m;
int v[MAXV];
int vi;
int dp[MAXV][MAXN];

int f(int l, int node) {
  if(dp[l][node] != -1)
    return dp[l][node];
  if(l == 1) {
    return dp[l][node] = v[0] == node ? 0 : 1;
  }
  int res = f(l-1, node);
  for(int i = 0; i < adjList[node].size(); i++) {
    res = min(res, f(l-1, adjList[node][i]));
  }
  if(node != v[l-1])
    res++;
  return dp[l][node] = res;
}

int main() {
  int tc;
  scanf("%d", &tc);
  while(tc--) {
    scanf("%d %d", &n, &m);
    for(int i= 0; i < n; i++)
      adjList[i].clear();
    for(int i =0; i < m; i++) {
      int a, b;
      scanf("%d %d", &a, &b);
      adjList[a].push_back(b);
      adjList[b].push_back(a);
    }
    scanf("%d", &vi);
    for(int i= 0; i < vi; i++)
      scanf("%d", &v[i]);
    int res = INF;
    memset(dp, -1, sizeof dp);
    for(int i = 1; i <= n; i++)
      res = min(res, f(vi, i));
    printf("%d\n", res);
  }
  return 0;
}
