#include <cstdio>
#include <cstring>
#define MAXS 11
#define MAXN 11
#define MAXV 1005

using namespace std;

int s, n;
int stamps[MAXN][MAXN];
int dp[MAXV];

int main() {
  while(scanf("%d", &s) != EOF && s) {
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
      scanf("%d", &stamps[i][0]);
      for(int j = 1; j <= stamps[i][0]; j++)
	scanf("%d", &stamps[i][j]);
    }
    int maxi = -1;
    int maxval = 0;
    for(int i = 0; i < n; i++) {
      memset(dp, -1, sizeof dp);
      for(int j = 1; j <= stamps[i][0]; j++)
	dp[stamps[i][j]] = 1;
      for(int next = 1; next <= s * stamps[i][stamps[i][0]] + 1; next++) {
	if(dp[next] == -1) {
	  bool change = false;
	  if(next - 1 > maxval) {
	    change = true;
	  } else if(next - 1 == maxval) {
	    if(stamps[i][0] < stamps[maxi][0]) {
	      change = true;
	    } else if(stamps[i][0] == stamps[maxi][0]) {
	      if(stamps[i][stamps[i][0]] < stamps[maxi][stamps[maxi][0]]) {
		change = true;
	      }
	    }
	  }
	  if(change) {
	    maxval = next - 1;
	    maxi = i;
	  }
	  break;
	} else {
	  if(dp[next] < s) {
	    for(int j = 1; j <= stamps[i][0]; j++) {
	      int sum = next + stamps[i][j];
	      if(dp[sum] == -1 || dp[sum] > dp[next] + 1)
		dp[sum] = dp[next] + 1;
	    }
	  }
	}
      }
    }
    printf("max coverage = %3d :", maxval);
    for(int i = 1; i <= stamps[maxi][0]; i++)
      printf("%3d", stamps[maxi][i]);
    printf("\n");
  }
  return 0;
}
