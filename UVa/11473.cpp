#include <cstdio>
#include <cmath>
#define MAXN 16
#define EPS 1e-8

using namespace std;

struct Point {
  double x, y;
  Point();
  Point(double _x, double _y);
  Point operator+(const Point& b) const;
  Point operator-(const Point& b) const;
  Point operator*(double m) const;
  Point operator/(double m) const;
  // cross product
  double operator^(const Point& b) const;
  // dot product
  double operator*(const Point& b) const;
  bool operator<(const Point& b) const;
  bool operator==(const Point& b) const;
  // rotate with respect to origin with B in radiant
  void transXY(double B);
};

int sgn(double x) {
  if(fabs(x) < EPS)
    return 0;
  else
    return x < 0 ? -1 : 1;
}

double dist(Point a, Point b);

struct Line {
  Point s, e;
  Line();
  Line(Point _s, Point _e);
  // returns intersection between lines
  // first == 0 -> same line
  // first == 1 -> parallel
  // first == 2 -> intersect, second is the point of intersection
};

bool PointOnSeg(Point P, Line L);

int turn(Point p, Point q, Point r) {
  int res = (q - p) ^ (r - q);
  if(res == 0)
    return 0;
  else
    return res < 0 ? -1 : 1;
}

Point points[MAXN];
int n;
int cnt;

int main() {
  int tc;
  scanf("%d", &tc);
  for(int et = 1; et <= tc; et++) {
    scanf("%d %d", &n, &cnt);
    double total = 0.0;
    for(int i = 0; i < n; i++) {
      scanf("%lf %lf", &points[i].x, &points[i].y);
      if(i > 0)
	total += dist(points[i], points[i-1]);
    }
    double step = total / (cnt - 1);
    printf("Road #%d:\n", et);
    printf("%.2f %.2f\n", points[0].x, points[0].y);
    Point prev = points[0];
    double stepres = step;
    for(int i = 1; i < n; i++) {
      Point next = points[i];
      while(sgn(dist(next, prev) - stepres) >= 0) {
	prev = prev + (next - prev) * stepres / dist(next, prev);
	printf("%.2f %.2f\n", prev.x, prev.y);
	stepres = step;
      }
      stepres -= dist(next, prev);
      prev = next;
    }
    printf("\n");
  }
  return 0;
}


Point::Point() {}

Point::Point(double _x, double _y) : x(_x), y(_y) {}

Point Point::operator-(const Point& b) const {
  return Point(x - b.x, y - b.y);
}

Point Point::operator+(const Point& b) const {
  return Point(x + b.x, y + b.y);
}

Point Point::operator*(double m) const {
  return Point(x * m, y * m);
}

Point Point::operator/(double m) const {
  return Point(x / m, y / m);
}

double Point::operator^(const Point& b) const {
  return x * b.y - y * b.x;
}

double Point::operator*(const Point& b) const {
  return x * b.x + y * b.y;
}

bool Point::operator<(const Point& b) const {
  return x < b.x || (x == b.x && y < b.y);
}

bool Point::operator==(const Point& b) const {
  return sgn(x - b.x) == 0 && sgn(y - b.y) == 0;
}

void Point::transXY(double B) {
  double tx = x, ty = y;
  x = tx * cos(B) - ty * sin(B);
  y = tx * sin(B) + ty * cos(B);
}

Line::Line(Point _s, Point _e) : s(_s), e(_e) {}

bool PointOnSeg(Point P, Line L) {
  return
    sgn((L.s-P)^(L.e-P)) == 0 &&
    sgn((P.x - L.s.x) * (P.x - L.e.x)) <= 0 &&
    sgn((P.y - L.s.y) * (P.y - L.e.y)) <= 0;
}

double dist(Point a, Point b) {
  return sqrt((a - b) * (a - b));
}
