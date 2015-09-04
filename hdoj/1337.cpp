#include <cstring>
#include <cstdio>
#define MAXN 105

using namespace std;

int n;
int dp[MAXN];
int ans[MAXN];

int main() {
  int tc;
  scanf("%d", &tc);
  memset(dp, 0, sizeof dp);
  for(int i = 1; i <= 100; i++) {
    for(int j = i; j <= 100; j+=i) {
      dp[j]++;
    }
  }
  ans[0] = 0;
  for(int i = 1; i <= 100; i++) {
    if(dp[i] % 2)
      ans[i] = ans[i-1] + 1;
    else
      ans[i] = ans[i-1];
  }
  while(tc--) {
    scanf("%d", &n);
    printf("%d\n", ans[n]);
  }
  return 0;
}
