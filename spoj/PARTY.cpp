#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int maxn = 500;

int dp[maxn+5];
int n, p;

int main() {
  while(scanf("%d%d", &n, &p) != EOF) {
    if(n == 0 && p == 0)
      break;
    memset(dp, 0, sizeof dp);
    int c, v;
    while(p--) {
      scanf("%d%d", &c, &v);
      for(int i = n; i >= c; i--) {
	dp[i] = max(dp[i], dp[i-c] + v);
      }
    }
    int an = 0, ap = 0;
    for(int i = 0; i <= n; i++) {
      if(dp[i] > ap) {
	ap = dp[i];
	an = i;
      }
    }
    printf("%d %d\n", an, ap);
  }
  return 0;
}
