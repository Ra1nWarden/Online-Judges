#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
#define MAXN 55

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

double AreaPoint(Point a, Point b, Point c);

int n;
Point points[MAXN];
double dp[MAXN][MAXN];

int main() {
  int tc;
  scanf("%d", &tc);
  while(tc--) {
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
      scanf("%lf %lf\n", &points[i].x, &points[i].y);
    }

    for(int diff = 1; diff < n; diff++) {
      for(int i = 0; i < n; i++) {
	if(diff == 1) {
	  dp[i][(i+diff)%n] = 0;
	}
	else if(diff == 2) {
	  dp[i][(i+diff) % n] = AreaPoint(points[i], points[(i+1) %n], points[(i+2) %n]);
	} else {
	  dp[i][(i+diff) % n] = 2000000000;
	  for(int j = i+2; j <= i+diff; j++) {
	    double subres = max(AreaPoint(points[i], points[(i+1)%n], points[j % n]), dp[(i+1)%n][j%n]);
	    subres = max(subres, dp[j%n][i]);
	    dp[i][(i+diff)%n] = min(dp[i][(i+diff)%n], subres);
	  }
	}
      }
    }

    printf("%.1f\n", dp[0][n-1]);
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

double AreaPoint(Point a, Point b, Point c) {
  return fabs((b - a) ^ (c - a) * 0.5);
}
