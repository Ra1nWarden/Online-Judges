#include <cstdio>
#include <cmath>
#include <algorithm>
#define MAXN 105
#define INF (1LL << 60)

using namespace std;

typedef long long LL;

LL v[MAXN], x[MAXN * MAXN * 2], dp[2][MAXN * MAXN * 2];
int n;
LL d;

int main() {
  int tc;
  scanf("%d", &tc);
  while(tc--) {
    scanf("%d %d", &n, &d);
    for(int i = 0; i < n; i++)
      scanf("%lld", &v[i]);
    if(abs(v[0] - v[n - 1]) > (n - 1) * d) {
      printf("impossible\n");
      continue;
    }
    int nx = 0;
    for(int i = 0; i < n; i++) {
      for(int j = -n+1; j <= n-1; j++)
	x[nx++] = v[i] + j * d;
    }
    sort(x, x+nx);
    nx = unique(x, x+nx) - x;

    int t = 0;
    for(int i = 0; i < nx; i++) {
      dp[t][i] = INF;
      if(x[i] == v[0])
	dp[t][i] = 0;
    }
    for(int i = 1; i < n; i++) {
      int k = 0;
      for(int j  = 0; j < nx; j++) {
	while(k < nx && x[k] < x[j] - d)
	  k++;
	while(k+1 < nx && x[k+1] <= x[j] + d && dp[t][k+1] <= dp[t][k])
	  k++;
	if(dp[t][k] == INF)
	  dp[t^1][j] = INF;
	else
	  dp[t^1][j] = dp[t][k] + abs(x[j] - v[i]);
      }
      t ^= 1;
    }
    for(int i = 0; i < nx; i++)
      if(x[i] == v[n-1])
	printf("%lld\n", dp[t][i]);
  }
  return 0;
}
