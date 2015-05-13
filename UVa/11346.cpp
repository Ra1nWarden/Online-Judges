#include <cstdio>
#include <cmath>

using namespace std;

double a, b, s;

int main() {
  int tc;
  scanf("%d", &tc);
  while(tc--) {
    scanf("%lf %lf %lf", &a, &b, &s);
    if(a * b <= s) {
      printf("0.000000%%\n");
    } else if(s == 0) {
      printf("100.000000%%\n");
    } else {
      printf("%.6f%%\n", 100.0 * (a * b - s - s * log(a * b / s)) / (a * b));
    }
  }
  return 0;
}
