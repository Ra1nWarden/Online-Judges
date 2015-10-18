#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

const int maxn = 100;
int v[maxn+5];
int n, t;
const int maxl = 300;
int dp[maxl+5];
int di;
int cnt[maxl+5];
int prefix[maxl+5];

int main() {
  scanf("%d%d", &n, &t);
  di = 0;
  memset(cnt, 0, sizeof cnt);
  memset(prefix, 0, sizeof prefix);
  for(int i = 0; i < n; i++) {
    scanf("%d", &v[i]);
    cnt[v[i]]++;
    int idx = upper_bound(dp, dp+di, v[i]) - dp;
    dp[idx] = v[i];
    if(idx == di) {
      di++;
    }
    prefix[v[i]] = max(prefix[v[i]], idx + 1);
  }
  if(t == 1) {
    printf("%d\n", di);
  } else {
    int ans = 0;
    for(int i = 1; i <= maxl; i++) {
      if(prefix[i] == 0) {
	continue;
      }
      int sub = prefix[i] + (t - 2) * cnt[i];
      di = 0;
      for(int j = 0; j < n; j++) {
	if(v[j] >= i) {
	  int idx = upper_bound(dp, dp+di, v[j]) - dp;
	  dp[idx] = v[j];
	  if(idx == di) {
	    di++;
	  }
	}
      }
      sub += di;
      ans = max(ans, sub);
    }
    printf("%d\n", ans);
  }
  return 0;
}
