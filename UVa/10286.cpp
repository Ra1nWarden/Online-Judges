#include <cstdio>
#include <cmath>
#define PI acos(-1.0)

using namespace std;

int main() {
  double l;
  double angle = 0.35 * PI;
  while(scanf("%lf", &l) != EOF) {
    printf("%.10f\n", l / sin(angle) * sin(0.6 * PI));
  }
  return 0;
}
