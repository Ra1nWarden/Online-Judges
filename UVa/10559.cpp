#include <cstdio>
#include <cstring>
#include <algorithm>
#define MAXN 205

using namespace std;

int v[MAXN];
int n;
int dp[MAXN][MAXN][MAXN];

int f(int i, int j, int k) {
  if(dp[i][j][k] != -1)
    return dp[i][j][k];
  int q = j;
  while(q >= i) {
    if(v[q] == v[j])
      q--;
    else
      break;
  }
  q++;
  if(q == i) {
    return dp[i][j][k] = (j - i + 1 + k) * (j - i + 1 + k);
  }
  int ans = f(i, q - 1, 0) + (j - q + 1 + k) * (j - q + 1 + k);
  for(int p = i; p < q; p++) {
    if(v[p] == v[j]) {
      while(v[p] == v[j]) {
	p++;
      }
      p--;
      ans = max(ans, f(p+1, q-1, 0) + f(i, p, k + j - q + 1));
    }
  }
  return dp[i][j][k] = ans;
}

int main() {
  int tc;
  scanf("%d", &tc);
  for(int kase = 1; kase <= tc; kase++) {
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
      scanf("%d", &v[i]);
    }
    memset(dp, -1, sizeof dp);
    printf("Case %d: %d\n", kase, f(0, n-1, 0));
  }
  return 0;
}
