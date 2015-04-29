#include <cstdio>
#include <cmath>

using namespace std;

int main() {
  int m, n;
  scanf("%d %d", &m, &n);
  double ans = 0.0;
  for(int x = 1; x <= m; x++) {
    ans += x * 1.0 * (pow(x * 1.0 / m, n) - pow((x - 1) * 1.0 / m, n));
  }
  printf("%.10f\n", ans);
  return 0;
}
