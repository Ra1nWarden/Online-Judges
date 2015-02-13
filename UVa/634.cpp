#include <cstdio>
#include <cmath>
#include <utility>
#include <algorithm>
#define MAXN 1001
#define EPS 1e-8

using namespace std;

int sgn(double x) {
  if(fabs(x) < EPS)
    return 0;
  else
    return x < 0 ? -1 : 1;
}

struct Point {
  double x, y;
  Point() {};
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

struct Line {
  Point s, e;
  Line() {};
  Line(Point _s, Point _e);
  // returns intersection between lines
  // first == 0 -> same line
  // first == 1 -> parallel
  // first == 2 -> intersect, second is the point of intersection
  pair<int, Point> operator&(const Line& b) const;
};

bool PointOnSeg(Point P, Line L);

bool SegIntersectSeg(Line l1, Line l2);

// return distance between a and b
double dist(Point a, Point b);
// return distance between p and origin
double dist(Point p);

// return unit normal vector
Point normal(Point A);

Point points[MAXN];
int n;

int inPoly(Point p) {
  int cnt;
  Line ray, side;
  cnt = 0;
  ray.s = p;
  ray.e.y = p.y;
  ray.e.x = -100000000000.0;

  for(int i=  0; i < n; i++) {
    side.s = points[i];
    side.e = points[(i+1)%n];

    if(PointOnSeg(p, side))
      return 0;
    if(sgn(side.s.y - side.e.y) == 0)
      continue;
    
    if(PointOnSeg(side.s, ray)) {
      if(sgn(side.s.y - side.e.y) > 0)
	cnt++;
    } else if (PointOnSeg(side.e, ray)) {
      if(sgn(side.e.y - side.s.y) > 0)
	cnt++;
    } else if (SegIntersectSeg(ray, side))
      cnt++;
  }
  if(cnt % 2 == 1)
    return 1;
  else return -1;
}

int main() {
  while(scanf("%d", &n) != EOF && n != 0) {
    for(int i = 0; i < n; i++) {
      scanf("%lf %lf", &points[i].x, &points[i].y);
    }
    Point p;
    scanf("%lf %lf", &p.x, &p.y);
    if(inPoly(p) >= 0)
      printf("T\n");
    else
      printf("F\n");
  }
  return 0;
}

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

pair<int, Point> Line::operator&(const Line& b) const {
  Point res = s;
  if(sgn((s - e) ^ (b.s - b.e)) == 0) {
    if(sgn((s - b.e) ^ (b.s - b.e)) == 0)
      return make_pair(0, res);
    else
      return make_pair(1, res);
  }
  double t = ((s - b.s) ^ (b.s - b.e)) / ((s - e) ^ (b.s - b.e));
  res.x += (e.x - s.x) * t;
  res.y += (e.y - s.y) * t;
  return make_pair(2, res);
}

bool SegIntersectSeg(Line l1, Line l2) {
  return 
    max(l1.s.x,l1.e.x) >= min(l2.s.x,l2.e.x) &&
    max(l2.s.x,l2.e.x) >= min(l1.s.x,l1.e.x) &&
    max(l1.s.y,l1.e.y) >= min(l2.s.y,l2.e.y) &&
    max(l2.s.y,l2.e.y) >= min(l1.s.y,l1.e.y) &&
    sgn((l2.s-l1.e)^(l1.s-l1.e))*sgn((l2.e-l1.e)^(l1.s-l1.e)) <= 0 &&
    sgn((l1.s-l2.e)^(l2.s-l2.e))*sgn((l1.e-l2.e)^(l2.s-l2.e)) <= 0;
}

bool PointOnSeg(Point P, Line L) {
  return
    sgn((L.s-P)^(L.e-P)) == 0 &&
    sgn((P.x - L.s.x) * (P.x - L.e.x)) <= 0 &&
    sgn((P.y - L.s.y) * (P.y - L.e.y)) <= 0;
}

