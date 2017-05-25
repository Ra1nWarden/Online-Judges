#include <cstdio>

using namespace std;

const int maxn = 1000000;
const int mod = 1000007;
int ans[maxn+5];

void init() {
  ans[0] = 0;
  for(int i = 1; i <= maxn; i++) {
    ans[i] = (ans[i-1] + i * 2 + i - 1) % mod;
  }
}

int main() {
  init();
  int tc;
  scanf("%d", &tc);
  int idx;
  while(tc--) {
    scanf("%d", &idx);
    printf("%d\n", ans[idx]);
  }
  return 0;
}
