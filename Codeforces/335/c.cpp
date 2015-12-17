#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int maxn = 100000;
int dp[maxn];
int n;

int main() {
  scanf("%d", &n);
  memset(dp, -1, sizeof dp);
  int maxlen = 1;
  for(int i = 0; i < n; i++) {
    int num;
    scanf("%d", &num);
    if(dp[num - 1] == -1) {
      dp[num] = 1;
    } else {
      dp[num] = dp[num - 1] + 1;
    }
    maxlen = max(maxlen, dp[num]);
  }
  printf("%d\n", n - maxlen);
  return 0;
}
