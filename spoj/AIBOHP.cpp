#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int maxn = 6100;
char str[maxn+5];
int dp[maxn+5][maxn+5];
int len;

int main() {
  int tc;
  scanf("%d\n", &tc);
  while(tc--) {
    scanf("%s\n", str);
    len = strlen(str);
    for(int i = 0; i < len; i++)
      dp[i][i] = 0;
    for(int i = 0; i < len - 1; i++) {
      dp[i][i+1] = str[i] == str[i+1] ? 0 : 1;
    }
    for(int l = 2; l <= len - 1; l++) {
      for(int i = 0; i < len - l; i++) {
	int ans = l;
	if(str[i] == str[i+l]) {
	  ans = min(ans, dp[i+1][i+l-1]);
	}
	ans = min(ans, dp[i+1][i+l] + 1);
	ans = min(ans, dp[i][i+l-1] + 1);
	dp[i][i+l] = ans;
      }
    }
    printf("%d\n", dp[0][len-1]);
  }
  return 0;
}
