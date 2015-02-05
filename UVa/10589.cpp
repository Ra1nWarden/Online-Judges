#include <iostream>
#include <cmath>
#include <cstdio>
#define EPS 1e-14

using namespace std;

struct Point {
  double x, y;
  Point() {};
  Point(double _x, double _y) : x(_x), y(_y) {};
  double operator*(const Point& b) const {
    return x * b.x + y * b.y;
  };
  Point operator-(const Point& b) const {
    return Point(x - b.x, y - b.y);
  };
};

const double PI = acos(-1.0);

double dist(Point a, Point b) {
  return (a - b) * (a - b);
}

double sgn(double x) {
  if(fabs(x) < EPS)
    return 0;
  else
    return x < 0 ? -1 : 1;
}
 
int main() {
  int n;
  double a;
  while(cin >> n >> a && (n || a)) {
    int inside = 0;
    Point corner[] = {Point(0, 0), Point(0, a), Point(a, 0), Point(a, a)};
    for(int i = 0; i < n; i++) {
      double x, y;
      cin >> x >> y;
      Point p(x, y);
      bool ok = true;
      for(int j = 0; j < 4; j++) {
	if(sgn(dist(corner[j], p) - a * a) > 0) {
	  ok = false;
	  break;
	}
      }
      if(ok)
	inside++;
    }
    printf("%.5f\n", a * a * inside / n);
  }
  return 0;
}
