#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int maxl = 2000;
char a[maxl+5], b[maxl+5];
int al, bl;
int dp[maxl+5][maxl+5];

int main() {
  int tc;
  scanf("%d\n", &tc);
  while(tc--) {
    scanf("%s\n%s\n", a, b);
    al = strlen(a);
    bl = strlen(b);
    for(int sum = 0; sum <= al + bl; sum++) {
      for(int i = 0; i <= sum; i++) {
	int j = sum - i;
	if(i > al || j > bl)
	  continue;
	if(i == 0) {
	  dp[i][j] = j;
	} else if(j == 0) {
	  dp[i][j] = i;
	} else {
	  dp[i][j] = a[i-1] == b[j-1] ? dp[i-1][j-1] : dp[i-1][j-1] + 1;
	  dp[i][j] = min(dp[i][j], dp[i-1][j] + 1);
	  dp[i][j] = min(dp[i][j], dp[i][j-1] + 1);
	}
      }
    }
    printf("%d\n", dp[al][bl]);
  }
  return 0;
}
