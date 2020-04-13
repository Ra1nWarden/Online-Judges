#include <cstdio>
#include <vector>
#include <cstring>
#include <stack>

using namespace std;

const int maxn = 100000;
int n;
vector<int> adjMat[maxn+5];
int dp[maxn+5][2];
int fa[maxn+5];

int f(int u, int v) {
  if(dp[u][v] != -1)
    return dp[u][v];
  if(v == 0) {
    int ans = 0;
    for(int i = 0; i < adjMat[u].size(); i++) {
      if(fa[u] == adjMat[u][i])
	continue;
      int uu = adjMat[u][i];
      ans += f(uu, 1);
    }
    return dp[u][v] = ans;
  } else {
    int ans = 1;
    for(int i = 0; i < adjMat[u].size(); i++) {
      if(fa[u] == adjMat[u][i])
	continue;
      int uu = adjMat[u][i];
      ans += min(f(uu, 0), f(uu, 1));
    }
    return dp[u][v] = ans;
  }
}

int main() {
  scanf("%d", &n);
  for(int i = 0; i < n-1; i++) {
    int u, v;
    scanf("%d%d", &u, &v);
    adjMat[u].push_back(v);
    adjMat[v].push_back(u);
  }
  
  stack<int> s;
  memset(fa, -1, sizeof fa);
  fa[1] = 0;
  s.push(1);
  while(!s.empty()) {
    int u = s.top();
    s.pop();
    for(int i = 0; i < adjMat[u].size(); i++) {
      int v = adjMat[u][i];
      if(fa[v] != -1)
	continue;
      fa[v] = u;
      s.push(v);
    }
  }
  
  memset(dp, -1, sizeof dp);
  printf("%d\n", min(f(1, 0), f(1, 1)));
  return 0;
}
