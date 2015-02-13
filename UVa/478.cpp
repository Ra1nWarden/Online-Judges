#include <iostream>
#include <cmath>
#include <sstream>
#define MAXN 20
#define EPS 1e-8

using namespace std;

struct Point {
  double x, y;
  Point() {};
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

double dist(Point a, Point b);
// return distance between p and origin
double dist(Point p);

// return unit normal vector
Point normal(Point A);

struct Line {
  Point s, e;
  Line() {};
  Line(Point _s, Point _e) : s(_s), e(_e) {};
};

struct Figure {
  char type;
  double radius;
  Point center;
  Point corners[3];
  Figure() {};
};

Figure figs[20];

int sgn(double x) {
  if(fabs(x) < EPS)
    return 0;
  else
    return x > 0 ? 1 : -1;
}

bool OnSeg(Point P, Line L) {
  return sgn((L.s - P) ^ (L.e - P)) == 0 &&
    sgn((P.x - L.s.x) * (P.x - L.e.x)) <= 0 &&
    sgn((P.y - L.s.y) * (P.y - L.e.y)) <= 0;
}

int inConvexPoly(Point a, Point p[], int n) {
  for(int i = 0; i < n; i++) {
    if(sgn((p[i] - a) ^ (p[(i+1) % n] - a)) < 0)
      return -1;
    else if (OnSeg(a, Line(p[i], p[(i+1)%n])))
      return 0;
  }
  return 1;
}

int turn(Point p, Point q, Point r) {
  int result = (r.x  - q.x) * (p.y - q.y) - (r.y - q.y) * (p.x - q.x);
  if(result < 0) return -1;
  if(result > 0) return 1;
  return 0;
}

bool inTriangle(Point p, Point ps[]) {
  Point a = ps[0];
  Point b = ps[1];
  Point c = ps[2];
  int turn1 = turn(a, p, b);
  int turn2 = turn(b, p, c);
  int turn3 = turn(c, p, a);
  return (turn1 == turn2 && turn2 == turn3); 
}

int main() {
  string line;
  int index = 0;
  while(getline(cin, line)) {
    if(line[0] == '*')
      break;
    char shape;
    stringstream ss(line.c_str());
    ss >> shape;
    Figure fig;
    if(shape == 't') {
      fig.type = 't';
      ss >> fig.corners[0].x >> fig.corners[0].y >> fig.corners[1].x >> fig.corners[1].y >> fig.corners[2].x >> fig.corners[2].y;
    }
    if(shape == 'c') {
      fig.type = 'c';
      ss >> fig.center.x >> fig.center.y >> fig.radius;
    }
    if(shape == 'r') {
      fig.type = 'r';
      ss >> fig.corners[0].x >> fig.corners[0].y >> fig.corners[1].x >> fig.corners[1].y;
    }
    figs[index++] = fig;
  }
  double x, y;
  int pi = 1;
  while(cin >> x >> y) {
    if(x == 9999.9 && y == 9999.9)
      break;
    Point p(x, y);
    bool contained = false;
    for(int i = 0; i < index; i++) {
      Figure& nextfig = figs[i];
      if(nextfig.type == 'r' && sgn(x - nextfig.corners[0].x) > 0 && sgn(x - nextfig.corners[1].x) < 0 && sgn(y - nextfig.corners[1].y) > 0 && sgn(y - nextfig.corners[0].y) < 0) {
	contained = true;
	cout << "Point " << pi << " is contained in figure " << i+1 << endl;
      }
      if(nextfig.type == 'c' && sgn(dist(nextfig.center, p) - nextfig.radius) < 0) {
	contained = true;
	cout << "Point " << pi << " is contained in figure " << i+1 << endl;
      }
      if(nextfig.type == 't') {
	if(inTriangle(p, nextfig.corners)) {
	  contained = true;
	  cout << "Point " << pi << " is contained in figure " << i+1 << endl;
	}
      }
    }
    if(!contained)
      cout << "Point " << pi << " is not contained in any figure" << endl;
    pi++;
  }
  return 0;
}

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
