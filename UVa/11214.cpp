#include <cstdio>
#include <vector>
#include <cmath>
#include <cstring>
#define MAXN 11

using namespace std;

char board[MAXN][MAXN];
bool vis[MAXN*2][4];
int m, n, ans, total;

bool check() {
  for(int i = 0; i < m; i++) {
    for(int j = 0; j < n; j++) {
      if(board[i][j] == 'X') {
	if(!vis[i][0] && !vis[j][1] && !vis[i+j][2] && !vis[i-j+n][3])
	  return false;
      }
    }
  }
  return true;
}

bool dfs(int i, int j, int cnt, int maxd) {
  if(cnt == maxd || i == m) {
    return check();
  }
  int ii = i;
  int jj = j;
  if(j == n-1) {
    jj = 0;
    ii++;
  } else {
    jj++;
  }
  bool tmpa = vis[i][0], tmpb = vis[j][1], tmpc = vis[i+j][2], tmpd = vis[i-j+n][3];
  vis[i][0] = vis[j][1] = vis[j+i][2] = vis[i-j+n][3] = true;
  if(dfs(ii, jj, cnt+1, maxd))
    return true;
  vis[i][0] = tmpa;
  vis[j][1] = tmpb;
  vis[i+j][2] = tmpc;
  vis[i-j+n][3] = tmpd;
  return dfs(ii, jj, cnt, maxd);
}

int main() {
  int kase = 1;
  while(scanf("%d", &m) != EOF && m) {
    scanf("%d\n", &n);
    total = 0;
    memset(vis, false, sizeof vis);
    for(int i = 0; i < m; i++) {
      scanf("%s\n", board[i]);
    }
    for(int i = 1; i <= min(m, n); i++) {
      if(dfs(0, 0, 0, i)) {
	printf("Case %d: %d\n", kase++, i);
	break;
      }
    }
  }
  return 0;
}
