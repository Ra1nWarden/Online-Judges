#include <cstdio>
#include <cmath>
#include <algorithm>
#define MAXN 10005

using namespace std;

int n, f;
double area[MAXN];
double PI = acos(-1.0);

bool ok(double a) {
  int sum = 0;
  for(int i = 0; i < n; i++) {
    sum += floor(area[i] / a);
  }
  return sum >= (f+1);
}

int main() {
  int tc;
  scanf("%d", &tc);
  while(tc--) {
    scanf("%d %d", &n, &f);
    double maxa = 0;
    for(int i = 0; i < n; i++) {
      int r;
      scanf("%d", &r);
      area[i] = PI * r * r;
      maxa = max(maxa, area[i]);
    }
    double start = 0;
    double end = maxa;
    while(fabs(end - start) > 1e-5) {
      double mid = (start+end) / 2;
      if(ok(mid)) {
	start = mid;
      } else {
	end = mid;
      }
    }
    printf("%.4f\n", start);
  }
  return 0;
}
