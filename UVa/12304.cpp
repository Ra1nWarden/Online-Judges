#include <iostream>
#include <cmath>
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

// Adjust the epsilon if necessary
const double EPS = 1e-6;
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
  Point unit();
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

struct Circle {
  Point center;
  double radius;
  Circle(Point c, double r);
  int getLineIntersection(Line l, vector<Point>& intersections);
  // -1 means two circles overlap
  int getCircleIntersection(Circle c, vector<Point>& intersections);
  int getLineTangents(Point p, vector<Line>& tangents);
  // -1 means two circles overlap
  int getCircleTangents(Circle c, vector<Line>& tangents);
  Point angleOnCircle(double a);
  bool operator<(const Circle& rhs) const;
};

// Do not use this if coordinates of the three points are provided
double AreaHeron(double a, double b, double c);
// A more precise calculation of area of triangle
double AreaPoint(Point a, Point b, Point c);
// Radius of inner circle given the area and perimeter
double InnerRadius(double area, double perimeter);
// Radius of outer circle given the area and length of the sides
double OuterRadius(double area, double a, double b, double c);
// Origin of outer radius
Point OuterCircleCenter(Point a, Point b, Point c);
// Returns the length of other side c
double CosineRule(double a, double b, double angle); // angle is the angle between side a and side b
// Returns the length of side B
double SineRule(double a, double A, double B); // A is the angle opposite of side A
// Returns whether the triangle ABC contains point p
// -1 -> p is not in the triangle
// 0 -> p is on the side of the triangle
// 1 -> p is inside the triangle
int TriangleContainsPoint(Point a, Point b, Point c, Point p);
// Center of mass of triangle
Point CenterOfMass(Point a, Point b, Point c);
// Find circumscribed circle given the points
Circle CircumscribedCircle(Point p1, Point p2, Point p3);
// Find inscribed circle given the points
Circle InscribedCircle(Point p1, Point p2, Point p3);


int main() {
  ios::sync_with_stdio(false);
  string cmd;
  while(cin >> cmd) {
    if(cmd == "CircumscribedCircle") {
      double x1, y1, x2, y2, x3, y3;
      cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
      Circle circle = CircumscribedCircle(Point(x1, y1), Point(x2, y2), Point(x3, y3));
      printf("(%.6lf,%.6lf,%.6lf)\n", circle.center.x, circle.center.y, circle.radius);
    } else if(cmd == "InscribedCircle") {
      double x1, y1, x2, y2, x3, y3;
      cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
      Circle circle = InscribedCircle(Point(x1, y1), Point(x2, y2), Point(x3, y3));
      printf("(%.6lf,%.6lf,%.6lf)\n", circle.center.x, circle.center.y, circle.radius);
    } else if(cmd == "TangentLineThroughPoint") {
      double x1, y1, r1, x2, y2;
      cin >> x1 >> y1 >> r1 >> x2 >> y2;
      Circle circle(Point(x1, y1), r1);
      vector<Line> tangents;
      Point p(x2, y2);
      circle.getLineTangents(p, tangents);
      vector<double> ans;
      for(int i = 0; i < tangents.size(); i++) {
	double dy = tangents[i].e.y - tangents[i].s.y;
	double dx = tangents[i].e.x - tangents[i].s.x;
	double each = atan2(dy, dx);
	if(each < 0)
	  each += PI;
	if(sgn(each - PI) == 0)
	  each = 0;
	ans.push_back(each);
      }
      sort(ans.begin(), ans.end());
      printf("[");
      for(int i = 0; i < ans.size(); i++) {
	if(i)
	  printf(",");
	printf("%.6lf", ans[i] / PI * 180);
      }
      printf("]\n");
    } else if(cmd == "CircleThroughAPointAndTangentToALineWithRadius") {
      double xp, yp, x1, y1, x2, y2, r;
      cin >> xp >> yp >> x1 >> y1 >> x2 >> y2 >> r;
      Point p(xp, yp);
      Point s(x1, y1);
      Point e(x2, y2);
      Circle c(p, r);
      vector<Point> ans;
      Point ss = s;
      ss.transXY(PI / 2, e);
      Line ls(e, ss);
      Point ee = e;
      ee.transXY(-PI / 2, s);
      Line le(s, ee);
      Point e1 = e + ls.unit() * r;
      Point s1 = s + le.unit() * r;
      Line l1(s1, e1);
      c.getLineIntersection(l1, ans);
      ss = s;
      ss.transXY(-PI / 2, e);
      Line lss(e, ss);
      ee = e;
      ee.transXY(PI / 2, s);
      Line lee(s, ee);
      Point e2 = e + lss.unit() * r;
      Point s2 = s + lee.unit() * r;
      Line l2(s2, e2);
      c.getLineIntersection(l2, ans);
      printf("[");
      sort(ans.begin(), ans.end());
      for(int i = 0; i < ans.size(); i++) {
	if(i)
	  printf(",");
	printf("(%.6lf,%.6lf)", ans[i].x, ans[i].y);
      }
      printf("]\n");
    } else if(cmd == "CircleTangentToTwoLinesWithRadius") {
      double x1, y1, x2, y2, x3, y3, x4, y4, r;
      cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4 >> r;
      Point p1(x1, y1);
      Point p2(x2, y2);
      Point p3(x3, y3);
      Point p4(x4, y4);
      Point p22 = p2;
      p22.transXY(PI / 2, p1);
      Line ll1(p1, p22);
      Point p1u = p1 + ll1.unit() * r;
      Point p11 = p1;
      p11.transXY(-PI / 2, p2);
      Line ll2(p2, p11);
      Point p2u = p2 + ll2.unit() * r;
      Line l1(p1u, p2u);
      p22 = p2;
      p22.transXY(-PI / 2, p1);
      ll1 = Line(p1, p22);
      Point p1d = p1 + ll1.unit() * r;
      p11 = p1;
      p11.transXY(PI / 2, p2);
      ll2 = Line(p2, p11);
      Point p2d = p2 + ll2.unit() * r;
      Line l2(p1d, p2d);
      Point p44 = p4;
      p44.transXY(PI / 2, p3);
      Line ll3(p3, p44);
      Point p3u = p3 + ll3.unit() * r;
      Point p33 = p3;
      p33.transXY(-PI / 2, p4);
      Line ll4(p4, p33);
      Point p4u = p4 + ll4.unit() * r;
      Line l3(p3u, p4u);
      p44 = p4;
      p44.transXY(-PI / 2, p3);
      ll3 = Line(p3, p44);
      Point p3d = p3 + ll3.unit() * r;
      p33 = p3;
      p33.transXY(PI / 2, p4);
      ll4 = Line(p4, p33);
      Point p4d = p4 + ll4.unit() * r;
      Line l4(p3d, p4d);
      vector<Point> ans;
      pair<int, Point> p1p3 = l1 & l3;
      if(p1p3.first == 2)
	ans.push_back(p1p3.second);
      pair<int, Point> p1p4 = l1 & l4;
      if(p1p4.first == 2)
	ans.push_back(p1p4.second);
      pair<int, Point> p2p3 = l2 & l3;
      if(p2p3.first == 2)
	ans.push_back(p2p3.second);
      pair<int, Point> p2p4 = l2 & l4;
      if(p2p4.first == 2)
	ans.push_back(p2p4.second);
      printf("[");
      sort(ans.begin(), ans.end());
      for(int i = 0; i < ans.size(); i++) {
	if(i)
	  printf(",");
	printf("(%.6lf,%.6lf)", ans[i].x, ans[i].y);
      }
      printf("]\n");
    } else if(cmd == "CircleTangentToTwoDisjointCirclesWithRadius") {
      double x1, y1, r1, x2, y2, r2, r;
      cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2 >> r;
      Circle c1(Point(x1, y1), r1 + r);
      Circle c2(Point(x2, y2), r2 + r);
      vector<Point> ans;
      c1.getCircleIntersection(c2, ans);
      printf("[");
      sort(ans.begin(), ans.end());
      for(int i = 0; i < ans.size(); i++) {
	if(i)
	  printf(",");
	printf("(%.6lf,%.6lf)", ans[i].x, ans[i].y);
      }
      printf("]\n");
    }
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

Line::Line() {}

Line::Line(Point _s, Point _e) : s(_s), e(_e) {}

Point Line::unit() {
  Point ret = e - s;
  double length = sqrt(ret.x * ret.x + ret.y * ret.y);
  ret.x /= length;
  ret.y /= length;
  return ret;
}

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


double AreaHeron(double a, double b, double c) {
  double s = 0.5 * (a + b + c);
  return sqrt(s * (s - a) * (s - b) * (s - c));
}

double AreaPoint(Point a, Point b, Point c) {
  return fabs((b - a) ^ (c - a) * 0.5);
}

double InnerRadius(double area, double perimeter) {
  return area / (perimeter * 0.5);
}

double OuterRadius(double area, double a, double b, double c) {
  return (a * b * c) / (4 * area);
}

Point OuterCircleCenter(Point a, Point b, Point c) {
  double a1 = b.x - a.x, b1 = b.y - a.y, c1 = (a1 * a1 + b1 * b1) / 2;
  double a2 = c.x - a.x, b2 = c.y - a.y, c2 = (a2 * a2 + b2 * b2) / 2;
  double d = a1 * b2 - a2 * b1;
  return Point(a.x + (c1 * b2 - c2 * b1) / d, a.y + (a1 * c2 - a2 * c1) / d);
}

double CosineRule(double a, double b, double angle) {
  return sqrt(a * a + b * b - cos(angle) * 2 * a * b);
}

double SineRule(double a, double A, double B) {
  return a / sin(A) * sin(B);
}

int TriangleContainsPoint(Point a, Point b, Point c, Point p) {
  if(PointOnSeg(p, Line(a, b)) || PointOnSeg(p, Line(b, c)) || PointOnSeg(p, Line(a, c)))
    return 0;
  int turn1 = turn(a, p, b);
  int turn2 = turn(b, p, c);
  int turn3 = turn(c, p, a);
  if(turn1 == turn2 && turn2 == turn3)
    return 1;
  else
    return -1;
}

Point CenterOfMass(Point a, Point b, Point c) {
  return (a + b + c) / 3;
}

Circle CircumscribedCircle(Point p1, Point p2, Point p3) {
  double Bx = p2.x - p1.x;
  double By = p2.y - p1.y;
  double Cx = p3.x - p1.x;
  double Cy = p3.y - p1.y;
  double D = 2 * (Bx * Cy - By * Cx);
  double cx = (Cy * (Bx * Bx + By * By) - By * (Cx * Cx + Cy * Cy)) / D + p1.x;
  double cy = (Bx * (Cx * Cx + Cy * Cy) - Cx * (Bx * Bx + By * By)) / D + p1.y;
  Point p(cx, cy);
  return Circle(p, dist(p, p1));
}

Circle InscribedCircle(Point p1, Point p2, Point p3) {
  double a = dist(p2, p3);
  double b = dist(p3, p1);
  double c = dist(p1, p2);
  Point p = (p1 * a + p2 * b + p3 * c) / (a + b + c);
  return Circle(p, DistanceToLine(p, Line(p1, p2)));
}


Circle::Circle(Point c, double r) : center(c), radius(r) {}

int Circle::getLineIntersection(Line l, vector<Point>& intersections) {
  double dist = DistanceToLine(center, l);
  int sg = sgn(dist - radius);
  if(sg < 0) {
    Point foot = PointToLine(center, l);
    double offset = sqrt(radius * radius - dist * dist);
    Point unit = l.unit();
    intersections.push_back(foot + unit * offset);
    intersections.push_back(foot - unit * offset);
    return 2;
  } else if(sg == 0) {
    Point foot = PointToLine(center, l);
    intersections.push_back(foot);
    return 1;
  } else {
    return 0;
  }
}

int Circle::getCircleIntersection(Circle c, vector<Point>& intersections) {
  double cc = dist(c.center, center);
  if(sgn(cc) == 0) {
    if(sgn(c.radius - radius) == 0)
      return -1;
    return 0;
  }
  if(sgn(radius + c.radius - cc) < 0)
    return 0;
  if(sgn(fabs(radius - c.radius) - cc) > 0)
    return 0;
  Point dir = c.center - center;
  double a = atan2(dir.y, dir.x);
  double da = acos((radius * radius + cc * cc - c.radius * c.radius) / (2 * radius * cc));
  Point p1 = angleOnCircle(a - da), p2 = angleOnCircle(a + da);
  intersections.push_back(p1);
  if(p1 == p2)
    return 1;
  intersections.push_back(p2);
  return 2;
}

int Circle::getLineTangents(Point p, vector<Line>& tangents) {
  Point u = center - p;
  double dis = dist(u);
  int sg = sgn(dis - radius);
  if(sg < 0) {
    return 0;
  } else if(sg == 0) {
    u.transXY(PI / 2);
    tangents.push_back(Line(p, p+u));
    return 1;
  } else {
    double a = asin(radius / dis);
    u.transXY(a);
    tangents.push_back(Line(p, p+u));
    u.transXY(-2 * a);
    tangents.push_back(Line(p, p+u));
    return 2;
  }
}

int Circle::getCircleTangents(Circle c, vector<Line>& tangents) {
  int cnt = 0;
  if(radius < c.radius) {
    return c.getCircleTangents(*this, tangents);
  }
  double d2 = (center.x - c.center.x) * (center.x - c.center.x) + (center.y - c.center.y) * (center.y - c.center.y);
  double rdiff = radius - c.radius;
  double rsum = radius + c.radius;
  if(sgn(d2 - rdiff * rdiff) < 0)
    return 0;
  double base = atan2(c.center.y - center.y, c.center.x - center.x);
  if(sgn(d2) == 0 && sgn(radius - c.radius) == 0)
    return -1;
  if(sgn(d2 - rdiff * rdiff) == 0) {
    Line l1(angleOnCircle(base), c.angleOnCircle(base));
    cnt++;
    tangents.push_back(l1);
    return cnt;
  }
  double ang = acos((radius - c.radius) / sqrt(d2));
  Line l2(angleOnCircle(base + ang), c.angleOnCircle(base + ang));
  cnt++;
  tangents.push_back(l2);
  Line l3(angleOnCircle(base - ang), c.angleOnCircle(base - ang));
  cnt++;
  tangents.push_back(l3);
  if(sgn(d2 - rsum * rsum) == 0) {
    Line l4(angleOnCircle(base), c.angleOnCircle(PI + base));
    cnt++;
    tangents.push_back(l4);
  } else if(sgn(d2 - rsum * rsum) > 0) {
    ang = acos((radius + c.radius) / sqrt(2));
    Line l5(angleOnCircle(base + ang), c.angleOnCircle(PI + base + ang));
    cnt++;
    tangents.push_back(l5);
    Line l6(angleOnCircle(base - ang), c.angleOnCircle(PI + base - ang));
    cnt++;
    tangents.push_back(l6);
  }
  return cnt;
}

Point Circle::angleOnCircle(double a) {
  return Point(center.x + cos(a) * radius, center.y + sin(a) * radius);
}

bool Circle::operator<(const Circle& rhs) const {
  if(center.x != rhs.center.x)
    return center.x < rhs.center.x;
  if(center.y != rhs.center.y)
    return center.y < rhs.center.y;
  if(radius != rhs.radius)
    return radius < rhs.radius;
  return false;
}
