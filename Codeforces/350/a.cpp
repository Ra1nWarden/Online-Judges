#include <cstdio>
#include <algorithm>

using namespace std;

int main() {
  int n;
  scanf("%d", &n);
  int ans = n / 7 * 2;
  printf("%d %d\n", ans + max(0, n % 7 - 5), ans + min(2, n % 7));
  return 0;
}
