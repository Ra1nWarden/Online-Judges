#include <cstdio>
#include <cmath>
#include <utility>
#define EPS 1e-9

using namespace std;

int sgn(double x);

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

// return distance between a and b
double dist(Point a, Point b);
// return distance between p and origin
double dist(Point p);

// return unit normal vector
Point normal(Point A);

struct Line {
  Point s, e;
  Line();
  Line(Point _s, Point _e);
  // returns intersection between lines
  // first == 0 -> same line
  // first == 1 -> parallel
  // first == 2 -> intersect, second is the point of intersection
  pair<int, Point> operator&(const Line& b) const;
};

int main() {
  double a, b, c, d, e, f;
  while(scanf("%lf %lf %lf %lf %lf %lf", &a, &b, &c, &d, &e, &f) != EOF) {
    Point x(a, b);
    Point y(c, d);
    Point z(e, f);
    Point xyn = normal(y - x);
    Point yzn = normal(z - y);
    Line l1((x+y) / 2, (x+y) / 2 + xyn);
    Line l2((y+z) / 2, (y+z) / 2 + yzn);
    Point center = (l1 & l2).second;
    double radius = dist(center, x);
    double num =  center.x*center.x + center.y*center.y - radius*radius;
    printf("(x %c %.3f)^2 + (y %c %.3f)^2 = %.3f^2\n", center.x > 0 ? '-' : '+', fabs(center.x), center.y > 0 ? '-' : '+', fabs(center.y), radius);
    printf("x^2 + y^2 %c %.3fx %c %.3fy %c %.3f = 0\n", center.x > 0 ? '-' : '+', 2*fabs(center.x), center.y > 0 ? '-' : '+', 2*fabs(center.y), num < 0 ? '-' : '+', fabs(num));
    printf("\n");
  }
  return 0;
}

int sgn(double x) {
  if(fabs(x) < EPS)
    return 0;
  else
    return x < 0 ? -1 : 1;
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

double dist(Point a, Point b) {
  return sqrt((a - b) * (a - b));
}

double dist(Point p) {
  Point o(0.0, 0.0);
  return dist(o, p);
}

Point normal(Point A) {
  double L = dist(A);
  return Point(-A.y/L, A.x/L);
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
