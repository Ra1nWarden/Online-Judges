#include <cstdio>
#include <algorithm>
#include <cmath>
#include <utility>
#include <cstring>
#define MAXN 1005

using namespace std;

const double EPS = 1e-8;
const double PI = acos(-1.0);

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

// determines whether p -> q -> r is a left/right turn
// 1 -> left turn
// -1 -> right turn
// 0 -> collinear
int turn(Point p, Point q, Point r);

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

// Intersection between lines(segs)
bool SegIntersectSeg(Line l1, Line l2);
bool LineIntersectSeg(Line l1, Line l2);

// Point on line(seg)
bool PointOnSeg(Point P, Line L);
bool PointOnLine(Point P, Line L);

// Point of normal between point and line(seg)
Point PointToLine(Point P, Line L);
Point PointToSeg(Point P, Line L);

// Distance between point and line(seg)
double DistanceToLine(Point P, Line L);
double DistanceToSeg(Point P, Line L);

int n;
Point pv[MAXN];

int main() {
  Point p;
  scanf("%d %lf %lf", &n, &p.x, &p.y);
  for(int i = 0; i < n; i++) {
    scanf("%lf %lf", &pv[i].x, &pv[i].y);
  }
  bool crossed[MAXN];
  memset(crossed, false, sizeof crossed);
  int res = 0;
  for(int i = 0; i < n; i++) {
    if(!crossed[i]) {
      crossed[i] = true;
      Line l(pv[i], p);
      res++;
      for(int j = 0; j < n; j++) {
	if(!crossed[j] && PointOnLine(pv[j], l)) {
	  crossed[j] = true;
	}
      }
    }
  }
  printf("%d\n", res);

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

int turn(Point p, Point q, Point r) {
  int res = (q - p) ^ (r - q);
  if(res == 0)
    return 0;
  else
    return res < 0 ? -1 : 1;
}

Line::Line() {}

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

bool LineIntersectSeg(Line l1, Line l2) {
  return sgn((l2.s-l1.e)^(l1.s-l1.e))*sgn((l2.e-l1.e)^(l1.s-l1.e)) <= 0;
}

bool PointOnSeg(Point P, Line L) {
  return
    sgn((L.s-P)^(L.e-P)) == 0 &&
    sgn((P.x - L.s.x) * (P.x - L.e.x)) <= 0 &&
    sgn((P.y - L.s.y) * (P.y - L.e.y)) <= 0;
}

bool PointOnLine(Point P, Line L) {
  return PointOnSeg(P, L) || PointOnSeg(L.s, Line(P, L.e)) || PointOnSeg(L.e, Line(P, L.s));
}

Point PointToLine(Point P, Line L) {
  Point result;
  double t = ((P-L.s)*(L.e-L.s))/((L.e-L.s)*(L.e-L.s));
  result.x = L.s.x + (L.e.x-L.s.x)*t;
  result.y = L.s.y + (L.e.y-L.s.y)*t;
  return result;
}

Point PointToSeg(Point P, Line L) {
  Point result;
  double t = ((P-L.s)*(L.e-L.s))/((L.e-L.s)*(L.e-L.s));
  if(t >= 0 && t <= 1) {
    result.x = L.s.x + (L.e.x - L.s.x)*t;
    result.y = L.s.y + (L.e.y - L.s.y)*t;
  }
  else {
    if(dist(P,L.s) < dist(P,L.e))
      result = L.s;
    else result = L.e;
  }
  return result;
}

double DistanceToLine(Point P, Line L) {
  Point A = L.s, B = L.e;
  Point v1 = B - A, v2 = P - A;
  return fabs(v1 ^ v2) / dist(v1);
}

double DistanceToSeg(Point P, Line L) {
  Point A = L.s, B = L.e;
  if(A == B)
    return dist(A, P);
  Point v1 = B - A, v2 = P - A, v3 = P - B;
  if(sgn(v1 * v2) < 0)
    return dist(v2);
  else if (sgn(v1 * v3) > 0)
    return dist(v3);
  else
    return fabs(v1 ^ v2) / dist(v1);
}
