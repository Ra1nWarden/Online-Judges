#include <cstdio>
#include <cstring>
#include <algorithm>
#define MAXL 2005

using namespace std;

char str1[MAXL], str2[MAXL];
int l1, l2;
int dp[MAXL][MAXL];

int main() {
  while(scanf("%s %s", str1, str2) != EOF) {
    l1 = strlen(str1);
    l2 = strlen(str2);
    memset(dp, 0, sizeof dp);
    for(int i = 1; i <= l1; i++) {
      for(int j = 1; j <= l2; j++) {
	dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
	if(str1[i-1] == str2[j-1])
	  dp[i][j] = max(dp[i][j], dp[i-1][j-1] + 1);
      }
    }
    printf("%d\n", dp[l1][l2]);
  }
  return 0;
}
