#include <cstdio>
#include <algorithm>
#include <cmath>
#define EPS 1e-8
#define MAXN 200005

using namespace std;

int v[MAXN];
int n, w;

int main() {
  scanf("%d %d", &n, &w);
  for(int i = 0; i < 2 * n; i++) {
    scanf("%d", &v[i]);
  }
  sort(v, v+(2*n));
  double v0 = (double)v[0];
  double vn = (double)v[n];
  double l = 0, r = min(v0, (double) vn / 2) * 3 * n;
  while(fabs(l - r) > EPS) {
    double mid = (l + r) / 2;
    if(mid <= w) {
      l = mid;
    } else {
      r = mid;
    }
  }
  printf("%.7lf\n", l);
  return 0;
}
