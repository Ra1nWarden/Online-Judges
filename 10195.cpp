#include <iostream>
#include <cmath>
#include <cstdio>

#define PI 3.141592653

using namespace std;

int main() {
  double a, b, c;
  while (cin >> a >> b >> c) {
    if (a == 0 || b == 0 || c == 0) {
      printf("The radius of the round table is: %.3f\n", 0.0);
      continue;
    }
    double cosA = (pow(b, 2) + pow(c, 2) - pow(a, 2)) / (2 * b * c);
    double cosB = (pow(a, 2) + pow(c, 2) - pow(b, 2)) / (2 * a * c);
    double angleA = acos(cosA);
    double angleB = acos(cosB);
    double topAngle = PI - (angleA / 2) - (angleB / 2);
    double height = sin(angleB / 2) * sin(angleA / 2) * c / sin(topAngle);
    printf("The radius of the round table is: %.3f\n", height);
  }
  return 0;
}
