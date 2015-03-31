#include <cstdio>
#include <cstring>
#include <algorithm>
#define MAXN 55
#define MAXT 205
#define INF 2000000000

using namespace std;

int n, t;
bool has_train[MAXT][MAXN][2];
int time[MAXT];
int dp[MAXT][MAXN];

int main() {
  int kase = 1;
  while(scanf("%d", &n) != EOF && n) {
    memset(has_train, false, sizeof has_train);
    scanf("%d", &t);
    for(int i = 0; i < n-1; i++)
      scanf("%d", &time[i]);
    int m1;
    scanf("%d", &m1);
    int m;
    while(m1--) {
      scanf("%d", &m);
      if(m <= t)
	has_train[m][1][0] = true;
      int total = m;
      for(int i = 1; i <= n - 1; i++) {
	total += time[i-1];
	if(total <= t)
	  has_train[total][i+1][0] = true;
      }
    }
    int m2;
    scanf("%d", &m2);
    while(m2--) {
      scanf("%d", &m);
      has_train[m][n][1] = true;
      int total = m;
      for(int i = 1; i <= n - 1; i++) {
	total += time[n-i-1];
	if(total <= t)
	  has_train[total][n-i][1] = true;
      }
    }
    
    for(int i = 1; i <= n - 1; i++)
      dp[t][i] = INF;
    
    dp[t][n] = 0;

    for(int i = t - 1; i >= 0; i--) {
      for(int j = 1; j <= n; j++) {
	dp[i][j] = dp[i+1][j] + 1;
	//printf("time=%d station=%d init=%d dp[%d][%d]=%d\n", i, j, dp[i][j], i+1, j, dp[i+1][j]);
	if(j > 1 && has_train[i][j][1] && i + time[j - 2] <= t) {
	  //printf("if one\n");
	  dp[i][j] = min(dp[i][j], dp[i + time[j - 2]][j-1]);
	}
	if(j < n && has_train[i][j][0] && i + time[j-1] <= t) {
	  //printf("if two\n");
	  dp[i][j] = min(dp[i][j], dp[i+time[j-1]][j+1]);
	}
	//printf("final val=%d\n", dp[i][j]);
      }
    }
    if(dp[0][1] < INF)
      printf("Case Number %d: %d\n", kase++, dp[0][1]);
    else
      printf("Case Number %d: impossible\n", kase++);

  }
  return 0;
}
