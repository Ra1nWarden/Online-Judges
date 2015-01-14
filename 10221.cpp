#include <iostream>
#include <cmath>
#include <cstdio>
#define EPS 1e-8

using namespace std;

const double PI = acos(-1.0);
const double r = 6440;

int sgn(double x) {
  if(fabs(x) < EPS)
    return 0;
  else
    return x < 0 ? -1 : 1;
}

int main() {
  double s, a;
  string unit;
  while(cin >> s >> a >> unit) {
    if(unit == "min") {
      a /= 60.0;
    }
    a = a / 180.0 * PI;
    if(sgn(a - PI) > 0)
      a = 2 * PI - a;
    s = s + r;
    printf("%.6f %.6f\n", s * a, 2 * sin(a / 2) * s);
  }
  return 0;
}
