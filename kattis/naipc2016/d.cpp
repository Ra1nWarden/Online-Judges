#include <cstdio>
#include <cstring>

using namespace std;

const int maxn = 2500;
bool visited[maxn+1][maxn+1];
int dpp[maxn+1][maxn+1];
int dps[maxn+1][maxn+1];
double dp[maxn+1][maxn+1];
int k, n;
int sv[maxn+1];
int pv[maxn+1];
int rv[maxn+1];
int sizev[maxn+1];

void f(int a, int b) {
  //printf("f(%d, %d)\n", a, b);
  if(visited[a][b]) {
    return;
  }
  if(b == 0) {
    visited[a][b] = true;
    dpp[a][b] = 0;
    dps[a][b] = 0;
    dp[a][b] = 0;
    return;
  }
  if(a == 0) {
    visited[a][b] = true;
    dpp[a][b] = 0;
    dps[a][b] = -1;
    dp[a][b] = -1;
    return;
  }
  int next_cnt = sizev[a];
  f(a-1, b);
  if(next_cnt > b) {
    //printf("%d %d current too much, return\n", a, b);
    visited[a][b] = true;
    dpp[a][b] = dpp[a-1][b];
    dps[a][b] = dps[a-1][b];
    dp[a][b] = dp[a-1][b];
    return;
  } else {
    f(a-1, b-sizev[a]);
    if(dp[a-1][b-sizev[a]] == -1) {
      //printf("%d %d removing current one leads to impossibility, return\n", a, b);
      dpp[a][b] = dpp[a-1][b];
      dps[a][b] = dps[a-1][b];
      dp[a][b] = dp[a-1][b];
    } else {
      int pp = dpp[a-1][b-sizev[a]] + pv[a];
      int ss = dps[a-1][b-sizev[a]] + sv[a];
      //printf("%d %d pp=%d ss=%d prev=%lf\n", a, b, pp, ss, dp[a-1][b]);
      if(dp[a-1][b] == -1 || pp * dps[a-1][b] >= ss * dpp[a-1][b]) {
	dpp[a][b] = pp;
	dps[a][b] = ss;
	dp[a][b] = (double) pp / ss;
	//printf("setting %d %d to %lf\n", pp, ss, dp[a][b]);
      } else {
	dpp[a][b] = dpp[a-1][b];
	dps[a][b] = dps[a-1][b];
	dp[a][b] = dp[a-1][b];
	//printf("not good setting %d %d to %lf\n", a, b, dp[a][b]);
      }
    }
    visited[a][b] = true;
    return;
  }
}

int main() {
  scanf("%d%d", &k, &n);
  for(int i = 1; i <= n; i++) {
    scanf("%d%d%d", &sv[i], &pv[i], &rv[i]);
    sizev[i] = 1;
  }
  for(int i = 1; i <= n; i++) {
    int dep = rv[i];
    while(dep != 0) {
      sv[i] += sv[dep];
      pv[i] += pv[dep];
      sizev[i]++;
      dep = rv[dep];
    }
  }
  memset(visited, false, sizeof visited);
  f(n, k);
  printf("%.3lf\n", (double) dpp[n][k] / dps[n][k]);
  return 0;
}
