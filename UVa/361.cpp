#include <cstdio>
#include <vector>
#include <cmath>
#include <algorithm>
#define MAXN 205

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

Point listr[MAXN], listc[MAXN], listo[MAXN];
int Stackr[MAXN], topr, Stackc[MAXN], topc;

bool _cmpc(Point p1, Point p2) {
  //printf("calling _cmp on %.1f %.1f and %.1f %.1f\n", p1.x, p1.y, p2.x, p2.y);
  double tmp = (p1 - listc[0]) ^ (p2 - listc[0]);
  if(sgn(tmp) > 0)
    return true;
  else if (sgn(tmp) == 0 && sgn(dist(p1, listc[0]) - dist(p2, listc[0])) <= 0)
    return true;
  else
    return false;
}

bool _cmpr(Point p1, Point p2) {
  //printf("calling _cmp on %.1f %.1f and %.1f %.1f\n", p1.x, p1.y, p2.x, p2.y);
  double tmp = (p1 - listr[0]) ^ (p2 - listr[0]);
  if(sgn(tmp) > 0)
    return true;
  else if (sgn(tmp) == 0 && sgn(dist(p1, listr[0]) - dist(p2, listr[0])) <= 0)
    return true;
  else
    return false;
}

void Grahamc(int n) {
  Point p0;
  int k = 0;
  p0 = listc[0];
  for(int i = 1; i < n; i++) {
    if((p0.y > listc[i].y) || (p0.y == listc[i].y && p0.x > listc[i].x)) {
      p0 = listc[i];
      k = i;
    }
  }
  swap(listc[k], listc[0]);
  //printf("n is %d\n", n);
  sort(listc+1, listc+n, _cmpc);
  if(n == 1) {
    topc = 1;
    Stackc[0] = 0;
    return;
  }
  Stackc[0] = 0;
  Stackc[1] = 1;
  topc = 2;
  if(n == 2) {
    return;
  }
  for(int i = 2; i < n; i++) {
    while(topc > 1 &&
	  sgn((listc[Stackc[topc-1]] - listc[Stackc[topc - 2]]) ^ (listc[i] - listc[Stackc[topc - 2]])) < 0) {
      topc--;
    }
    Stackc[topc++] = i;
  }
}

void Grahamr(int n) {
  Point p0;
  int k = 0;
  p0 = listr[0];
  for(int i = 1; i < n; i++) {
    if((p0.y > listr[i].y) || (p0.y == listr[i].y && p0.x > listr[i].x)) {
      p0 = listr[i];
      k = i;
    }
  }
  swap(listr[k], listr[0]);
  //printf("n is %d\n", n);
  sort(listr+1, listr+n, _cmpr);
  if(n == 1) {
    topr = 1;
    Stackr[0] = 0;
    return;
  }
  Stackr[0] = 0;
  Stackr[1] = 1;
  topr = 2;
  if(n == 2) {
    return;
  }
  for(int i = 2; i < n; i++) {
    while(topr > 1 &&
	  sgn((listr[Stackr[topr-1]] - listr[Stackr[topr - 2]]) ^ (listr[i] - listr[Stackr[topr - 2]])) < 0) {
      topr--;
    }
    Stackr[topr++] = i;
  }
}

int insidePoly(Point a, Point p[], int n) {
  if(n == 1) {
    return (a.x == p[0].x && a.y == p[0].y);
  } else if(n == 2) {
    return PointOnSeg(a, Line(p[0], p[1]));
  } else {
    int cnt;
    Line ray, side;
    cnt = 0;
    ray.s = a;
    ray.e.y = a.y;
    ray.e.x = -100000000000.0;
    for(int i = 0; i < n; i++) {
      side.s = p[i];
      side.e = p[(i+1)%n];

      if(PointOnSeg(a, side))
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
    else
      return -1;   
  }
  
}

int main() {
  int c, r, o;
  int tc = 1;
  while(scanf("%d %d %d", &c, &r, &o) != EOF && (c || r || o)) {
    for(int i = 0; i < c; i++)
      scanf("%lf %lf", &listc[i].x, &listc[i].y);
    for(int i = 0; i < r; i++)
      scanf("%lf %lf", &listr[i].x, &listr[i].y);
    for(int i=  0; i < o; i++)
      scanf("%lf %lf", &listo[i].x, &listo[i].y);
    bool csuc = false;
    if(c >= 3) {
      Grahamc(c);
      csuc = true;
    }
    bool rsuc = false;
    if(r >= 3) {
      Grahamr(r);
      rsuc = true;
    }
    Point cv[MAXN];
    if(csuc)
      for(int i = 0; i < topc; i++)
	cv[i] = listc[Stackc[i]];
    Point rv[MAXN];
    if(rsuc)
      for(int i = 0; i < topr; i++)
	rv[i] = listr[Stackr[i]];
    printf("Data set %d:\n", tc++);
    for(int i = 0; i < o; i++) {
      if(csuc && insidePoly(listo[i], cv, topc) >= 0) {
	printf("     Citizen at (%.0f,%.0f) is safe.\n", listo[i].x, listo[i].y);
      } else if(rsuc && insidePoly(listo[i], rv, topr) >= 0) {
	printf("     Citizen at (%.0f,%.0f) is robbed.\n", listo[i].x, listo[i].y);
      } else {
	printf("     Citizen at (%.0f,%.0f) is neither.\n", listo[i].x, listo[i].y);
      }
    }
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
