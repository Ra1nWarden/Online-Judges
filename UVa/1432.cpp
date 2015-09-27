#include <cstdio>
#include <algorithm>
#include <cmath>
#include <queue>
#define MAXN 5005
#define INF 2000000000
#define PI acos(-1)

using namespace std;

struct Point {
  int x, y;
  bool operator<(const Point& rhs) const {
    double cur = this->angle();
    double test = rhs.angle();
    if(cur != test)
      return cur < test;
    else
      return x * x + y * y < rhs.x * rhs.x + rhs.y * rhs.y;
  }
  int radius() {
    return x * x + y * y;
  }
  double angle() const {
    double res = atan2(y, x);
    if(res < 0)
      res += 2 * PI;
    return res;
  }
};

int n, k;
Point points[MAXN];
int radii[MAXN];

int main() {
  int kase = 1;
  while(~scanf("%d%d", &n, &k) && (n || k)) {
    for(int i = 0; i < n; i++) {
      scanf("%d%d", &points[i].x, &points[i].y);
      radii[i] = points[i].radius();
    }
    if(k == 1) {
      printf("Case #%d: 0.00\n", kase++);
      continue;
    }
    sort(points, points+n);
    sort(radii, radii+n);
    double ans = INF;
    for(int i = k-1; i < n; i++) {
      int radius = radii[i];
      queue<int> q;
      int idx = 0;
      for(int j = 0; j < 2 * n; j++) {
	int cur = points[idx].radius();
	if(cur <= radius) {
	  if(q.size() == k-1) {
	    int start = q.front();
	    while(!q.empty() && points[q.front()].angle() == points[start].angle()) {
	      q.pop();
	    }
	    double ang1 = points[start].angle();
	    double ang2 = points[idx].angle();
	    double angle = ang2 - ang1;
	    if(angle < 0)
	      angle += 2 * PI;
	    ans = min(ans, PI * radius * (angle / (2 * PI)));
	  }
	  q.push(idx);
	}
	idx = (idx + 1) % n;
      }
    }
    printf("Case #%d: %.2lf\n", kase++, ans);
  }
  return 0;
}
