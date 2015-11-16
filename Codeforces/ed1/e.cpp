#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int maxn = 30;
const int maxk = 50;
const int inf = 1000000000;

int dp[maxn+1][maxn+1][maxk+1];

// n < m
int f(int n, int m, int k) {
  if(dp[n][m][k] != -1)
    return dp[n][m][k];
  if(k == 0 || k == m * n)
    return dp[n][m][k] = 0;
  int ans = inf;
  for(int i = 1; i <= n / 2; i++) {
    int suba = i * m;
    int subb = (n - i) * m;
    for(int cut = 0; cut <= min(k, suba); cut++)
      if(k - cut <= subb)
	ans = min(ans, f(min(i, m), max(i, m), cut) + f(min(n - i, m), max(n - i, m), k - cut) + m * m);
  }
  for(int i = 1; i <= m / 2; i++) {
    int suba = i * n;
    int subb = (m - i) * n;
    for(int cut = 0; cut <= min(k, suba); cut++)
      if(k - cut <= subb)
	ans = min(ans, f(min(i, n), max(i, n), cut) + f(min(m - i, n), max(m - i, n), k - cut) + n * n);
  }
  return dp[n][m][k] = ans;
}

int main() {
  memset(dp, -1, sizeof dp);
  int tc;
  scanf("%d", &tc);
  while(tc--) {
    int n, m, k;
    scanf("%d%d%d", &n, &m, &k);
    if(n > m)
      swap(n, m);
    printf("%d\n", f(n, m, k));
  }

  return 0;
}
