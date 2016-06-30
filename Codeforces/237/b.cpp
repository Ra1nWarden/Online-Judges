#include <cstdio>

using namespace std;

int main() {
  double a, d;
  int n;
  scanf("%lf %lf", &a, &d);
  scanf("%d", &n);
  for(int i = 1; i <= n; i++) {
    long double dist = d * i;
    long long side = (long long) (dist / a);
    double r = dist - side * a;
    side %= 4;
    if(side == 0) {
      printf("%.5lf 0.00000\n", r);
    } else if(side == 1) {
      printf("%.5lf %.5lf\n", a, r);
    } else if(side == 2) {
      printf("%.5lf %.5lf\n", a - r, a);
    } else {
      printf("0.00000 %.5lf\n", a - r);
    }
  }
  return 0;
}
