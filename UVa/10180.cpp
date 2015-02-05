#include <iostream>
#include <cmath>
#include <cstdio>
#define EPS 1e-7

using namespace std;

const double PI = acos(-1.0);

struct Point {
  double x, y;
  Point() {};
  Point(double _x, double _y) : x(_x), y(_y) {};
  Point operator-(const Point& b) const {
    return Point(x - b.x, y - b.y);
  };
  // cross product
  double operator^(const Point& b) const {
    return x * b.y - y * b.x;
  };
  // dot product
  double operator*(const Point& b) const {
    return x * b.x + y * b.y;
  };
};

Point o(0, 0);

double dist(Point& a, Point& b) {
  return sqrt((a-b) * (a-b));
};

struct Line {
  Point s, e;
  Line(Point a, Point b) : s(a), e(b) {};
};

Point PointToLine(Point& P,Line& L) {
  Point result;
  double t = ((P-L.s)*(L.e-L.s))/((L.e-L.s)*(L.e-L.s));
  result.x = L.s.x + (L.e.x-L.s.x)*t;
  result.y = L.s.y + (L.e.y-L.s.y)*t;
  return result;
}

double dist(Point& p, Line& l) {
  Point proj = PointToLine(p, l);
  return dist(p, proj);
}

double angle(Point a, Point b) {
  double ab = dist(a, b);
  double ao = dist(a, o);
  double bo = dist(b, o);
  return acos((ao * ao + bo * bo - ab * ab) / (2.0 * ao * bo));
}

bool touchCircle(Line& l, double r) {
  if(dist(o, l) >= r)
    return false;
  double a1 = angle(o - l.s, l.e - l.s);
  double a2 = angle(o - l.e, l.s - l.e);
  //cout << a1 << " and " << a2 << endl;
  //cout << fabs(a1 - PI) << " and " << fabs(a2 - PI) << endl;
  return (a1 + EPS < PI/2 && a2 + EPS < PI/2) || (fabs(a1 - PI) < EPS && fabs(a2 - PI) < EPS);
}

double totalLength(Point& a, Point& b, double r) {
  double biga = angle(a, b);
  //cout << "biga is " << biga << endl;
  double result = 0;
  double ao = dist(a, o);
  double bo = dist(b, o);
  result += sqrt(ao * ao - r * r);
  //cout << "after adding ao " << result << endl;
  result += sqrt(bo * bo - r * r);
  //cout << "after adding bo " << result << endl;
  double arcangle = biga - acos(r / ao) - acos(r / bo);
  result += r * arcangle;
  //cout << "after adding arclength " << result << endl;
  return result;
}

int main() {
  int tc;
  cin >> tc;
  while(tc--) {
    double x1, y1, x2, y2, r;
    cin >> x1 >> y1 >> x2 >> y2 >> r;
    Point a(x1, y1);
    Point b(x2, y2);
    Line l(a, b);
    if(touchCircle(l, r)) {
      //cout << "touched" << endl;
      printf("%.3f\n", totalLength(a, b, r));
    } else {
      //cout << "not touched" << endl;
      printf("%.3f\n", dist(a, b));
    }
  }
  return 0;
}
