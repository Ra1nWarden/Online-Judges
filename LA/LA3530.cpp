#include <cstdio>
#include <cstring>
#include <algorithm>
#define MAXN 505

using namespace std;

int v[MAXN][MAXN][MAXN];
int dp[MAXN][MAXN];
int n, m;

int f(int a, int b) {
  if(dp[a][b] != -1)
    return dp[a][b];
  if(a == 0 || b == 0)
    return dp[a][b] = 0;
  int hsum = f(a-1, b);
  for(int i = 0; i < b; i++)
    hsum += v[a-1][i][0];
  int vsum = f(a, b-1);
  for(int i = 0; i < a; i++)
    vsum += v[i][b-1][1];
  return dp[a][b] = max(vsum, hsum);
}

int main() {
  while(scanf("%d %d", &n, &m) != EOF && (n || m)) {
    for(int i = 0; i < 2; i++) {
      for(int j = 0; j < n; j++) {
	for(int k = 0; k < m; k++) {
	  scanf("%d", &v[j][k][i]);
	}
      }
    }
    memset(dp, -1, sizeof dp);
    printf("%d\n", f(n, m));
  }
  return 0;
}
