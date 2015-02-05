#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <cstdio>
#define EPS 1e-8

using namespace std;

const double PI = acos(-1.0);

int sgn(double x) {
  if(fabs(x) < EPS)
    return 0;
  return x < 0 ? -1 : 1;
}

struct Point {
  double x, y;
  Point(double _x, double _y) : x(_x), y(_y) {};
  bool operator<(const Point& b) const {
    return x < b.x || (x == b.x && y < b.y);
  };
  bool operator==(const Point& b) const {
    return x == b.x && y == b.y;
  };
  Point operator-(const Point& b) const {
    return Point(x - b.x, y - b.y);
  };
  double operator^(const Point& b) const {
    return x * b.y - y * b.x;
  };
  double operator*(const Point& b) const {
    return x * b.x + y * b.y;
  };
};

struct Line {
  Point s, e;
  Line(Point _s, Point _e) : s(_s), e(_e) {};
  pair<int, Point> operator&(const Line& b) const {
    Point res = s;
    if(sgn((s - e) ^ (b.s - b.e)) == 0) {
      if(sgn((s - b.e) ^ (b.s - b.e)) == 0)
	return make_pair(0, res);
      else return make_pair(1, res);
    }
    double t = ((s - b.s) ^ (b.s - b.e)) / ((s - e) ^ (b.s - b.e));
    res.x += (e.x - s.x) * t;
    res.y += (e.y - s.y) * t;
    return make_pair(2, res);
  };
  bool online(Point& b) {
    Line l(s, b);
    return ((*this) & l).first == 0;
  };
};

int main() {
  int tc;
  cin >> tc;
  for(int i = 1; i <= tc; i++) {
    int pc;
    cin >> pc;
    vector<Point> points;
    for(int j = 0; j < pc; j++) {
      double x, y;
      cin >> x >> y;
      points.push_back(Point(x, y));
    }
    sort(points.begin(), points.end());
    vector<Point>::iterator itr = unique(points.begin(), points.end());
    points.erase(itr, points.end());
    bool matched[points.size()][points.size()];
    memset(matched, false, sizeof matched);
    int result = 2;
    for(int j = 0; j < points.size(); j++) {
      for(int k = j + 1; k < points.size(); k++) {
	if(matched[j][k])
	  continue;
	Point a = points[j];
	Point b = points[k];
	Line li(a, b);
	vector<int> colinearp;
	for(int l = k + 1; l < points.size(); l++) {
	  Point c = points[l];
	  if(li.online(c)) {
	    matched[j][l] = true;
	    matched[k][l] = true;
	    for(int m = 0; m < colinearp.size(); m++) {
	      matched[colinearp[m]][l] = true;
	    }
	    colinearp.push_back(l);
	  }
	}
	result = max(result, 2 + (int) colinearp.size());
      }
    }
    if(points.size() == 1)
      printf("Data set #%d contains a single gnu.\n", i);
    else
      printf("Data set #%d contains %lu gnus, out of which a maximum of %d are aligned.\n", i, points.size(), result);
  }
  return 0;
}
