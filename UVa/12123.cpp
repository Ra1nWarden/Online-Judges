#include <cstdio>
#include <cmath>
#include <algorithm>

using namespace std;

const int maxn = 1200;
const double eps = 1e-9;
const double pi = acos(-1);
int x[maxn+1], y[maxn+1];
double angles[maxn*2+5];
int n;

int main() {
  int kase = 1;
  while(scanf("%d", &n) != EOF && n) {
    for(int i = 0; i < n; i++) {
      scanf("%d %d", &x[i], &y[i]);
    }
    int illegal = 0;
    for(int i = 0; i < n; i++) {
      int idx = 0;
      for(int j = 0; j < n; j++) {
	if(j == i)
	  continue;
	angles[idx] = atan2(y[j] - y[i], x[j] - x[i]);
	if(angles[idx] < eps)
	  angles[idx] += 2 * pi;
	idx++;
      }
      sort(angles, angles + idx);
      for(int j = idx; j < idx * 2; j++) {
	angles[j] = angles[j - idx] + 2 * pi;
      }
      int k = 0;
      int ok = 0;
      for(int j = 0; j < idx; j++) {
	while(angles[k+1] - angles[j] <= pi / 2 - eps) {
	  k++;
	}
	ok += k - j;
      }
      illegal += (n - 1) * (n - 2) / 2 - ok;
    }
    printf("Scenario %d:\n", kase++);
    printf("There are %d sites for making valid tracks\n", n * (n - 1) * (n - 2) / 6 - illegal);
  }
  return 0;
}
