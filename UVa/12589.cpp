#include <cstring>
#include <cstdio>
#include <utility>
#include <algorithm>
#define MAXN 55
#define MAXH 2505

using namespace std;

int n, k;

typedef pair<int, int> Vec;

Vec v[MAXN];
int dp[2][MAXN][MAXH];

bool _cmp(const Vec& a, const Vec& b) {
  return a.second * b.first > b.second * a.first;
}

int main() {
  int tc;
  scanf("%d", &tc);
  int kase = 1;
  while(tc--) {
    scanf("%d%d", &n, &k);
    for(int i = 1; i <= n; i++) {
      scanf("%d%d", &v[i].first, &v[i].second);
    }
    sort(v+1, v+1+n, _cmp);
    memset(dp, -1, sizeof dp);
    dp[0][0][0] = dp[1][0][0] = 0;
    for(int i = 1; i <= n; i++) {
      for(int j = 1; j <= min(i, k); j++) {
	for(int h = 1; h <= 2500; h++) {
	  dp[i&1][j][h] = dp[(i&1)^1][j][h];
	  if(h >= v[i].second && dp[(i&1)^1][j-1][h-v[i].second] != -1)
	    dp[i&1][j][h] = max(dp[i&1][j][h], dp[(i&1)^1][j-1][h-v[i].second] + ((h - v[i].second) * 2 + v[i].second) * v[i].first);
	}
      }
    }
    int ans = 0;
    for(int h = 0; h <= 2500; h++) {
      ans = max(ans, dp[n&1][k][h]);
    }
    printf("Case %d: %d\n", kase++, ans);
  }
  return 0;
}
