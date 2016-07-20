#include <cstdio>
#include <algorithm>

using namespace std;

int main() {
  int n, h, k, m;
  scanf("%d%d%d", &n, &h, &k);
  int x = 0;
  long long ans = 0;
  for(int i = 0; i < n; i++) {
    scanf("%d", &m);
    if(x + m > h) {
      int diff = x - (h - m);
      int delta = (diff + k - 1) / k;
      ans += delta;
      x -= min(x, delta * k);
    }
    x += m;
  }
  ans += (x + k - 1) / k;
  printf("%I64d\n", ans);
  return 0;
}
