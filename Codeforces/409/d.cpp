#include <cstdio>
#include <cmath>
#include <utility>
#include <algorithm>

using namespace std;

const int maxn = 1000;
const double eps = 1e-8;
const double pi = acos(-1);
int xv[maxn+5];
int yv[maxn+5];
int n;
double edge[maxn+5];
double angle[maxn+5];
double diff[maxn+5];

double len(int i, int j) {
  return sqrt(pow(yv[i] - yv[j], 2) + pow(xv[i] - xv[j], 2));
}

int main() {
  scanf("%d", &n);
  for(int i = 0; i < n; i++) {
    scanf("%d%d", &xv[i], &yv[i]);
  }
  double left = 0, right = -1;
  for(int i = 0; i < n; i++) {
    int ii = i;
    int jj = (i+1) % n;
    edge[i] = len(ii, jj);
    angle[i] = atan2(yv[jj] - yv[ii], xv[jj] - xv[ii]);
    if(angle[i] < 0) {
      angle[i] += 2 * pi;
    }
    if(fabs(right + 1) < eps)
      right = edge[i] / 2;
    else
      right = min(right, edge[i] / 2);
  }
  while(fabs(left - right) > eps) {
    double mid = (left + right) / 2;
    for(int i = 0; i < n; i++) {
      diff[i] = asin(mid / (edge[i] / 2));
    }
    bool ok = true;
    for(int i = 0; i < n; i++) {
      int ii = i;
      int jj = (i + 1) % n;
      double delta = angle[ii] - angle[jj];
      if(delta < 0)
	delta += 2 * pi;
      if(diff[ii] + diff[jj] - delta > eps) {
	ok = false;
	break;
      }
    }
    if(ok)
      left = mid;
    else
      right = mid;
  }
  printf("%.8lf\n", left);
  return 0;
}
