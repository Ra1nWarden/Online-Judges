#include <cstdio>
#include <vector>
#include <cstring>
#define MAXN 10005
#define INF 2000000000

using namespace std;

int n, c1, c2;
int a, b;
vector<int> adjList[MAXN];
int dp[MAXN][3][4];
// dp[u][i][j]
// at node u
// put i
// j=0 : parent edge not connected
// j=1 : parent edge connected
// j=2 : parent and children edge connected
// j=3 : parent and children/grandchildren edge connecteed

int f(int root, int parent, int device, int mode) {
  if(dp[root][device][mode] != -1)
    return dp[root][device][mode];
  int ans = 0;
  if(mode == 0) {
    ans = INF;
  } else {
    for(int i = 0; i < adjList[root].size(); i++) {
      int u = adjList[root][i];
      if(u == parent)
	continue;
      ans += min(min(f(u, root, 0, mode-1), f(u, root, 1, 2)), f(u, root, 2, 3));
    }
  }
  int tmp = 0;
  for(int i = 0; i < adjList[root].size(); i++) {
    int u = adjList[root][i];
    if(u == parent)
      continue;
    tmp += min(min(f(u, root, 0, 1), f(u, root, 1, 2)), f(u, root, 2, 3));
  }
  for(int i = 0; i < adjList[root].size(); i++) {
    int u = adjList[root][i];
    if(u == parent)
      continue;
    ans = min(ans, tmp - min(min(f(u, root, 0, 1), f(u, root, 1, 2)), f(u, root, 2, 3)) + f(u, root, 2, 3));
  }
  if(device == 1)
    ans += c1;
  if(device == 2)
    ans += c2;
  return dp[root][device][mode] = ans;
}

int main() {
  while(scanf("%d %d %d", &n, &c1, &c2) != EOF && (n || c1 || c2)) {
    for(int i = 1; i <= n; i++)
      adjList[i].clear();
    for(int i =0 ; i < n - 1; i++) {
      scanf("%d %d", &a, &b);
      adjList[a].push_back(b);
      adjList[b].push_back(a);
    }
    memset(dp, -1, sizeof dp);
    printf("%d\n", min(min(f(1, 0, 0, 1), f(1, 0, 1, 2)), f(1, 0, 2, 3)));
  }
  return 0;
}
