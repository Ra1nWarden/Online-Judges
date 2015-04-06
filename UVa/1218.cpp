#include <cstdio>
#include <vector>
#include <algorithm>
#include <cstring>
#define MAXN 10005

using namespace std;

vector<int> adjList[MAXN];
int n;
int dp[MAXN][3];

int f(int root, int mode, int parent) {
  if(dp[root][mode] != -1)
    return dp[root][mode];
  if(mode == 0) {
    int ans = 0;
    for(int i = 0; i < adjList[root].size(); i++) {
      if(adjList[root][i] == parent)
	continue;
      ans += f(adjList[root][i], 2, root);
    }
    return dp[root][mode] = ans;
  } else if(mode == 1) {
    int ans = 1;
    for(int i = 0; i < adjList[root].size(); i++) {
      if(adjList[root][i] == parent)
	continue;
      ans += min(f(adjList[root][i], 1, root), f(adjList[root][i], 0, root));
    }
    return dp[root][mode] = ans;
  } else {
    // mode == 2
    int ans = n;
    for(int i = 0; i < adjList[root].size(); i++) {
      if(adjList[root][i] == parent)
	continue;
      ans = min(ans, f(root, 0, parent) - f(adjList[root][i], 2, root)  + f(adjList[root][i], 1, root));
    }
    return dp[root][mode] = ans;
  }
}

int main() {
  while(scanf("%d", &n) != EOF) {
    for(int i = 1; i <= n; i++)
      adjList[i].clear();
    for(int i = 0; i < n - 1; i++) {
      int a, b;
      scanf("%d %d", &a, &b);
      adjList[a].push_back(b);
      adjList[b].push_back(a);
    }
    memset(dp, -1, sizeof dp);
    if(n == 1)
      printf("1\n");
    else
      printf("%d\n", min(f(1, 2, -1), f(1, 1, -1)));
    int fin;
    scanf("%d", &fin);
    if(fin == -1)
      break;
  }
  return 0;
}
