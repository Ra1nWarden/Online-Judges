#include <cstdio>
#include <cmath>
#include <cstring>
#define MAXN 51
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

Point points[MAXN];
int n;

bool isConvex() {
  bool s[3];
  memset(s, false, sizeof s);
  for(int i = 0; i < n; i++) {
    s[sgn((points[(i+1)%n] - points[i]) ^ (points[(i+2)%n] - points[i])) + 1] = true;
    if(s[0] && s[2])
      return false;
  }
  return true;
}

int main() {
  while(scanf("%d", &n) != EOF && n) {
    for(int i = 0; i < n; i++) {
      scanf("%lf %lf", &points[i].x, &points[i].y);
    }
    if(isConvex()) 
      printf("No\n");
    else
      printf("Yes\n");
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
