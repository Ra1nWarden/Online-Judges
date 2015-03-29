#include <cstdio>
#include <algorithm>
#include <cstring>
#define MAXN 105
#define INF 2000000000

using namespace std;

int v[MAXN];
int kk, n;
int dp[MAXN][MAXN][(1 << 8)][9];
int num[1 << 8];

int main() {
  int kase = 1;
  
  memset(num, 0, sizeof num);
  for(int i = 0; i < (1 << 8); i++)
    for(int j = 0; j < 8; j++)
      if(((1 << j) & i) != 0)
	num[i]++;
  
  while(scanf("%d %d", &n, &kk) != EOF && (kk || n)) {
    int begin = 0;
    for(int i = 0; i < n; i++) {
      scanf("%d", &v[i]);
      v[i] -= 25;
      begin |= (1 << v[i]);
    }

 
    for(int i = 0; i <= n; i++)
      for(int j = 0; j <= kk; j++) 
	for(int k = 0; k < (1 << 8); k++) 
	  for(int s = 0; s <= 8; s++)
	    dp[i][j][k][s] = INF;
    
    dp[0][0][0][8] = 0;

    for(int i = 0; i < n; i++) {
      for(int j = 0; j <= kk && j <= i; j++) {
	for(int k = 0; k < (1 << 8); k++) {
	  for(int s = 0; s <= 8; s++) {
	    if(dp[i][j][k][s] != INF) {
	      if(j < kk)
		dp[i+1][j+1][k][s] = min(dp[i+1][j+1][k][s], dp[i][j][k][s]);
	      if(s == v[i])
		dp[i+1][j][k][s] = min(dp[i+1][j][k][s], dp[i][j][k][s]);
	      else {
		dp[i+1][j][k | (1 << v[i])][v[i]] = min(dp[i+1][j][k | (1 << v[i])][v[i]], dp[i][j][k][s] + 1);
		// printf("%d %d %d %d\n", i+1, j, k | (1 << v[i]), v[i]);
		// printf("%d %d %d %d\n", i, j , k , s);
		// printf("%d vs %d\n", dp[i+1][j][k | (1 << v[i])][v[i]], dp[i][j][k][s] + 1);
	      }
	    }
	    
	  }
	}
      }
    }
    
    int ans = INF;
    for(int j = 0; j <=kk; j++) {
      for(int k = 0; k < (1 << 8); k++) {
	for(int s = 0; s <= 8; s++) {
	  ans = min(ans, dp[n][j][k][s] + num[begin^k]);
	}
      }
    }

    printf("Case %d: %d\n\n", kase++, ans);
  }
  return 0;
}
