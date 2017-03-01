#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

const int maxn = 1000000;
const int maxm = 10000000;
int v[maxn+5];
int n, k;
int dp[maxm+5];

bool ok(int m) {
  for(int i = 0; i <= 10000000; i++) {
    if(i < m)
      dp[i] = 0;
    else if(i / 2 < m)
      dp[i] = 1;
    else
      dp[i] = dp[i / 2] + dp[i - i / 2];
  }
  long long total = 0;
  for(int i = 0; i < n; i++) {
    total += dp[v[i]];
    if(total >= k)
      return true;
  }
  return false;
}

int main() {
  scanf("%d%d", &n, &k);
  long long sum = 0;
  for(int i = 0; i < n; i++) {
    scanf("%d", &v[i]);
    sum += v[i];
  }
  if(sum < k) {
    printf("-1\n");
    return 0;
  }
  int left = 1, right = 10000000;
  while(left != right) {
    int mid = ((left + right) >> 1) + 1;
    if(ok(mid)) {
      left = mid;
    } else {
      right = mid - 1;
    }
  }
  printf("%d\n", left);
  return 0;
}
