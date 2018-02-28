#include <cstdio>
#include <cstring>

using namespace std;

const int maxn = 5000;
char str[maxn+5];
int n;
int dp[maxn+5][maxn+5];
int ans[maxn+5];

int main() {
  scanf("%s", str);
  n = strlen(str);
  for(int i = 0; i < n; i++)
    dp[i][i] = 1;
  for(int l = 1; l < n; l++) {
    for(int i = 0; i + l < n; i++) {
      if(str[i] != str[i+l]) {
	dp[i][i+l] = 0;
      } else if(l == 1) {
	dp[i][i+l] = 2;
      } else if (dp[i+1][i+l-1] == 0) {
	dp[i][i+l] = 0;
      } else {
	dp[i][i+l] = dp[i][i+((l-1)/2)] + 1;
      }
    }
  }

  // for(int i = 0; i < n; i++)
  //   for(int j = i; j < n; j++)
  //     printf("dp[%d][%d]=%d\n", i, j, dp[i][j]);

  memset(ans, 0, sizeof ans);
  int p = (1 + n) * n / 2;
  for(int i = 0; i < n; i++) {
    for(int j = i; j < n; j++) {
      ans[dp[i][j]]++;
    }
  }
  for(int i = 0; i < n; i++) {
    if(i)
      printf(" ");
    p -= ans[i];
    printf("%d", p);
  }
  printf("\n");
  return 0;
}
