#include <cstdio>
#include <cstring>

using namespace std;

const int maxn = 1e5;
int v[maxn+5];
int dp[maxn+5][6];
int ans[maxn+5];
int n;

int main() {
  scanf("%d", &n);
  for(int i = 0; i < n; i++)
    scanf("%d", &v[i]);
  for(int i = 1; i <= 5; i++)
    dp[0][i] = 0;
  for(int i = 1; i < n; i++) {
    for(int j = 1; j <= 5; j++) {
      dp[i][j] = -1;
      if(v[i] > v[i-1]) {
	for(int k = 1; k < j; k++) {
	  if(dp[i-1][k] != -1) {
	    dp[i][j] = k;
	    break;
	  }
	}
      } else if(v[i] < v[i-1]) {
	for(int k = j+1; k <= 5; k++) {
	  if(dp[i-1][k] != -1) {
	    dp[i][j] = k;
	    break;
	  }
	}
      } else {
	for(int k = 1; k <= 5; k++) {
	  if(k == j)
	    continue;
	  if(dp[i-1][k] != -1) {
	    dp[i][j] = k;
	    break;
	  }
	}
      }
    }
  }
  int next = -1;
  for(int i = 1; i <= 5; i++) {
    if(dp[n-1][i] != -1) {
      next = i;
      break;
    }
  }
  
  if(next == -1) {
    printf("%d\n", next);
    return 0;
  }

  for(int i = n-1; i >= 0; i--) {
    ans[i] = next;
    next = dp[i][next];
  }

  for(int i = 0; i < n; i++) {
    if(i)
      printf(" ");
    printf("%d", ans[i]);
  }
  printf("\n");
  
  return 0;
}
