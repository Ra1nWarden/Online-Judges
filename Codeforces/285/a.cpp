#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <iostream>
#define EPS 1e-8

using namespace std;

int sgn(double x) {
  if(fabs(x) < EPS)
    return 0;
  else
    return x < 0 ? -1 : 1;
}

int main() {
  int a, b, c, d;
  scanf("%d %d %d %d", &a, &b, &c, &d);
  double misha = max(3 * (double)a / 10, (double)a - (double)a/250 * c);
  double vasya = max(3 * (double)b / 10, (double)b - (double)b/250 * d);
  int cmp = sgn(misha - vasya);
  if(cmp == 0)
    printf("Tie\n");
  else if (cmp > 0)
    printf("Misha\n");
  else
    printf("Vasya\n");
  return 0;
}
