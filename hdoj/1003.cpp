#include <cstdio>
#define MAXN 100005

using namespace std;

int v[MAXN];
int dp[MAXN];
int lv[MAXN];
int n;

int main() {
  int tc;
  scanf("%d", &tc);
  for(int kase = 1; kase <= tc; kase++) {
    if(kase > 1)
      printf("\n");
    scanf("%d", &n);
    for(int i = 1; i <= n; i++)
      scanf("%d", &v[i]);
    int ans = v[1];
    int l = 1;
    int r = 1;
    dp[1] = v[1];
    lv[1] = 1;
    for(int i = 2; i <= n; i++) {
      if(dp[i-1] + v[i] >= v[i]) {
	dp[i] = dp[i-1] + v[i];
	lv[i] = lv[i-1];
      } else {
	dp[i] = v[i];
	lv[i] = i;
      }
      if(dp[i] > ans) {
	ans = dp[i];
	l = lv[i];
	r = i;
      }
    }
    printf("Case %d:\n%d %d %d\n", kase, ans, l, r);
  }
  return 0;
}
