#include <cstdio>
#include <cstring>

using namespace std;

const int maxn = 20;
const int maxmask = (1 << 20) - 1;
int n;

long long dp[maxn+5][maxmask+5];
int mat[maxn+5];

long long f(int m, int mask) {
  if(dp[m][mask] != -1) {
    return dp[m][mask];
  }
  if(m == 1) {
    return dp[m][mask] = (mask & mat[m]) ? 1LL : 0LL;
  }
  long long ans = 0;
  for(int i = 0; i < n; i++) {
    if((mat[m] & (1 << i)) && (mask & (1 << i))) {
      ans += f(m-1, mask ^ (1 << i));
    }
  }
  return dp[m][mask] = ans;
}

int main() {
  int tc;
  scanf("%d", &tc);
  while(tc--) {
    memset(dp, -1, sizeof dp);
    scanf("%d", &n);
    int b;
    for(int i = 1; i <= n; i++) {
      int curmask = 0;
      for(int j = 0; j < n; j++) {
	scanf("%d", &b);
	if(b) {
	  curmask |= (1 << j);
	}
      }
      mat[i] = curmask;
    }
    printf("%lld\n", f(n, (1 << n) - 1));
  }
  return 0;
}
