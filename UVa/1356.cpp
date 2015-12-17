#include <cstdio>
#include <cmath>

using namespace std;

int d, h, b, l;
const double eps = 1e-6;
double a;

double f(double x) {
  return sqrt(1 + 4 * a * a * x * x);
}

double simpson(double a, double b) {
  double c = a + (b - a) / 2;
  return (f(a) + 4 * f(c) + f(b)) * (b - a) / 6;
}

double asr(double a, double b, double eps, double A) {
  double c = a + (b - a) / 2;
  double L = simpson(a, c), R = simpson(c, b);
  if(fabs(L + R - A) <= 15 * eps)
    return L + R + (L + R - A) / 15.0;
  return asr(a, c, eps/2, L) + asr(c, b, eps/2, R);
}

double asr(double a, double b, double eps) {
  return asr(a, b, eps, simpson(a, b));
}

double parabola_length(double w, double h) {
  a = 4.0 * h / (w * w);
  return asr(0, w/2, eps) * 2;
}

int main() {
  int tc;
  scanf("%d", &tc);
  for(int kase = 1; kase <= tc; kase++) {
    scanf("%d%d%d%d", &d, &h, &b, &l);
    int n = (d + b - 1) / d;
    double d1 = (double) b / n;
    double l1 = (double) l / n;
    double left = 0, right = h;
    while(right - left > eps) {
      double mid = left + (right - left) / 2;
      if(parabola_length(d1, mid) < l1)
	left = mid;
      else
	right = mid;
    }
    if(kase > 1)
      printf("\n");
    printf("Case %d:\n%.2lf\n", kase, h - left);
  }
  return 0;
}
