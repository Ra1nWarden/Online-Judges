#include <iostream>
#include <vector>
#include <cmath>
#define EPS 1e-8

using namespace std;

const double PI = acos(-1.0);

struct Point {
  double x, y;
  Point() {};
  Point(double _x, double _y) : x(_x), y(_y) {};
  Point operator-(const Point& b) const {
    return Point(x - b.x, y - b.y);
  };
  double operator*(const Point& b) const {
    return x * b.x + y * b.y;
  };
  Point operator*(double m) const {
    return Point(x * m, y * m);
  };
  Point operator+(const Point& b) const {
    return Point(x + b.x, y + b.y);
  };
};

ostream& operator<<(ostream& oss, const Point& p) {
  oss << "(" << p.x << ", " << p.y << ")";
  return oss;
}

double dist(Point a, Point b) {
  return sqrt((b - a) * (b - a));
}

int dcmp(double x) {
  if(fabs(x) < EPS)
    return 0;
  else
    return x < 0 ? -1 : 1;
}

Point normal(Point p) {
  double l = dist(p, Point(0.0, 0.0));
  return Point(-(p.y/l), p.x/l);
}

int main() {
  int n;
  while(cin >> n && n) {
    double x, y;
    vector<Point> points;
    for(int i = 0; i < n; i++) {
      cin >> x >> y;
      points.push_back(Point(x, y));
    }
    double r;
    cin >> r;
    if(points.size() == 1) {
      cout << "The polygon can be packed in the circle." << endl;
      continue;
    }
    bool ok = false;
    for(int i = 0; i < points.size(); i++) {
      for(int j = i+1; j < points.size(); j++) {
	if(dcmp(dist(points[i], points[j]) - 2 * r) > 0) {
	  ok = false;
	  break;
	}
	Point mid((points[i].x + points[j].x) / 2, (points[i].y + points[j].y) / 2);
	Point norm = normal(points[j] - points[i]);
	double l = sqrt(r * r - pow(dist(points[i], points[j]) / 2, 2));
#ifdef _DEBUG
	cout << "mid is " << mid << endl;
	cout << "norm is " << norm << endl;
	cout << "length is " << l << endl;
#endif
	Point candidate[] = {mid + norm * l, mid - norm * l};
	for(int k = 0; k < 2; k++) {
	  Point center = candidate[k];
#ifdef _DEBUG
	  cout << "center is " << center << endl;
	  cout << "distance to " << i << " is " << dist(center, points[i]) << endl;
	  cout << "distance to "<< j << " is " << dist(center, points[j]) << endl;
#endif
	  ok = true;
	  for(int m = 0; m < points.size(); m++) {
	    if(m == i || m == j)
	      continue;
#ifdef _DEBUG
	    cout << "distance to m " << m << " is " << dist(center, points[m]) << endl;
#endif
	    if(dcmp(dist(center, points[m]) - r) > 0) {
	      ok = false;
	    }
	  }
	  if(ok)
	    break;
	}
	if(ok)
	  break;
      }
      if(ok)
	break;
    }
    cout << (ok ? "The polygon can be packed in the circle." : "There is no way of packing that polygon.") << endl;
  }
  return 0;
}
