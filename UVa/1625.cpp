#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#define MAXN 5005

using namespace std;

char str1[MAXN];
int sn1[MAXN][2];
char str2[MAXN];
int sn2[MAXN][2];
int dp[MAXN][MAXN];
int n, m;
int change[MAXN][MAXN];

int main() {
  int tc;
  scanf("%d", &tc);
  while(tc--) {
    scanf("%s\n%s\n", str1, str2);
    n = strlen(str1);
    m = strlen(str2);
    memset(sn1, -1, sizeof sn1);
    for(int i = 0; i < n; i++) {
      int index = str1[i] - 'A';
      if(sn1[index][0] == -1) {
	sn1[index][0] = sn1[index][1] = i;
      } else {
	sn1[index][1] = i;
      }
    }
    memset(sn2, -1, sizeof sn2);
    for(int i = 0; i < m; i++) {
      int index = str2[i] - 'A';
      if(sn2[index][0] == -1) {
	sn2[index][0] = sn2[index][1] = i;
      } else
	sn2[index][1] = i;
    }

    for(int i = 0; i <= n; i++) {
      for(int j = 0; j <= m; j++) {
	int entry = 0;
	for(int a = 0; a < 26; a++) {
	  if(sn1[a][0] == -1 && sn2[a][0] == -1)
	    continue;
	  else if(sn1[a][0] == -1) {
	    if(j > sn2[a][0])
	      entry++;
	    if(j > sn2[a][1])
	      entry--;
	  } else if(sn2[a][0] == -1) {
	    if(i > sn1[a][0])
	      entry++;
	    if(i > sn1[a][1])
	      entry--;
	  } else {
	    if(i > sn1[a][0] || j > sn2[a][0])
	      entry++;
	    if(i > sn1[a][1] && j > sn2[a][1])
	      entry--;
	  }
	}
	change[i][j] = entry;
      }
    }
        
    for(int i = 0; i <= n; i++) {
      for(int j = 0; j <= m; j++) {
        if(i == 0 && j == 0)
	  dp[i][j] = 0;
	else if(i == 0)
	  dp[i][j] = dp[i][j-1] + change[i][j-1];
	else if(j == 0)
	  dp[i][j] = dp[i-1][j] + change[i-1][j];
	else
	  dp[i][j] = min(dp[i-1][j] + change[i-1][j], dp[i][j-1] + change[i][j-1]);
      }
    }
    
    printf("%d\n", dp[n][m]);
  }
  return 0;
}
