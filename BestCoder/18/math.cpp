#include <iostream>
#include <cstdio>
#include <cmath>
#define EPS 1e-8

using namespace std;

double a, b, c, d, l, r;

double f(double x) {
  return fabs(a * pow(x, 3) + b * pow(x, 2) + c * x + d);
}

int main() {

  while(cin >> a >> b >> c >> d >> l >> r) {
    bool cr = false;
    double b24ac = 4 * pow(b, 2) - 12 * a * c;
    cr = (b24ac + EPS >= 0);
    if(cr) {
      double cr1 = (-2*b + sqrt(b24ac)) / (6 * a);
      double cr2 = (-2*b - sqrt(b24ac)) / (6 * a);
      double result = max(f(l), f(r));
      if(l < cr1 && cr1 < r)
	result = max(result, f(cr1));
      if(l < cr2 && cr2 < r)
	result = max(result, f(cr2));
      printf("%.2f\n", result + EPS);
    }
    else {
      double result = max(f(l), f(r));
      printf("%.2f\n", result + EPS);
    }
  }
  return 0;
}
