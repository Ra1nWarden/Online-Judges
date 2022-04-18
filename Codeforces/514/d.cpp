#include <cstdio>
#include <algorithm>
#include <cmath>
#include <climits>
#include <cfloat>

using namespace std;

const double eps = 1e-6;
const int maxn = 100000;
int n;
int xv[maxn+5];
int yv[maxn+5];

int main() {
  scanf("%d", &n);
  int sign = 0;
  bool ok = true;
  for(int i = 0; i < n; i++) {
    scanf("%d %d", &xv[i], &yv[i]);
    if(sign == 0) {
      sign = yv[i] > 0 ? 1 : -1;
    } else if(sign == 1) {
      if(yv[i] < 0) {
	ok = false;
      }
    } else if(sign == -1) {
      if(yv[i] > 0) {
	ok = false;
      }
    }
    if(yv[i] < 0)
      yv[i] = -yv[i];
  }
  if(!ok) {
    printf("-1\n");
    return 0;
  }
  double l = 0, r = 1e16;
  
  for(int i = 0; i < 150; i++) {
    double m = (l + r) / 2;
    //printf("m=%.7f\n", m);
    double start = -1e15, end = 1e15;
    bool ok = true;
    for(int i = 0; i < n; i++) {
      double a = abs(m - yv[i]);
      if(m - a < -eps) {
	ok = false;
      }
      double half = sqrt((m + a) * (m - a + eps));
      double starti = xv[i] - half + eps;
      double endi = xv[i] + half;
      start = max(start, starti);
      end = min(end, endi);
      if(end - start < -eps) {
	ok = false;
	break;
      }
    }
    if(ok) {
      r = m;
    } else {
      l = m;
    }
    //printf("l=%.7f r=%.7f\n", l , r);
  }
  printf("%.8f\n", l);
  return 0;
}
