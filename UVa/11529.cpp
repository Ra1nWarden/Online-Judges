#include <cstdio>
#include <cmath>
#include <algorithm>

using namespace std;

const int maxn = 1200;
const double eps = 1e-8;
const double pi = acos(-1);
int x[maxn+1], y[maxn+1];
double angles[2*maxn+5];
int n;

long long choose(long long m, long long n) {
  if(n > m)
    return 0;
  if(n > m / 2)
    return choose(m, m - n);
  long long ans = 1;
  for(long long div = 1; div <= n; div++) {
    ans *= (m - div + 1);
    ans /= div;
  }
  return ans;
}

int main() {
  int kase = 1;
  while(scanf("%d", &n) != EOF && n) {
    for(int i = 0; i < n; i++) {
      scanf("%d %d", &x[i], &y[i]);
    }
    long long illegal = 0;
    for(int i = 0; i < n; i++) {
      int idx = 0;
      for(int j = 0; j < n; j++) {
	if(j != i) {
	  angles[idx] = atan2(y[j] - y[i], x[j] - x[i]);
	  if(angles[idx] < eps)
	    angles[idx] += 2 * pi;
	  idx++;
	}
      }
      sort(angles, angles + idx);
      for(int j = idx; j < idx * 2; j++)
	angles[j] = angles[j - idx] + 2 * pi;
      int k = 0;
      for(int j = 0; j < idx; j++) {
	while(k < 2 * idx && angles[k] - angles[j] < pi) {
	  k++;
	}
	illegal += choose(k - j - 1, 2);
      }
    }
    long long total = choose(n - 1, 3) * n;
    total -= illegal;
    printf("City %d: %.2lf\n", kase++, (double) total / choose(n, 3));
  }
  return 0;
}
