#include <iostream>
#include <sstream>
#include <vector>
#include <cmath>
#define EPS 1e-8

using namespace std;

const double PI = acos(-1.0);

int sgn(double x) {
  if(fabs(x) < EPS)
    return 0;
  else
    return x < 0 ? -1 : 1;
}

struct Point {
  double x, y;
  Point() {};
  Point(double _x, double _y) : x(_x), y(_y) {};
  double operator*(const Point& b) const {
    return x * b.x + y * b.y;
  };
  double operator^(const Point& b) const {
    return x * b.y - y * b.x;
  };
  Point operator-(const Point& b) const {
    return Point(x - b.x, y - b.y);
  };
  Point operator+(const Point& b) const {
    return Point(x + b.x, y + b.y);
  };
  Point operator*(double m) const {
    return Point(x * m, y * m);
  };
  Point operator/(double m) const {
    return Point(x / m, y / m);
  };
};

double dist(Point a, Point b) {
  return sqrt((a-b) * (a-b));
}

struct Line {
  Point s, e;
  Line() {};
  Line(Point _s, Point _e) : s(_s), e(_e) {};
  Point unitNormal() {
    double l = dist(s, e);
    Point p = s - e;
    return Point(-p.y/l, p.x/l);
  };
};

int main() {
  int tc;
  cin >> tc >> ws;
  string line;
  for(int c = 0; c < tc; c++) {
    if(c != 0)
      cout << endl;
    vector<Point> points;
    while(getline(cin, line)) {
      if(line.empty())
	break;
      stringstream ss(line.c_str());
      double x, y;
      ss >> x >> y;
      points.push_back(Point(x, y));
    }
    if(points.size() == 1) {
      cout << 1 << endl;
      continue;
    }
    int result = 1;
    for(int i = 0; i < points.size(); i++) {
      for(int j = i+1; j < points.size(); j++) {
	Point a = points[i];
	Point b = points[j];
	if(sgn(dist(a, b) - 5.0) > 0)
	  continue;
	Line l(a, b);
	double d = sqrt(2.5 * 2.5 - pow(dist(a, b)/2,2));
	Point o1 = (a + b) / 2 + (l.unitNormal() * d);
	Point o2 = (a + b) / 2 - (l.unitNormal() * d);
	Point os[] = {o1, o2};
	for(int k = 0; k < 2; k++) {
	  if(sgn(os[k].x) < 0 ||sgn(os[k].y) < 0)
	    continue;
	  int res = 2;
	  for(int m = 0; m < points.size(); m++) {
	    if(m == i || m == j)
	      continue;
	    Point nextp = points[m];
	    if(sgn(dist(nextp, os[k]) - 2.5) <= 0)
	      res++;
	  }
	  result = max(result, res);
	}
      }
    }
    cout << result << endl;
  }
  return 0;
}
