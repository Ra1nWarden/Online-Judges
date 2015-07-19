#include <cstdio>
#include <cmath>
#include <algorithm>

using namespace std;

double k, l, s, w;
double g = 9.81;

int main() {
  while(scanf("%lf %lf %lf %lf", &k, &l, &s, &w) != EOF && (k || l || s || w)) {
    double maxL = l + sqrt((w * g * s) / (0.5 * k));
    if(maxL < s) {
      printf("Stuck in the air.\n");
      continue;
    }
    double mgh = w * g * s;
    double kxs = 0.5 * k * pow(max(0.0, s - l), 2);
    double speed = sqrt((mgh - kxs) / (0.5 * w));
    if(speed <= 10) {
      printf("James Bond survives.\n");
    } else {
      printf("Killed by the impact.\n");
    }
  }
  return 0;
}
