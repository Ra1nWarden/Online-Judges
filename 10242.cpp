#include <iostream>
#include <cstdio>

using namespace std;

struct Point {
  double x, y;
  Point(double _x, double _y) : x(_x), y(_y) {};
  bool operator==(const Point& b) const {
    return x == b.x && y == b.y;
  };
};

int main() {
  double x1, y1, x2, y2, x3, y3, x4, y4;
  while(cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4) {
    Point a(x1, y1);
    Point b(x2, y2);
    Point c(x3, y3);
    Point d(x4, y4);
    double x, y;
    if(b == c) {
      printf("%.3f %.3f\n", a.x + d.x - b.x, a.y + d.y - b.y);
    } else if (b == d) {
      printf("%.3f %.3f\n", a.x + c.x - b.x, a.y + c.y - b.y);
    } else  if (a == c) {
      printf("%.3f %.3f\n", b.x + d.x - a.x, b.y + d.y - a.y);
    } else if (a == d) {
      printf("%.3f %.3f\n", b.x + c.x - a.x, b.y + c.y - a.y);
    }
  }
  return 0;
}
