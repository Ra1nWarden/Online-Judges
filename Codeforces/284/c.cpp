#include <cmath>
#include <iostream>
#include <cstdio>
#define EPS 1e-8

using namespace std;

struct Point {
  double x, y;
  Point() {};
  Point(double _x, double _y) : x(_x), y(_y) {};
  Point operator-(const Point& b) const {
    return Point(x - b.x, y - b.y);
  };
  double operator*(const Point& b) const {
    return x * b.x + y * b.y;
  };
  double operator^(const Point& b) const {
    return x * b.y - y * b.x;
  };
};

struct Line {
  Point s, e;
  Line() {};
  Line(Point _s, Point _e) : s(_s), e(_e) {};
};

ostream& operator<<(ostream& oss, const Line& l) {
  oss << "from (" << l.s.x << ", " << l.s.y << ") to (" << l.e.x << ", " << l.e.y << ")" << endl;
  return oss;
}

double sgn(double x) {
  //cout << "sign checking " << x << endl;
  if(fabs(x) < EPS)
    return 0;
  else
    return x < 0 ? -1 : 1;
}

bool Seg_intersect_line(Line l1, Line l2) {
  return sgn((l2.s - l1.e) ^ (l1.s - l1.e)) * sgn((l2.e-l1.e) ^ (l1.s-l1.e)) <= 0;
}

int main() {
  int x1, y1, x2, y2, n;
  scanf("%d %d %d %d %d", &x1, &y1, &x2, &y2, &n);
  Line seg(Point(x1, y1), Point(x2, y2));
  int result = 0;
  for(int i = 0; i < n; i++) {
    int a, b, c;
    scanf("%d %d %d", &a, &b, &c);
    Line l;
    if(a == 0) {
      l = Line(Point(1.0, -(double)c / b), Point(-1.0, -(double)c / b));
    } else if (b == 0) {
      l = Line(Point(-(double)c / a, 1.0), Point(-(double)c / a, -1.0));
    } else {
      l = Line(Point(1.0, (-(double)c  - a) / b), Point(-1.0, (-(double)c + a) / b));
    }
    //cout << "line is " << l << endl;
    //cout << l.s.x * a + l.s.y * b + c << endl;
    //cout << l.e.x * a + l.e.y * b + c << endl;
    if(Seg_intersect_line(l, seg))
      result++;
  }
  printf("%d\n", result);
  return 0;
}
