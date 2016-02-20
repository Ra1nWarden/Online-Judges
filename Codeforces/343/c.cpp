#include <cstdio>
#include <algorithm>

using namespace std;

const int maxn = 2000;
int dp[maxn+1][maxn+1];
int n, m;
const int maxm = 100000;
char str[maxm];
const int mod = 1000000007;

void init(int len) {
  for(int i = 0; i <= len; i++) {
    for(int j = 0; j <= i; j++) {
      if(i == j) {
	dp[i][j] = 1;
      } else {
	dp[i][j] = dp[i-1][j-1];
	if(j+1 <= i-1)
	  dp[i][j] = (dp[i][j] + dp[i-1][j+1]) % mod;
      }
    }
  }
}

int main() {
  scanf("%d%d\n", &n, &m);
  scanf("%s", str);
  int closediff = 0;
  int cur = 0;
  for(int i = 0; i < m; i++) {
    if(str[i] == '(')
      cur++;
    else
      cur--;
    closediff = min(closediff, cur);
  }
  int ans = 0;
  init(n - m);
  for(int l = -closediff; l <= n - m - cur; l++) {
    int r = n - m - l;
    for(int o = -closediff; o + cur <= r && o <= l; o++) {
      int add = (dp[l][o] * 1LL * dp[r][o + cur]) % mod;
      ans = (ans + add) % mod; 
    }
  }
  printf("%d\n", ans);
  return 0;
}
