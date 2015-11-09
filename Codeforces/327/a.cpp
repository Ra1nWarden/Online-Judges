#include <cstdio>

using namespace std;

int main() {
  double l, p, q;
  scanf("%lf%lf%lf", &l, &p, &q);
  printf("%.5lf\n", l / (p + q) * p);
  return 0;
}
