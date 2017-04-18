#include <cstdio>
#include <cmath>

using namespace std;

const double pi = acos(-1);

int main() {
  int l;
  while(scanf("%d", &l)) {
    if(l == 0)
      break;
    double r = l / pi;
    printf("%.2lf\n", pi * r * r / 2);
  }
  return 0;
}
