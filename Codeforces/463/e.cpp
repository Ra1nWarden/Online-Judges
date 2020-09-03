#include <cstdio>
#include <cstring>

using namespace std;

int n, k;
const int mod = 1e9 + 7;
const int maxk = 5000;
int dp[maxk+5][maxk+5];

int pow(int b, int p) {
  if(p == 0) {
    return 1;
  }
  int sub = pow(b, p >> 1);
  int sq = (sub * 1LL * sub) % mod;
  if(p&1) {
    sq = (sq * 1LL * b) % mod;
  }
  return sq;
}

int f(int a, int b, int c) {
  if(dp[a][c] != -1) {
    return dp[a][c];
  }
  if(c == 0) {
    return dp[a][c] = pow(2, n-a);
  }
  if(b == 0) {
    return dp[a][c] = pow(a, c);
  }
  return dp[a][c] = ((a * 1LL * f(a, b, c - 1)) % mod + (b * 1LL * f(a+1, b-1, c-1)) % mod) % mod;
}

int main() {
  scanf("%d%d", &n, &k);
  memset(dp, -1, sizeof dp);
  printf("%d\n", f(0, n, k));
  return 0;
}
