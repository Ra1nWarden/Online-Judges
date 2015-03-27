#include <iostream>
#include <cstdio>
#include <cmath>

using namespace std;

int main() {
  int tc;
  cin >> tc;
  for(int t = 1; t <= tc; t++) {
    double a, b;
    scanf("%lf %lf", &a, &b);
    printf("Case #%d: %.3f\n", t, (1+a)*a/2*(1-pow(1-1/a, b)));
  }
  return 0;
}
