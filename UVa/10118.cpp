#include <cstdio>
#include <cstring>
#include <algorithm>
#define MAXN 41

using namespace std;

int v[4][MAXN];
int n;
int dp[MAXN][MAXN][MAXN][MAXN];
int bitmask[MAXN][MAXN][MAXN][MAXN];

bool valid(int bitmask) {
  int cnt = 0;
  for(int i = 0; i < 20; i++) {
    if(((1 << i) & bitmask) != 0)
      cnt++;
    if(cnt >= 5)
      return false;
  }
  return true;
}

int f(int a, int b, int c, int d) {
  if(dp[a][b][c][d] != -1)
    return dp[a][b][c][d];
  int mask = bitmask[a][b][c][d];
  int ans = 0;
  if(valid(mask)) {
    if(a < n) {
      int color = v[0][a];
      bitmask[a+1][b][c][d] = mask ^ (1 << color);
      int newans = f(a+1, b, c, d);
      if((mask & (1 << color)) != 0)
	newans++;
      ans = max(ans, newans);
    }
    if(b < n) {
      int color = v[1][b];
      bitmask[a][b+1][c][d] = mask ^ (1 << color);
      int newans = f(a, b+1, c, d);
      if((mask & (1 << color)) != 0)
	newans++;
      ans = max(ans, newans);
    }
    if(c < n) {
      int color = v[2][c];
      bitmask[a][b][c+1][d] = mask ^ (1 << color);
      int newans = f(a, b, c+1, d);
      if((mask & (1 << color)) != 0)
	newans++;
      ans = max(ans, newans);
    }
    if(d < n) {
      int color = v[3][d];
      bitmask[a][b][c][d+1] = mask ^ (1 << color);
      int newans = f(a, b, c, d+1);
      if((mask & (1 << color)) != 0)
	newans++;
      ans = max(ans, newans);
    }
  }
  return dp[a][b][c][d] = ans;
}

int main() {
  while(scanf("%d", &n) != EOF && n) {
    for(int i = 0; i < n; i++)
      scanf("%d %d %d %d", &v[0][i], &v[1][i], &v[2][i], &v[3][i]);
    bitmask[0][0][0][0] = 0;
    memset(dp, -1, sizeof dp);
    printf("%d\n", f(0, 0, 0, 0));
  }
  return 0;
}
