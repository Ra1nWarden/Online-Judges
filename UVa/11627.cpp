#include <cstdio>
#include <utility>
#include <algorithm>
#define MAXN 100005
#define MAXS 1000005

using namespace std;

typedef pair<double, double> Point;
int n, s;
double v, w;
Point points[MAXN];
int speeds[MAXS];

bool ok(double speed) {
  double left = points[0].first;
  double right = left + w;
  for(int i = 1; i < n; i++) {
    double vertical = points[i].second - points[i-1].second;
    double time = vertical / speed;
    double ll = left - v * time;
    double rr = right + v * time;
    if(rr < points[i].first || ll > points[i].first + w)
      return false;
    left = max(ll, points[i].first);
    right = min(rr, points[i].first + w);
  }
  return true;
}

int main() {
  int tc;
  scanf("%d", &tc);
  while(tc--) {
    scanf("%lf %lf %d", &w, &v, &n);
    for(int i = 0; i < n; i++) {
      scanf("%lf %lf", &points[i].first, &points[i].second);
    }
    scanf("%d", &s);
    for(int i = 0; i < s; i++) {
      scanf("%d", &speeds[i]);
    }
    sort(speeds, speeds + s);
    int l = 0, r = s;
    while(l + 1 < r) {
      int m = l + (r - l) / 2;
      if(ok(speeds[m])) {
	l = m;
      } else {
	r = m;
      }
    }
    if(ok(speeds[l])) {
      printf("%d\n", speeds[l]);
    } else {
      printf("IMPOSSIBLE\n");
    }
  }
  return 0;
}
