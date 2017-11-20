#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int maxn = 10000;
int dp[maxn+5];
int n;

int main() {
  int tc;
  scanf("%d", &tc);
  while(tc--) {
    int e, f;
    scanf("%d%d", &e, &f);
    n = f - e;
    int vn;
    scanf("%d", &vn);
    memset(dp, -1, sizeof dp);
    dp[0] = 0;
    int p, w;
    while(vn--) {
      scanf("%d%d", &p, &w);
      for(int i = 0; i + w <= n; i++) {
	if(dp[i] != -1) {
	  if(dp[i + w] == -1) {
	    dp[i + w] = dp[i] + p;
	  } else {
	    dp[i + w] = min(dp[i + w], dp[i] + p);
	  }
	}
      }
    }
    if(dp[n] == -1) {
      printf("This is impossible.\n");
    } else {
      printf("The minimum amount of money in the piggy-bank is %d.\n", dp[n]);
    }
  }
  return 0;
}
