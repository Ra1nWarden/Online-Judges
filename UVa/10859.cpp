#include <cstdio>
#include <vector>
#include <cstring>
#define MAXN 1005
#define M 2000

using namespace std;

vector<int> adj[MAXN];
int dp[MAXN][2], n, m;

int fdp(int i, int j, int f) {
  if(dp[i][j] != -1)
    return dp[i][j];
  dp[i][j] = M;
  for(int k = 0; k < adj[i].size(); k++) {
    if(adj[i][k] != f)
      dp[i][j] += fdp(adj[i][k], 1, i);
  }
  if(j == 0 && f >= 0)
    dp[i][j]++;
  
  if(j || f < 0) {
    int sum = 0;
    for(int k = 0; k < adj[i].size(); k++) {
      if(adj[i][k] != f)
	sum += fdp(adj[i][k], 0, i);
    }
    if(f >= 0)
      sum++;
    dp[i][j] = min(dp[i][j], sum);
  }
  return dp[i][j];
}

int main() {
  int tc;
  scanf("%d", &tc);
  while(tc--) {
    scanf("%d %d", &n, &m);
    memset(dp, -1, sizeof dp);
    for(int i = 0 ; i < MAXN; i++)
      adj[i].clear();
    for(int i = 0; i < m; i++) {
      int a, b;
      scanf("%d %d", &a, &b);
      adj[a].push_back(b);
      adj[b].push_back(a);
    }
    int ans = 0;
    for(int i = 0; i < n; i++) {
      if(dp[i][0] == -1)
	ans += fdp(i, 0, -1);
    }
    printf("%d %d %d\n", ans/M,  m - ans % M,  ans % M);
  }

  return 0;
}
