#include <cstdio>
#include <cmath>

using namespace std;

int a, b, x, y, v;
int n;
const int maxn = 1000;
const double eps = 1e-8;
double t;

int main() {
  scanf("%d%d", &a, &b);
  scanf("%d", &n);
  for(int i = 0; i < n; i++) {
    scanf("%d%d%d", &x, &y, &v);
    double tt = sqrt((x - a) * (x - a) + (y - b) * (y - b)) / v;
    if(i == 0 || t - tt > eps) {
      t = tt;
    }
  }
  printf("%.10lf\n", t);
  return 0;
}
