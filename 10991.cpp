#include <cmath>
#include <cstdio>

using namespace std;

int main() {
  int tc;
  scanf("%d", &tc);
  double a, b, c;
  for(int et = 0; et < tc; et++) {
    scanf("%lf %lf %lf", &a, &b, &c);
    double l1 = b + c, l2 = a + c, l3 = a + b;
    double s = (l1+l2+l3) / 2;
    double area = sqrt(s * (s-l1) * (s-l2) * (s-l3));
    //printf("area1 %.6f ", area);
    area -= 0.5 * a * a * acos((l2 * l2 + l3 * l3 - l1 * l1) / (2 * l2 * l3));
    //printf("area2 %.6f ", area);
    area -= 0.5 * b * b * acos((l1 * l1 + l3 * l3 - l2 * l2) / (2 * l1 * l3));
    //printf("area3 %.6f\n", area);
    area -= 0.5 * c * c * acos((l2 * l2 + l1 * l1 - l3 * l3) / (2 * l2 * l1));
    printf("%.6f\n", area);
  }
  return 0;
}
