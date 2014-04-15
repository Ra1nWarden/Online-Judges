#include <iostream>
#include <cstdio>
#include <cmath>

using namespace std;

#define EPSILON 1e-7

int main() {
  double l, w;
  while (cin >> l >> w) {
    double a = 12.0;
    double b = - 4 * l - 4 * w;
    double c = l * w;
    double offset = sqrt(pow(b, 2) - 4 * a * c);
    double minusr = (- b - offset) / (2 * a);
    double plusr = (- b + offset) / (2 * a);
    double maxr, minr;
    if (24 * minusr - 4 * l - 4 * w < 0) {
      maxr = minusr;
      minr = plusr;
    }
    if (24 * plusr - 4 * l - 4 * w < 0) {
      maxr = plusr;
      minr = minusr;
    }
    if (minr < 0 || minr > (w < l ? w / 2 : l / 2)) {
      minr = w < l ? w / 2 : l / 2;
    }
    printf("%.3f %.3f %.3f\n", maxr + EPSILON, 0.000, minr + EPSILON);
  }
  return 0;
}
