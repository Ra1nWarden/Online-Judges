#include <cstdio>
#include <cstring>
#include <algorithm>
#define MAXN 35

using namespace std;

int v[MAXN][3];
int dp[MAXN][3];
int n;

int f(int i, int j) {
  //printf("f(%d, %d)\n", i, j);
  if(dp[i][j] != -1)
    return dp[i][j];
  int smaller, larger;
  if(j == 0) {
    smaller = min(v[i][1], v[i][2]);
    larger = max(v[i][1], v[i][2]);
  } else if(j == 1) {
    smaller = min(v[i][0], v[i][2]);
    larger = max(v[i][0], v[i][2]);
  } else {
    smaller = min(v[i][1], v[i][0]);
    larger = max(v[i][1], v[i][0]);
  }
  int ans = v[i][j];
  for(int ii = 0; ii < n; ii++) {
    for(int jj = 0; jj < 3; jj++) {
      int ss, ll;
      if(jj == 0) {
	ss = min(v[ii][1], v[ii][2]);
	ll = max(v[ii][1], v[ii][2]);
      } else if(jj == 1) {
	ss = min(v[ii][0], v[ii][2]);
	ll = max(v[ii][0], v[ii][2]);
      } else {
	ss = min(v[ii][1], v[ii][0]);
	ll = max(v[ii][1], v[ii][0]);
      }
      if(smaller > ss && larger > ll) {
	ans = max(ans, v[i][j] + f(ii, jj));
      }
    }
  }
  return dp[i][j] = ans;
}

int main() {
  int kase = 1;
  while(scanf("%d", &n) != EOF && n) {
    for(int i = 0; i < n; i++) {
      scanf("%d %d %d", &v[i][0], &v[i][1], &v[i][2]);
    }
    memset(dp, -1, sizeof dp);
    int ans = 0;
    for(int i = 0; i < n; i++) {
      for(int j = 0; j < 3; j++)
	ans = max(ans, f(i, j));
    }
    printf("Case %d: maximum height = %d\n", kase++, ans);
  }
  return 0;
}
