#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int maxn = 500;
int v[maxn+1];
int n;
bool palin[maxn+1][maxn+1];
int dp[maxn+1][maxn+1];

void init() {
  for(int len = 1; len <= n; len++) {
    for(int i = 0; i + len - 1 < n; i++) {
      palin[i][i+len-1] = v[i] == v[i+len-1] && (len > 2 ? palin[i+1][i+len-2] : true);
    }
  }
  memset(dp, -1, sizeof dp);
}

int f(int i, int j) {
  if(i > j)
    return 0;
  if(dp[i][j] != -1)
    return dp[i][j];
  if(palin[i][j])
    return dp[i][j] = 1;
  int ans = j - i + 1;
  for(int ii = i; ii <= j; ii++) {
    for(int jj = ii; jj <= j; jj++) {
      if(palin[ii][jj]) {
	ans = min(ans, 1 + f(i, ii - 1) + f(jj + 1, j));
      }
    }
  }
  printf("f(%d, %d) = %d\n", i, j, ans);
  return dp[i][j] = ans;
}

int main() {
  scanf("%d", &n);
  for(int i = 0; i < n; i++)
    scanf("%d", &v[i]);
  init();
  printf("%d\n", f(0, n - 1));
  return 0;
}
