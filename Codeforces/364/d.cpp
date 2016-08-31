#include <cstdio>
#include <cmath>

using namespace std;

int n, k;
double v1, v2, l;
const double eps = 1e-8;

int main() {
  scanf("%d %lf %lf %lf %d", &n, &l, &v1, &v2, &k);
  double left = l / v2;
  double right = l / v1;
  int s = (n + k - 1) / k;
  while(fabs(left - right) > eps) {
    double mid = (left + right) / 2;
    double r = (l - mid * v1) / (v2 - v1);
    double d = (v2 - v1) * r;
    double total = r * s + d / (v1 + v2) * (s - 1);
    if(total < mid) {
      right = mid;
    } else {
      left = mid;
    }
  }
  printf("%.10lf\n", left);
  return 0;
}
