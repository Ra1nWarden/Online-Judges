#include <cstdio>
#include <algorithm>
#include <cmath>
#define MAXN 1005

using namespace std;

struct Point {
  int x, y;
  bool black;
  double rad;
  Point() {}
  bool operator<(const Point& p) const {
    return rad < p.rad;
  }
};

Point points[MAXN];
Point diff[MAXN];
int n, di;

int turn(Point p, Point q) {
  int res = p.x * q.y - p.y * q.x;
  if(res == 0)
    return 0;
  return res < 0 ? -1 : 1;
}

int main() {
  while(scanf("%d", &n) != EOF && n) {
    for(int i = 0; i < n; i++) {
      int b;
      scanf("%d %d %d", &points[i].x ,&points[i].y, &b);
      points[i].black = b == 1;
    }
    if(n <= 2) {
      printf("%d\n", n);
      continue;
    }
    int res = 0;
    for(int i = 0; i < n; i++) {
      di = 0;
      for(int j = 0; j < n; j++) {
	if(j == i)
	  continue;
	diff[di].x = points[j].x - points[i].x;
	diff[di].y = points[j].y - points[i].y;
	if(points[j].black) {
	  diff[di].x = - diff[di].x;
	  diff[di].y = - diff[di].y;
	}
	diff[di].rad = atan2(diff[di].y, diff[di].x);
	di++;
      }
      sort(diff, diff+di);
      int L = 0;
      int R = 0;
      int ans = 1;
      while(L < di) {
	if(R == L) {
	  ans++;
	  R = (R+1)%di;
	}
	while(R != L && turn(diff[L], diff[R]) >= 0) {
	  //printf("L=%d R=%D turn=%d\n", L, R, turn(diff[L], diff[R]));
	  ans++;
	  R = (R+1)%di;
	}
	res = max(res, ans);
	ans--;
	L++;
      }
    }
    printf("%d\n", res);
  }
  return 0;
}
