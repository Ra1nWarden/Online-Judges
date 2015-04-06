#include <cstdio>
#include <algorithm>
#include <cstring>
#define MAXN 130
#define MAXL 13
#define MAXM (1<<11)

using namespace std;

char board[MAXN][MAXL];
int m, n;
int cnt[MAXM][MAXM];
int dp[MAXM][MAXM];

void initcnt() {
  cnt[0][0] = n;
  for(int i = 1; i < (1 << m); i++) {
    for(int j = i; j >= 0; j=((j-1)&i)) {
      int counter = 0;
      for(int k = 0; k < n; k++) {
	bool ok = true;
	for(int l = 0; l < m; l++) {
	  if(((1 << l) & i) != 0) {
	    if(((1 << l) & j) == 0) {
	      // looking for 0
	      ok = board[k][l] == '0';
	    } else {
	      // looking for 1
	      ok = board[k][l] == '1';
	    }
	  }
	  if(!ok)
	    break;
	}
	if(ok)
	  counter++;
      }
      cnt[i][j] = counter;
      if(j == 0)
	break;
    }
  }
}

int f(int x, int y) {
  //printf("querying %d %d\n", x, y);
  //printf("count is %d\n", cnt[x][y]);
  if(dp[x][y] != -1)
    return dp[x][y];
  if(cnt[x][y] == 1)
    return dp[x][y] = 0;
  int ans = m;
  for(int i = 0; i < m; i++) {
    if(((1 << i) & x) == 0) {
      int newx = (x | (1 << i));
      int newy1 = (y | (1 << i));
      int newy2 = y;
      int subdecision = 1;
      if(cnt[newx][newy1] > 0) {
	subdecision = max(subdecision, f(newx, newy1) + 1);
	//printf("at %d %d answering true, subdecision is %d\n", x, y, subdecision);
      }
      if(cnt[newx][newy2] > 0) {
	subdecision = max(subdecision, f(newx, newy2) + 1);
	//printf("at %d %d answering false, subdecision is %d\n", x, y, subdecision);
      }

      //printf("at %d %d asking %d subdecision is %d\n", x, y, i, subdecision);
      ans = min(ans, subdecision);
    }
  }
  return dp[x][y] = ans;
}

int main() {
  while(scanf("%d %d\n", &m, &n) != EOF && (m || n)) {
    for(int i = 0; i < n; i++)
      scanf("%s\n", board[i]);		   
    memset(cnt, 0, sizeof cnt);
    initcnt();
    memset(dp, -1, sizeof dp);
    printf("%d\n", f(0, 0));
  }
  return 0;
}
