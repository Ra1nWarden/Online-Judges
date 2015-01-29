#include <cmath>
#include <cstdio>
#define EPS 1e-8

using namespace std;

double sgn(double x) {
  if(fabs(x) < EPS)
    return 0;
  else
    return x < 0 ? -1 : 1;
}

bool triangle(double a, double b, double c) {
  if(sgn(a + b - c) <= 0 || sgn(fabs(a - b) - c) >= 0)
    return false;
  if(sgn(a + c - b) <= 0 || sgn(fabs(a - c) - b) >= 0)
    return false;
  if(sgn(c + b - a) <= 0 || sgn(fabs(c - b) - a) >= 0)
    return false;
  return true;
}

int main() {
  double a, b, c;
  while(scanf("%lf %lf %lf", &a, &b, &c) != EOF) {
    if(!triangle(a, b, c))
      printf("-1.000\n");
    else {
      double p = (a+b+c) / 2;
      // Heron's formula for area of triangle formed by medians
      // original triangle has an area that is 1/3 more
      printf("%.3f\n", 4 * sqrt(p * (p - a) * (p - b) * (p - c)) / 3);
    }
  }
  return 0;
}
