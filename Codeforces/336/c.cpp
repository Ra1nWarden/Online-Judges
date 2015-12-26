#include <cstdio>
#include <utility>
#include <algorithm>

using namespace std;

const int maxn = 100000;
typedef pair<int, int> Beacon;
Beacon v[maxn+1];
int dp[maxn+1];
int n;

int main() {
  scanf("%d", &n);
  for(int i = 0; i < n; i++)
    scanf("%d%d", &v[i].first, &v[i].second);
  sort(v, v+n);
  for(int i = 0; i < n; i++) {
    if(i == 0) {
      dp[i] = 0;
    } else {
      int next = v[i].first - v[i].second;
      int j = lower_bound(v, v+n, make_pair(next, -1)) - v;
      if(j < i) {
	dp[i] = i - j + (j > 0 ? dp[j - 1] : 0);
      } else {
	dp[i] = dp[i-1];
      }
    }
  }
  int ans = n;
  for(int i = 0; i < n; i++)
    ans = min(ans, dp[i] + n - 1 - i);
  printf("%d\n", ans);
  return 0;
}
