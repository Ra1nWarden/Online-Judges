#include <cstdio>
#include <algorithm>

using namespace std;

const int maxn = 50000;
const int inf = 2000000000;
int v[maxn+5];
int dp[maxn+5];
int n;

int main() {
  int tc;
  scanf("%d", &tc);
  while(tc--) {
    scanf("%d", &n);
    for(int i = 1; i <= n; i++) {
      scanf("%d", &v[i]);
    }
    sort(v+1, v+1+n);
    n = unique(v+1, v+1+n) - (v + 1);
    dp[0] = 0;
    int _max = 0;
    for(int i = 1; i <= n; i++) {
      _max = max(_max, v[i] - dp[i-1]);
      dp[i] = _max;
    }
    printf("%d\n", dp[n]);
  }
  return 0;
}
