#include <iostream>
#include <cmath>
#include <cstdio>

using namespace std;

const double PI = 2 * acos(0);

int main() {
  int n;
  double a;
  int tc = 1;
  while(cin >> n >> a) {
    if(n < 3)
      break;
    double rec = a / n;
    double rad = PI * 2 / n;
    double r2 = sqrt(rec * 2 / sin(rad));
    double r1 = cos(rad / 2) * r2;
    printf("Case %d: %.5f %.5f\n", tc++, PI * r2 * r2 - a, a - (PI * r1 * r1));
  }
  return 0;
}
