#include <cstdio>
#include <cstring>

using namespace std;

const int maxn = 100;
const int mod = 1000000007;
int c[maxn+5];
bool vis[maxn+5];
bool valids[maxn+5];
bool used[maxn+5];
int n, k;

inline int count(int x, int y) {
  printf("count(%d, %d)\n", x, y);
  int ans = 1;
  for(int i = 0; i < x; i++) {
    ans = (ans * 1LL * (k - 1)) % mod;
  }
  for(int i = 0; i < y; i++) {
    printf("ans=%d\n", ans);
    ans = (ans * 1LL * k) % mod;
  }
  return ans;
}

int main() {
  int tc;
  scanf("%d", &tc);
  while(tc--) {
    scanf("%d%d", &n, &k);
    for(int i = 0; i < n; i++)
      scanf("%d", &c[i]);
    memset(vis, false, sizeof vis);
    memset(valids, false, sizeof valids);
    for(int i = 0; i < n; i++) {
      if(vis[i])
	continue;
      vis[i] = true;
      valids[i] = true;
      int j = c[i];
      if(c[j] == i)
	vis[j] = true;
    }
    memset(vis, false, sizeof vis);
    int sub = 0;
    for(int i = 0; i < n; i++) {
      if(vis[i] || !valids[i])
	continue;
      vis[i] = true;
      int j = c[i];
      if(c[j] == i)
	vis[j] = true;
      memset(used, false, sizeof used);
      int cnt = 0;
      for(int j = 0; j < i; j++) {
	if(!valids[j] || j == c[i])
	  continue;
	if(j == c[i] || c[j] == i || c[j] == c[i]) {
	  if(!used[j]) {
	    cnt++;
	    used[j] = true;
	  }
	}
      }
      sub = (sub + (count(cnt, n-2-cnt) * 1LL * k) % mod) % mod;
      printf("i=%d sub=%d\n", i, sub);
    }
    int ans = (count(0, n) - sub);
    if(ans < 0)
      ans += mod;
    printf("%d\n", ans);
  }
  return 0;
}
