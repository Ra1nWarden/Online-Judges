#include <cstdio>
#include <algorithm>
#define MAXN 100005

using namespace std;

int dp[MAXN][3]; // 0 stay 1 left 2 right
int n;
int v[MAXN];
int h[MAXN];

int main() {
  scanf("%d", &n);
  for(int i = 0; i < n; i++)
    scanf("%d %d", &v[i], &h[i]);
  dp[0][0] = 0;
  dp[0][1] = 1;
  dp[0][2] = 1;
  for(int i = 1; i < n; i++) {
    dp[i][0] = max(dp[i-1][0], dp[i-1][1]);
    if(h[i-1] < v[i] - v[i-1])
      dp[i][0] = max(dp[i][0], dp[i-1][2]);
    dp[i][1] = 0;
    if(h[i] < v[i] - v[i-1])
      dp[i][1] = max(dp[i-1][0], dp[i-1][1]) + 1;
    if(h[i] + h[i-1] < v[i] - v[i-1])
      dp[i][1] = max(dp[i][1], dp[i-1][2] + 1);
    dp[i][2] = max(dp[i-1][1], dp[i-1][0]) + 1;
    if(h[i-1] < v[i] - v[i-1])
      dp[i][2] = max(dp[i][2], dp[i-1][2] + 1);
    //printf("i=%d dp[i][0] = %d dp[i][1] = %d dp[i][2] = %d\n", i, dp[i][0], dp[i][1], dp[i][2]);
  }
  printf("%d\n", max(max(dp[n-1][0], dp[n-1][1]), dp[n-1][2]));
  return 0;
}
