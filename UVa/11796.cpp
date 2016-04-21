#include <cstdio>
#include <cmath>
#include <algorithm>
#include <utility>

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
  // rotate with respect to point p
  void transXY(double B, Point p);
};

// return distance between a and b
double dist(Point a, Point b);
// return distance between p and origin
double dist(Point p);

// return the angle between two points (vectors)
// from a to b in counter-clockwise direction
double angle(Point a, Point b);

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

const int maxn = 50;
Point a_points[maxn+5];
Point b_points[maxn+5];
int an, bn, ai, bi;
double min_dist, max_dist;

void update(Point p, Point a, Point b) {
  min_dist = min(min_dist, DistanceToSeg(p, Line(a, b)));
  max_dist = max(max_dist, dist(p, a));
  max_dist = max(max_dist, dist(p, b));
}

int main() {
  int tc;
  scanf("%d", &tc);
  for(int kase = 1; kase <= tc; kase++) {
    scanf("%d%d", &an, &bn);
    for(int i = 0; i < an; i++)
      scanf("%lf %lf", &a_points[i].x, &a_points[i].y);
    for(int i = 0; i < bn; i++)
      scanf("%lf %lf", &b_points[i].x, &b_points[i].y);
    double a_total = 0, b_total = 0;
    for(int i = 0; i < an - 1; i++)
      a_total += dist(a_points[i], a_points[i+1]);
    for(int i = 0; i < bn - 1; i++)
      b_total += dist(b_points[i], b_points[i+1]);
    ai = bi = 0;
    Point a_pos = a_points[0];
    Point b_pos = b_points[0];
    min_dist = 1e9;
    max_dist = 0;
    while(ai < an - 1 && bi < bn - 1) {
      Point next_a = a_points[ai+1];
      Point next_b = b_points[bi+1];
      double a_left = dist(a_pos, next_a);
      double b_left = dist(b_pos, next_b);
      double proportion = min(a_left / a_total, b_left / b_total);
      Point a_move = (next_a - a_pos) / a_left * proportion * a_total;
      Point b_move = (next_b - b_pos) / b_left * proportion * b_total;
      update(b_pos, a_pos, a_pos + a_move - b_move);
      a_pos = a_pos + a_move;
      b_pos = b_pos + b_move;
      if(a_pos == next_a)
	ai++;
      if(b_pos == next_b)
	bi++;
    }
    printf("Case %d: %.0lf\n", kase, max_dist - min_dist);
  }
  return 0;
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
  transXY(B, Point(0, 0));
}

void Point::transXY(double B, Point p) {
  double tx = x - p.x, ty = y - p.y;
  x = p.x + tx * cos(B) - ty * sin(B);
  y = p.y + tx * sin(B) + ty * cos(B);
}

double dist(Point a, Point b) {
  return sqrt((a - b) * (a - b));
}

double dist(Point p) {
  Point o(0.0, 0.0);
  return dist(o, p);
}

double angle(Point a, Point b) {
  double ans = acos((a * b) / dist(a) / dist(b)); // This is sufficient if any angle below PI is wanted.
  if((a ^ b) < 0)
    ans = 2 * PI - ans;
  return ans;
}

Point normal(Point A) {
  double L = dist(A);
  return Point(-A.y/L, A.x/L);
}

int turn(Point p, Point q, Point r) {
  double res = (q - p) ^ (r - q);
  if(fabs(res) < EPS)
    return 0;
  else
    return res < 0 ? -1 : 1;
}
