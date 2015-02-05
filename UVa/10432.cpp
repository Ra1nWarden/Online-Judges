#include <iostream>
#include <cstdio>
#include <cmath>

using namespace std;

const double PI = acos(-1.0);

int main() {
  double r, n;
  while(cin >> r >> n) {
    double rad = 2 * PI / n;
    double sector = (r * r * rad - sin(rad) * r * r) / 2;
    printf("%.3f\n", r * r * PI - n * sector);
  }
  return 0;
}
