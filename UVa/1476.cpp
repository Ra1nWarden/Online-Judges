#include <cstdio>
#include <algorithm>
#include <cmath>

using namespace std;

const int maxn = 10000;
int n;
int av[maxn+5];
int bv[maxn+5];
int cv[maxn+5];
double eps = 1e-10;

double f(double x) {
  double ans = x * x * av[0] + bv[0] * x + cv[0];
  for(int i = 1; i < n; i++)
    ans = max(ans, x * x * av[i] + bv[i] * x + cv[i]);
  return ans;
}

int main() {
  int tc;
  scanf("%d", &tc);
  while(tc--) {
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
      scanf("%d%d%d", &av[i], &bv[i], &cv[i]);
    }
    double l = 0.0, r = 1000;
    while(fabs(l - r) > eps) {
      double m1 = l + (r - l) / 3;
      double m2 = r - (r - l) / 3;
      double y1 = f(m1), y2 = f(m2);
      if(y1 < y2) {
	r = m2;
      } else {
	l = m1;
      }
    }
    printf("%.4lf\n", f(l));
  }
  return 0;
}
