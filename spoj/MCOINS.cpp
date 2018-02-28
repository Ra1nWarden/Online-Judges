#include <cstdio>
#include <cstring>

using namespace std;

const int maxn = 1000000;
int dp[maxn+5];
int k, l, m;

void init() {
  memset(dp, -1, sizeof dp);
  dp[0] = 0;
  for(int i = 1; i <= maxn; i++) {
    dp[i] = dp[i-1]^1;
    if(i >= k)
      dp[i] = dp[i] || (dp[i-k]^1);
    if(i >= l)
      dp[i] = dp[i] || (dp[i-l]^1);
  }
}

int main() {
  scanf("%d%d%d", &k, &l, &m);
  init();
  while(m--) {
    int n;
    scanf("%d", &n);
    printf("%c", dp[n] ? 'A' : 'B');
  }
  printf("\n");
  return 0;
}
