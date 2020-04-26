#include <cstdio>

using namespace std;

const int maxn = 1000;
long long ans[maxn+5];

void init() {
  ans[1] = 5LL;
  for(int i = 2; i <= maxn; i++) {
    ans[i] = ans[i-1] + i * 1LL * 3 + 1LL;
  }
}

int main() {
  init();
  int n;
  while(scanf("%d", &n) != EOF) {
    if(!n)
      break;
    printf("%lld\n", ans[n]);
  }
  return 0;
}
