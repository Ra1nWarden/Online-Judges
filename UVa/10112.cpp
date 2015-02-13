#include <cstdio>
#include <cmath>
#define MAXN 16
#define EPS 1e-8

using namespace std;

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

struct Line {
  Point s, e;
  Line();
  Line(Point _s, Point _e);
  // returns intersection between lines
  // first == 0 -> same line
  // first == 1 -> parallel
  // first == 2 -> intersect, second is the point of intersection
};

bool PointOnSeg(Point P, Line L);

int turn(Point p, Point q, Point r) {
  int res = (q - p) ^ (r - q);
  if(res == 0)
    return 0;
  else
    return res < 0 ? -1 : 1;
}

bool inTriangle(Point p, Point q, Point r, Point s) {
  int turn1 = turn(p, s, q);
  int turn2 = turn(q, s, r);
  int turn3 = turn(r, s, p);

  if(PointOnSeg(s, Line(p, q)) || PointOnSeg(s, Line(q, r)) || PointOnSeg(s, Line(r, p)))
    return true;
  return turn1 == turn2 && turn2 == turn3;
}

double areaTriangle(Point p, Point q, Point r) {
  return fabs(0.5 * ((q - p) ^ (r - p)));
}

Point points[MAXN];
int n;

int main() {
  while(scanf("%d\n", &n) != EOF && n) {
    for(int i = 0; i < n; i++) {
      char c;
      scanf("%c %lf %lf\n,", &c, &points[i].x, &points[i].y);
    }
    int maxi, maxj, maxk;
    double maxarea = 0.0;
    for(int i = 0; i < n; i++) {
      for(int j = i+1; j < n; j++) {
	for(int k = j+1; k < n; k++) {
	  bool ok = true;
	  for(int l = 0; l < n; l++) {
	    if(l == i || l == j || l == k)
	      continue;
	    if(inTriangle(points[i], points[j], points[k], points[l])) {
	      //printf("%d is in %d %d %d\n", l, i, j, k);
	      ok = false;
	      break;
	    }
	  }
	  if(ok) {
	    double area = areaTriangle(points[i], points[j], points[k]);
	    //printf("ok %d %d %d area is %.5f\n", i, j, k, area);
	    if(sgn(area - maxarea) >= 0) {
	      maxarea = area;
	      maxi = i;
	      maxj = j;
	      maxk = k;
	    }
	  }
	}
      }
    }
    printf("%c%c%c\n", 'A'+maxi, 'A'+maxj, 'A'+maxk);
    
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

Line::Line(Point _s, Point _e) : s(_s), e(_e) {}

bool PointOnSeg(Point P, Line L) {
  return
    sgn((L.s-P)^(L.e-P)) == 0 &&
    sgn((P.x - L.s.x) * (P.x - L.e.x)) <= 0 &&
    sgn((P.y - L.s.y) * (P.y - L.e.y)) <= 0;
}
