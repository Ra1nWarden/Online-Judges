#include <cstdio>
#include <cstring>
#define MAXN 40

using namespace std;

long long dp[MAXN][MAXN];
int n;
char board[MAXN][MAXN];

int main() {
  while(~scanf("%d\n", &n) && n != -1) {
    for(int i = 0; i < n; i++) {
      scanf("%s", board[i]);
    }
    memset(dp, 0, sizeof dp);
    dp[0][0] = 1LL;
    for(int i = 0; i < n; i++) {
      for(int j = 0; j < n; j++) {
	if(dp[i][j] == 0)
	  continue;
	int num = board[i][j] - '0';
	if(num == 0)
	  continue;
	if(i+num < n) {
	  dp[i+num][j] += dp[i][j];
	}
	if(j+num < n) {
	  dp[i][j+num] += dp[i][j];
	}
      }
    }
    
    printf("%lld\n", dp[n-1][n-1]);
  }
  return 0;
}
