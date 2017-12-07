#include <cstdio>
#include <cmath>

using namespace std;

int main() {
  int tc;
  scanf("%d", &tc);
  while(tc--) {
    double a, b, c, d;
    scanf("%lf %lf %lf %lf", &a, &b, &c, &d);
    double ans = (-a + b + c + d) * (a - b + c + d) * (a + b - c + d) * (a + b + c - d);
    printf("%.2lf\n", sqrt(ans) / 4);
  }
  return 0;
}
