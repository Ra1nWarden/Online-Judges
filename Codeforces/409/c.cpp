#include <cstdio>
#include <cmath>
#include <algorithm>

using namespace std;

const int maxn = 100000;
const double eps = 1e-8;
int p;
int av[maxn+5];
int bv[maxn+5];
int n;

int main() {
  scanf("%d%d", &n, &p);
  long long sum = 0;
  long long bat = 0;
  for(int i = 0; i < n; i++) {
    scanf("%d%d", &av[i], &bv[i]);
    sum += av[i];
    bat += bv[i];
  }
  if(sum <= p) {
    printf("-1\n");
    return 0;
  }
  double left = 0, right = (double) bat / (sum - p);
  while(fabs(left - right) > eps) {
    double mid = (left + right) / 2;
    double total = 0;
    for(int i = 0; i < n; i++) {
      total += max((double) 0, (mid * av[i] - bv[i]) / p);
    }
    if(mid - total > eps) {
      left = mid;
    } else {
      right = mid;
    }
  }
  printf("%.8lf\n", left + eps);
  return 0;
}
