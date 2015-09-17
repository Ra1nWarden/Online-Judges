#include <cstdio>
#include <algorithm>

using namespace std;

int main() {
  int a, b;
  scanf("%d%d", &a, &b);
  if(a < b) {
    printf("-1\n");
  } else if(a == b) {
    printf("%d\n", b);
  } else {
    // (a-b-2kb) / (2k+2)
    int k = (a - b) / (2 * b);
    double sigma = (a - b - 2 * k * b) * 1.0 / (2 * k + 2);
    printf("%.9lf\n", sigma+b);
  }
  return 0;
}
