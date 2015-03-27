#include <cmath>
#include <cstdio>
#define EPS 1e-8

using namespace std;

int main() {
  int a, b, c, d;
  while(scanf("%d %d %d %d", &a, &b, &c, &d) != EOF) {
    double lhs = b * log(a);
    double rhs = d * log(c);
    if(fabs(lhs - rhs) < EPS) {
      printf("=\n");
    } else {
      if(lhs < rhs) {
	printf("<\n");
      } else {
	printf(">\n");
      }
    }
  }
  return 0;
}
