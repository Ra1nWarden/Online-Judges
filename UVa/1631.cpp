#include <cstdio>
#include <cstring>
#include <algorithm>
#define MAXL 1005
#define INF 2000000000

using namespace std;

char a[MAXL], b[MAXL];
int len;
int dp[MAXL][10][10];

int updist(char m, char n) {
  return n >= m ? n - m : (n - m) + 10;
}

int downdist(char m, char n) {
  return n <= m ? m - n : (m - n) + 10;
}

int main() {
  while(scanf("%s %s", a, b) != EOF) {
    len = strlen(a);
    for(int i = 0; i <= len; i++) {
      for(int j = 0; j < 10; j++) {
	for(int k = 0; k < 10; k++) {
	  dp[i][j][k] = INF;
	}
      }
    }
    dp[0][0][0] = 0;
    for(int i = 1; i <= len; i++) {
      for(int x = 0; x < 10; x++) {
	if(i == 1 && x > 0)
	  break;
	for(int y = 0; y < 10; y++) {
	  int d1 = updist('0' + y, b[i-1]);
	  int d2 = downdist('0' + y, b[i-1]);
	  if(i == 1) {
	    dp[i][x][y] = min(dp[i][x][y], min(d1, d2));
	  } else if(i == 2) {
	    for(int j = x; j <= x+d1; j++)
	      dp[i][x][y] = min(dp[i][x][y], dp[i-1][0][j%10]+d1);
	    for(int j = x; j >= x-d2; j--)
	      dp[i][x][y] = min(dp[i][x][y], dp[i-1][0][(j+10)%10]+d2);
	  } else {
	    for(int j = 0; j <= d1; j++) {
	      for(int k = j; k <= d1; k++) {
		dp[i][x][y] = min(dp[i][x][y], dp[i-1][(a[i-3]- '0' + j) % 10][(x+k)%10]+d1);
	      }
	    }
	    for(int j = 0; j <= d2; j++) {
	      for(int k = j; k <= d2; k++) {
		dp[i][x][y] = min(dp[i][x][y], dp[i-1][(a[i-3]-'0'-j+10)%10][(x-k+10)%10]+d2);
	      }
	    }
	  }
	}
      }
    }
    int ans;
    if(len >= 2)
      ans = dp[len][a[len-2]-'0'][a[len-1]-'0'];
    else if(len >= 1)
      ans = dp[len][0][a[len-1]-'0'];
    else
      ans = dp[len][0][0];
    printf("%d\n", ans);
  }
  return 0;
}
