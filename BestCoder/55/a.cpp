#include <cstdio>
#include <cmath>
#include <algorithm>
#define MAXN 10005
#define EPS 1e-8

using namespace std;

int av[MAXN], bv[MAXN];
int n;

int main() {
  int tc;
  scanf("%d", &tc);
  while(tc--) {
    scanf("%d", &n);
    double l = 0;
    double r = 0;
    for(int i = 0; i < n; i++) {
      scanf("%d", &av[i]);
      r = max(r, (double) av[i]);
    }
    double total = 0;
    for(int i = 0; i < n; i++) {
      scanf("%d", &bv[i]);
      total += av[i] * bv[i] * bv[i];
    }
    total /= 2;
    while(fabs(l - r) > EPS) {
      double m = (l + r) / 2;
      double sum = 0;
      for(int i = 0; i < n; i++) {
	if(m > av[i])
	  continue;
	double h = av[i] - m;
	double side = bv[i] * 1.0 / av[i] * h;
	sum += side * side * h;
      }
      if(sum > total) {
	l = m;
      } else {
	r = m;
      }
    }
    printf("%d\n", (int) l);
  }
  return 0;
}
