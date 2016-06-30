#include <cstdio>
#include <cmath>
#include <algorithm>
#define EPS 1e-21L

using namespace std;

int main() {
  long long x1, y1, x2, y2;
  scanf("%lld %lld %lld %lld\n", &x1, &y1, &x2, &y2);
  if(x1 > x2) {
    swap(x1, x2);
    swap(y1, y2);
  }
  long double l1 = (long double) (x2 - x1) * y1 / (y1+y2) + EPS;
  long double l2 = (long double) (x2 - x1) * y2 / (y1+y2) + EPS;
  long double ans = pow(l1, 2) + pow(l2, 2) + pow(y1, 2) + pow(y2, 2) + 2 * sqrt(pow(l1, 2) + pow(y1, 2)) * sqrt(pow(l2, 2) + pow(y2, 2));
  printf("%.20Lf\n", ans + EPS);
  return 0;
}
