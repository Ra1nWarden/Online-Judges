#include <cstdio>
#include <vector>
#include <cstring>
#include <cstdlib>
#define INF 2e9
#define MAXL 105

using namespace std;

char str1[MAXL], str2[MAXL];
int dp[MAXL][MAXL];
int n;
int ans[MAXL];

int main() {
  while(scanf("%s\n%s\n", str1, str2) != EOF) {
    n = strlen(str1);
    for(int i = 0; i < n; i++) {
      for(int j = i; j < n; j++) {
	dp[i][j] = (j - i + 1);
      }
    }
    for(int j = 1; j < n; j++) {
      for(int i = j - 1; i >= 0; i--) {
	dp[i][j] = dp[i+1][j] + 1;
	for(int k = i + 1; k <= j; k++) {
	  if(str2[k] == str2[i])
	    dp[i][j] = min(dp[i][j], dp[i+1][k-1] + dp[k][j]);
	}
      }
    }
    
    for(int i = 0; i < n; i++) {
      ans[i] = dp[0][i];
      if(str2[i] == str1[i])
	ans[i] = i == 0 ? 0 : ans[i-1];
      else {
	for(int k = 0; k < i; k++) {
	  ans[i] = min(ans[i], ans[k] + dp[k+1][i]);
	}
      }
    }
    printf("%d\n", ans[n-1]);
  }
  return 0;
}
