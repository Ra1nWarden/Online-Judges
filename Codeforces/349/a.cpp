#include <cstdio>
#include <cmath>

using namespace std;

const double PI = acos(-1.0);
const double eps = 1e-8;

int main() {
  double d, h, v, e;
  scanf("%lf%lf%lf%lf", &d, &h, &v, &e);
  double suf = PI * (d / 2) * (d / 2);
  double in = suf * e;
  if(v - in > eps) {
    printf("YES\n");
    printf("%.8lf\n", suf * h / (v - in));
  } else {
    printf("NO\n");
  }
  return 0;
}
