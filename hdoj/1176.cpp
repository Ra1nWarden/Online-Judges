#include <cstring>
#include <cstdio>
#include <algorithm>
#define MAXN 15
#define MAXT 100005

using namespace std;

int dp[2][MAXN];
int cnt[MAXT][MAXN];
int n;
int max_t;

int main() {
  while(~scanf("%d", &n) && n) {
    memset(cnt, 0, sizeof cnt);
    max_t = 0;
    for(int i = 0; i < n; i++) {
      int x, t;
      scanf("%d%d", &x, &t);
      cnt[t][x]++;
      max_t = max(max_t, t);
    }
    memset(dp, -1, sizeof dp);
    dp[0][5] = 0;
    for(int t = 1; t <= max_t; t++) {
      for(int pos = 0; pos <= 10; pos++) {
	dp[t&1][pos] = dp[(t&1)^1][pos];
	if(pos > 0)
	  dp[t&1][pos] = max(dp[t&1][pos], dp[(t&1)^1][pos-1]);
	if(pos < 10)
	  dp[t&1][pos] = max(dp[t&1][pos], dp[(t&1)^1][pos+1]);
	dp[t&1][pos] += cnt[t][pos];
      }
    }
    int ans = 0;
    for(int pos = 0; pos <= 10; pos++) {
      ans = max(ans, dp[max_t&1][pos]);
    }
    printf("%d\n", ans);
  }
  return 0;
}
