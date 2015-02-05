#include <iostream>
#include <vector>
#include <cmath>
#include <cstdio>
#define EPS 1e-9
#define INF 2e9

using namespace std;

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
  double operator*(const Point& b) const {
    return x * b.x + y * b.y;
  };
  // bool operator<(const Point& b) const {
  //   return x < b.x || (a.x == b.y && a.y < b.y);
  // };
};

struct Line {
  Point s, e;
  Line(Point _s, Point _e) : s(_s), e(_e) {};
};

double dist(Point a, Point b) {
  return sqrt((a - b) * (a - b));
}

Point NearestPointToLineSeg(Point p, Line l) {
  Point result;
  double t = ((p - l.s) * (l.e - l.s)) / ((l.e - l.s) * (l.e - l.s));
  if(t >= 0 && t <= 1) {
    result.x = l.s.x + (l.e.x - l.s.x) * t;
    result.y = l.s.y + (l.e.y - l.s.y) * t;
  } else {
    if(dist(p, l.s) < dist(p, l.e))
      result = l.s;
    else
      result = l.e;
  }
  return result;
}

// double dist(Point& p) {
//   return sqrt(p * p);
// }

// int dcmp(double x) {
//   if(fabs(x) < EPS)
//     return 0;
//   else
//     return x < 0 ? -1 : 1;
// }

// double DistanceToSegment(Point p, Point a, Point b) {
//   if(a == b)
//     return dist(p - a);
//   Point v1 = b - a, v2 = p - a, v3 = p - b;
//   if(dcmp(v1 * v2) < 0)
//     return dist(v2);
//   else if(dcmp(v1 * v3) > 0)
//     return dist(v3);
//   else
//     return fabs(v1 ^ v2) / dist(v1);
// }

int main() {
  double x, y;
  while(cin >> x >> y) {
    Point m(x, y);
    int seg;
    cin >> seg;
    vector<Point> points;
    double shortestl = INF;
    Point shortestp = m;
    for(int i = 0; i <= seg; i++) {
      cin >> x >> y;
      points.push_back(Point(x, y));
    }
    for(int i = 0; i < points.size() - 1; i++) {
      Point a = points[i];
      Point b = points[i+1];
      Line l(a, b);
      Point nextp = NearestPointToLineSeg(m, l);
      double nextl = dist(m, nextp) + EPS;
      if(nextl < shortestl) {
	shortestl = nextl;
	shortestp = nextp;
      }
    }
    printf("%.4f\n%.4f\n", shortestp.x, shortestp.y);
  }
  return 0;
}
