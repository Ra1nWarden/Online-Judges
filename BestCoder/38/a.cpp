#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <algorithm>

using namespace std;

const double EPS = 1e-8;
const double PI = acos(-1.0);

int sgn(double x);

struct Point {
  double x, y, z;
  Point();
  Point(double _x, double _y, double _z);
  Point operator-(const Point& b) const;
  double operator*(const Point& b) const;
};

// return distance between a and b
double dist(Point a, Point b);

Point points[4];
double sides[6];

int main() {
  int tc;
  scanf("%d", &tc);
  int kase = 1;
  while(tc--) {
    scanf("%lf %lf %lf %lf %lf %lf %lf %lf %lf %lf %lf %lf", &points[0].x, &points[0].y, &points[0].z, &points[1].x, &points[1].y, &points[1].z, &points[2].x, &points[2].y, &points[2].z, &points[3].x, &points[3].y, &points[3].z);
    int index = 0;
    for(int i = 0; i < 4; i++) {
      for(int j = i + 1; j < 4; j++) {
	sides[index++] = dist(points[i], points[j]);
      }
    }
    sort(sides, sides+6);
    bool square = true;
    for(int i = 1; i < 4; i++) {
      if(sgn(sides[i] - sides[i-1]) != 0) {
	square = false;
	break;
      }
    }
    if(square) {
      square = sgn(sides[4] - sides[3] * sqrt(2)) == 0;
    }
    if(square) {
      square = sgn(sides[4] - sides[5]) == 0;
    }
    if(square)
      printf("Case #%d: Yes\n", kase++);
    else
      printf("Case #%d: No\n", kase++);
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

Point::Point(double _x, double _y, double _z) : x(_x), y(_y), z(_z) {}

double dist(Point a, Point b) {
  return sqrt((a - b) * (a - b));
}

Point Point::operator-(const Point& b) const {
  return Point(x - b.x, y - b.y, z - b.z);
}

double Point::operator*(const Point& b) const {
  return x * b.x + y * b.y + z * b.z;
}
