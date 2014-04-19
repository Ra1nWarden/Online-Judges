#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>
#include <cstdio>

using namespace std;

struct Point {
  Point(double a, double b) : x(a), y(b) {};
  double x;
  double y;
};

typedef Point Vector;

Vector operator+(const Vector& a, const Vector& b) {
  return Vector(a.x + b.x, a.y + b.y);
}

Vector operator-(const Vector& a, const Vector& b) {
  return Vector(a.x - b.x, a.y - b.y);
}

Vector operator*(const Vector& a, double p) {
  return Vector(a.x * p, a.y * p);
}

double Dot(const Vector& a, const Vector& b) {
  return a.x * b.x + a.y * b.y;
}

double Cross(const Vector& a, const Vector& b) {
  return a.x * b.y - a.y * b.x;
}

int solve(const Point& a, const Point& b, const Point& c, const Point& d) {
  int ans = 0;
  Vector ab = b - a, bc = c - b, cd = d - c, da = a - d;
  if (Cross(ab, cd) == 0 || Cross(da, bc) == 0)
    ans = 1;
  if (Cross(ab, cd) == 0 && Cross(da, bc) == 0) {
    ans = 2;
    Vector ac = c - a, bd = d - b;
    if (Dot(ac, bd) == 0)
      ans = 3;
    if (Dot(ab, bc) == 0)
      ans = 4;
    if (Dot(ac, bd) == 0 && Dot(ab, bc) == 0)
      ans = 5;
  }
  return ans;
}

int main() {
  int cases; 
  cin >> cases;
  for(int i = 0; i < cases; i++) {
    vector<Point> points;
    for(int j = 0; j < 4; j++) {
      double x, y;
      cin >> x >> y;
      Point onePoint(x, y);
      points.push_back(onePoint);
    }
    int ans = 0;
    ans = solve(points[0], points[1], points[2], points[3]);
    ans = max(ans, solve(points[0], points[2], points[1], points[3]));
    ans = max(ans, solve(points[0], points[1], points[3], points[2]));
    switch(ans) {
    case 0:
      printf("Case %d: Ordinary Quadrilateral\n", i+1);
      break;
    case 1:
      printf("Case %d: Trapezium\n", i+1);
      break;
    case 2:
      printf("Case %d: Parallelogram\n", i+1);
      break;
    case 3:
      printf("Case %d: Rhombus\n", i+1);
      break;
    case 4:
      printf("Case %d: Rectangle\n", i+1);
      break;
    case 5:
      printf("Case %d: Square\n", i+1);
      break;
    }
  }
  return 0;
}
