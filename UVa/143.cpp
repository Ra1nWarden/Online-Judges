#include <cstdio>
#include <cmath>
//#include <iostream>
#define EPS 1e-9

using namespace std;

double xmin, xmax, ymin, ymax;

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
};

double dist(Point a, Point b) {
  return sqrt((a - b) * (a - b));
}

int sgn(double x) {
  if(fabs(x) < EPS)
    return 0;
  else
    return x < 0 ? -1 : 1;
}

double area(Point a, Point b, Point c) {
  return fabs(a.x * b.y + a.y * c. x + b.x * c.y - b.y * c.x - a.y * b.x - a.x * c.y);
}

int main() {
  double a, b, c, d, e, f;
  while(scanf("%lf %lf %lf %lf %lf %lf", &a, &b, &c, &d, &e, &f) != EOF && (a || b || c || d || e || f)) {
    xmin = fmin(a, fmin(c, e));
    ymin = fmin(b, fmin(d, f));
    xmax = fmax(a, fmax(c, e));
    ymax = fmax(b, fmax(d, f));
    Point x(a, b);
    Point y(c, d);
    Point z(e, f);
    int result = 0;
    for(int i = 1; i < 100; i++) {
      for(int j = 1; j < 100; j++) {
	if(i < xmin || i > xmax || j < ymin || j > ymax) {
	  continue;
	}
	Point p(i, j);
	double totalarea = area(x, y, p) + area(x, z, p) + area(y, z, p);
	if(sgn(totalarea - area(x, y, z)) == 0) {
	  result++;
	  //cout << "point found " << i << " " << j << endl;
	} // else if(fabs(totalarea - area(x, y, z)) < 1e-1) {
	//   cout << (totalarea - area(x, y, z)) << endl;
	//   cout << totalarea << " vs " << area(x, y, z) << endl;
	// }
      }
    }
    printf("%4d\n", result);
  }
  return 0;
}
