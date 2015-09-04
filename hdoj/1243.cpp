#include <cstdio>
#include <cstring>
#include <algorithm>
#define MAXN 2050

using namespace std;

char terros[MAXN];
int terron[MAXN];
int n;
char gun[MAXN];
int gl;
char terr[MAXN];
int tl;
int dp[2][MAXN];

int score(char ch) {
  for(int i = 0; i < strlen(terros); i++) {
    if(terros[i] == ch)
      return terron[i];
  }
  return -1;
}

int main() {
  while(~scanf("%d\n", &n)) {
    scanf("%s", terros);
    for(int i = 0; i < n; i++)
      scanf("%d", &terron[i]);
    scanf("\n");
    scanf("%s", gun+1);
    gl = strlen(gun+1);
    scanf("%s", terr+1);
    tl = strlen(terr+1);
    for(int i = gl; i >= 1; i--) {
      for(int j = tl; j >= 1; j--) {
	if(i == gl && j == tl) {
	  dp[i&1][j] = gun[i] == terr[j] ? score(gun[i]) : 0;
	} else if(i == gl) {
	  dp[i&1][j] = gun[i] == terr[j] ? score(gun[i]) : dp[i&1][j+1];
	} else if(j == tl) {
	  dp[i&1][j] = gun[i] == terr[j] ? score(gun[i]) : dp[(i&1)^1][j];
	} else {
	  dp[i&1][j] = max(dp[(i&1)^1][j], dp[i&1][j+1]);
	  if(gun[i] == terr[j])
	    dp[i&1][j] = max(dp[i&1][j], dp[(i&1)^1][j+1] + score(gun[i]));
	  else
	    dp[i&1][j] = max(dp[i&1][j], dp[(i&1)^1][j+1]);
	}
      }
    }
    printf("%d\n", dp[1][1]);
  }
  return 0;
}
