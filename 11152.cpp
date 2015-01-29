#include <cstdio>
#include <cmath>
#define PI acos(-1.0)

using namespace std;

int main() {
  double a, b, c;
  while(scanf("%lf %lf %lf", &a, &b, &c) != EOF) {
    double s = (a+b+c) / 2;
    double triangle = sqrt(s * (s - a) * (s - b) * (s - c));
    double innerradius = 2 * triangle / (a + b + c);
    double angle = acos((a * a + b * b - c * c) / (2 * a * b));
    double outerradius = c / 2 / cos((PI - angle * 2) / 2);
    printf("%.4f %.4f %.4f\n", PI * outerradius * outerradius - triangle, triangle - PI * innerradius * innerradius, PI * innerradius * innerradius);
  }
  return 0;
}
