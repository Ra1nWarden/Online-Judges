#include <iostream>
#include <cmath>
#include <cstdio>
#include <cstdlib>

using namespace std;

double calculate(double x, double p, double q, double r, double s, double t, double u) {
  return p * exp(-x) + q * sin(x) + r * cos(x) + s * tan(x) + t*pow(x, 2) + u;
}

int hasSolution(double p, double q, double r, double s, double t, double u) {
  double f0 = calculate(0, p, q, r, s, t, u);
  double f1 = calculate(1, p, q, r, s, t, u);
  if (f0 * f1 < 0) {
    return f0 > f1 ? -1 : 1;
  } else {
    return 0;
  }
}

double findSolution(double p, double q, double r, double s, double t, double u, double start, double end) {
  double mid = (start + end) / 2;
  double result = calculate(mid, p, q, r, s, t, u);
  if (abs(result - 0) < 1e-9)
    return mid;
  else if (result > 0) {
    return findSolution(p, q, r, s, t, u, start, mid);
  } else {
    return findSolution(p, q, r, s, t, u, mid, end);
  }
}

int main() {
  double p, q, r, s, t, u;
  int count = 0;
  while(cin >> p >> q >> r >> s >> t >> u) {
    int hasSol = hasSolution(p, q, r, s, t, u);
    if (hasSol != 0) {
      if (hasSol == 1)
	printf("%.4f\n", findSolution(p, q, r, s, t, u, 0, 1));
      else
	printf("%.4f\n", findSolution(p, q, r, s, t, u, 1, 0));
    } else {
      if (abs(calculate(0, p, q, r, s, t, u) - 0) < 1e-9)
	cout << "0.0000" << endl;
      else if (abs(calculate(1, p, q, r, s, t, u) - 0) < 1e-9)
	cout << "1.0000" << endl;
      else cout << "No solution" << endl;
    }
  }
  return 0;
}
