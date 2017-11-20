#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

const int maxn = 100;
const int inf = 2000000000;
int dp[maxn+5][maxn+5];
int n;
int sum[maxn+5];

int calc(int i, int j) {
  return (sum[j] - sum[i-1] + 100) % 100;
}

int main() {
  while(scanf("%d", &n) != EOF) {
    sum[0] = 0;
    int num;
    for(int i = 1; i <= n; i++) {
      scanf("%d", &num);
      sum[i] = (sum[i-1] + num) % 100;
    }
    for(int i = 1; i + 1 <= n; i++) {
      dp[i][i+1] = calc(i, i) * calc(i+1, i+1);
    }
    for(int len = 2; len < n; len++) {
      for(int i = 1; i + len <= n; i++) {
	dp[i][i+len] = inf;
	for(int j = i; j < i + len; j++) {
	  dp[i][i+len] = min(dp[i][i+len], dp[i][j] + dp[j+1][i+len] + (calc(i, j) * calc(j+1, i+len)));
	}
      }
    }
    printf("%d\n", dp[1][n]);
  }
  return 0;
}
