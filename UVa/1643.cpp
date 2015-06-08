#include <cmath>
#include <cstdio>
#include <utility>
#include <algorithm>
#define MAXN 10

using namespace std;

typedef pair<double, double> Point;

int n;
Point a, b;
double squares[MAXN];

int main() {
  while(scanf("%d", &n) != EOF && n) {
    scanf("%lf %lf %lf %lf", &a.first, &a.second, &b.first, &b.second);
    double height = 0;
    double squaresum = 0;
    for(int i = 0; i < n; i++) {
      scanf("%lf", &squares[i]);
      height += squares[i];
      squaresum += pow(squares[i], 2);
    }
    double c = height;
    double aangle = atan(a.second / a.first);
    double bangle = atan(b.second / b.first);
    if(aangle < bangle) {
      swap(a, b);
      swap(aangle, bangle);
    }
    double d = c / a.first * a.second;
    double h = (height + d) / (tan(aangle) - tan(bangle));
    double ans = (height + d) * h * 0.5 - c * d * 0.5 - squaresum - ((height * height - squaresum) / 2);
    printf("%.3f\n", ans);
  }
  return 0;
}
