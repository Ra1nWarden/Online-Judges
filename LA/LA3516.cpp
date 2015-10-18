#include <cstdio>
#include <cstring>

using namespace std;

const int mod = 1000000000;
const int maxl = 300;

int dp[maxl][maxl];
char str[maxl+5];

int f(int m, int n) {
  if(dp[m][n] >= 0) {
    return dp[m][n];
  }
  if(str[m] != str[n]) {
    return dp[m][n] = 0;
  }
  if(m == n) {
    return dp[m][n] = 1;
  }
  int ans = 0;
  for(int i = m + 2; i <= n; i++) {
    if(str[i] == str[m]) {
      ans = (ans + (long long) f(m+1, i-1) * f(i, n)) % mod;
    }
  }
  return dp[m][n] = ans;
}

int main() {
  while(scanf("%s\n", str) != EOF) {
    memset(dp, -1, sizeof dp);
    printf("%d\n", f(0, strlen(str) - 1));
  }
  return 0;
}
