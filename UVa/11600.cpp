#include <cstdio>
#include <cstring>
#include <map>
#define MAXN 35

using namespace std;

int n, m;
bool adjMat[MAXN][MAXN];
bool vis[MAXN];
int pc;
int pn[MAXN];

typedef pair<int, int> II;

map<II, double> dp;

void dfs(int u) {
  vis[u] = true;
  pn[pc]++;
  for(int i = 1; i <= n; i++) {
    if(adjMat[u][i] && !vis[i])
      dfs(i);
  }
}

double f(int mask, int pos) {
  II key = make_pair(mask, pos);
  if(dp.count(key))
    return dp[key];
  if(mask == (1 << pc) - 1)
    return dp[key] = 0.0;
  int notvis = 0;
  for(int i = 0; i < pc; i++) {
    if(i+1 == pos)
      continue;
    if(((1 << i) & mask) != 0)
      continue;
    else {
      //printf("else branch\n");
      notvis += pn[i];
    }
  }
  double ans = (double) (n-1) / notvis;
  //printf("ans is %.4f\n", ans);
  for(int i = 0; i < pc; i++) {
    if(!((1 << i) & mask)) {
      ans += f(mask | (1 << i), i+1) * pn[i] / notvis;
    }
  }
  //printf("dp(%d %d) = %.6f\n", mask, pos, ans);
  return dp[key] = ans;
}

int main() {
  int tc;
  scanf("%d", &tc);
  for(int kase = 1; kase <= tc; kase++) {
    memset(adjMat, false, sizeof adjMat);
    dp.clear();
    scanf("%d %d", &n, &m);
    while(m--) {
      int a, b;
      scanf("%d %d", &a, &b);
      adjMat[a][b] = adjMat[b][a] = true;
    }
    memset(vis, false, sizeof vis);
    memset(pn, 0, sizeof pn);
    pc = 0;
    for(int i = 1; i <= n; i++) {
      if(!vis[i]) {
	dfs(i);
	pc++;
      }
    }
    printf("Case %d: %.6f\n", kase, f(1, 1));
  }
  return 0;
}
