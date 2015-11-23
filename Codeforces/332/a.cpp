#include <cstdio>
#include <algorithm>

using namespace std;

int main() {
  int d1, d2, d3;
  scanf("%d%d%d", &d1, &d2, &d3);
  int ans = min((d1 + d3) * 2, (d2 + d3) * 2);
  ans = min(ans, d1 + d2 + d3);
  ans = min(ans, d1 * 2 + d2 * 2);
  printf("%d\n", ans);
  return 0;
}
