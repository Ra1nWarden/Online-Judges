#include <cstdio>
#include <algorithm>

using namespace std;

const int maxn = 5000;
int v[maxn+5];
int n;
int sum[maxn+5][maxn+5];
int dp[maxn+5][maxn+5];

int main() {
  scanf("%d", &n);
  for(int i = 1; i <= n; i++) {
    scanf("%d", &v[i]);
    sum[i][1] = v[i];
    dp[i][1] = v[i];
  }
  
  for(int len = 2; len <= maxn; len++) {
    for(int i = 1; i + len - 1 <= maxn; i++) {
      sum[i][len] = sum[i][len-1] ^ sum[i+1][len-1];
      dp[i][len] = max(max(dp[i][len-1], dp[i+1][len-1]), sum[i][len]);
    }
  }
  
  int q;
  scanf("%d", &q);
  while(q--) {
    int l, r;
    scanf("%d %d", &l, &r);
    printf("%d\n", dp[l][r-l+1]);
  }
  return 0;
}
