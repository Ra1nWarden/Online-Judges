#include <bits/stdc++.h>

using namespace std;

// @begin_lib
// @end_lib

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

struct Line {
  Point s, e;
  Line();
  Line(Point _s, Point _e);
  // returns intersection between lines
  // first == 0 -> same line
  // first == 1 -> parallel
  // first == 2 -> intersect, second is the point of intersection
  pair<int, Point> operator&(const Line& b) const;
};

// Intersection between lines(segs)
bool SegIntersectSeg(Line l1, Line l2);
bool LineIntersectSeg(Line l1, Line l2);

// Point on line(seg)
bool PointOnSeg(Point P, Line L);
bool PointOnLine(Point P, Line L);

// Point of normal between point and line(seg)
Point PointToLine(Point P, Line L);
Point PointToSeg(Point P, Line L);

// Distance between point and line(seg)
double DistanceToLine(Point P, Line L); 
double DistanceToSeg(Point P, Line L);

class NoRightTurnDiv2 {
public:
  vector <int> findPath(vector <int> x, vector <int> y) {
    vector<int> v;
    if(x.size() < 3)
      return v;
    for(int i = 0; i < x.size(); i++)
      v.push_back(i);
    do {
      // cout << "debug" << endl;
      // for(int i = 0; i < v.size(); i++)
      //  	cout << v[i] << " ";
      // cout << endl;
      bool ok = true;
      for(int i = 0; i < v.size() - 2; i++) {
	Point a(x[v[i]], y[v[i]]);
	Point b(x[v[i+1]], y[v[i+1]]);
	Point c(x[v[i+2]], y[v[i+2]]);
	if(turn(a, b, c) != 1) {
	  // cout << "not left turn" << endl;
	  // cout << a.x << "," << a.y << endl;
	  // cout << b.x << "," << b.y << endl;
	  // cout << c.x << "," << c.y << endl;
	  ok = false;
	  break;
	}
	Line seg(b, c);
	for(int j = 0; j < i; j++) {
	  Line seg2(Point(x[j], y[j]), Point(x[j+1], y[j+1]));
	  if(SegIntersectSeg(seg, seg2)) {
	    // cout << "intersect failure" << endl;
	    // cout << seg.s.x << ", " << seg.s.y << " -> " << seg.e.x << ", " <<  seg.e.y << endl;
	    // cout << seg2.s.x << ", " << seg2.s.y << " -> " << seg2.e.x << ", " <<  seg2.e.y << endl;
	    ok = false;
	    break;
	  }
	}
	if(!ok)
	  break;
      }
      if(ok)
	return v;
    } while(next_permutation(v.begin(), v.end()));
    v.clear();
    return v;
  }
};

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

Line::Line() {}

Line::Line(Point _s, Point _e) : s(_s), e(_e) {}

pair<int, Point> Line::operator&(const Line& b) const {
  Point res = s;
  if(sgn((s - e) ^ (b.s - b.e)) == 0) {
    if(sgn((s - b.e) ^ (b.s - b.e)) == 0)
      return make_pair(0, res);
    else
      return make_pair(1, res);
  }
  double t = ((s - b.s) ^ (b.s - b.e)) / ((s - e) ^ (b.s - b.e));
  res.x += (e.x - s.x) * t;
  res.y += (e.y - s.y) * t;
  return make_pair(2, res);
}

bool SegIntersectSeg(Line l1, Line l2) {
  return 
    max(l1.s.x,l1.e.x) >= min(l2.s.x,l2.e.x) &&
    max(l2.s.x,l2.e.x) >= min(l1.s.x,l1.e.x) &&
    max(l1.s.y,l1.e.y) >= min(l2.s.y,l2.e.y) &&
    max(l2.s.y,l2.e.y) >= min(l1.s.y,l1.e.y) &&
    sgn((l2.s-l1.e)^(l1.s-l1.e))*sgn((l2.e-l1.e)^(l1.s-l1.e)) <= 0 &&
    sgn((l1.s-l2.e)^(l2.s-l2.e))*sgn((l1.e-l2.e)^(l2.s-l2.e)) <= 0;
}

bool LineIntersectSeg(Line l1, Line l2) {
  return sgn((l2.s-l1.e)^(l1.s-l1.e))*sgn((l2.e-l1.e)^(l1.s-l1.e)) <= 0;
}

bool PointOnSeg(Point P, Line L) {
  return
    sgn((L.s-P)^(L.e-P)) == 0 &&
    sgn((P.x - L.s.x) * (P.x - L.e.x)) <= 0 &&
    sgn((P.y - L.s.y) * (P.y - L.e.y)) <= 0;
}

bool PointOnLine(Point P, Line L) {
  return PointOnSeg(P, L) || PointOnSeg(L.s, Line(P, L.e)) || PointOnSeg(L.e, Line(P, L.s));
}

Point PointToLine(Point P, Line L) {
  Point result;
  double t = ((P-L.s)*(L.e-L.s))/((L.e-L.s)*(L.e-L.s));
  result.x = L.s.x + (L.e.x-L.s.x)*t;
  result.y = L.s.y + (L.e.y-L.s.y)*t;
  return result;
}

Point PointToSeg(Point P, Line L) {
  Point result;
  double t = ((P-L.s)*(L.e-L.s))/((L.e-L.s)*(L.e-L.s));
  if(t >= 0 && t <= 1) {
    result.x = L.s.x + (L.e.x - L.s.x)*t;
    result.y = L.s.y + (L.e.y - L.s.y)*t;
  }
  else {
    if(dist(P,L.s) < dist(P,L.e))
      result = L.s;
    else result = L.e;
  }
  return result;
}

double DistanceToLine(Point P, Line L) {
  Point A = L.s, B = L.e;
  Point v1 = B - A, v2 = P - A;
  return fabs(v1 ^ v2) / dist(v1);
}

double DistanceToSeg(Point P, Line L) {
  Point A = L.s, B = L.e;
  if(A == B)
    return dist(A, P);
  Point v1 = B - A, v2 = P - A, v3 = P - B;
  if(sgn(v1 * v2) < 0)
    return dist(v2);
  else if (sgn(v1 * v3) > 0)
    return dist(v3);
  else
    return fabs(v1 ^ v2) / dist(v1);
}

// @begin_tests
void _print_res(ostream& str, vector< int > v) {
  bool first = 1;
  str << "{";
  for (vector< int >::iterator i = v.begin(); i != v.end(); i++) {
    if (first) {
      str << " ";
      first = 0;
    } else
      str << ", ";
    str << *i;
  }
  str << " }";
}
void _run_test(vector< int > x, vector< int > y, vector< int > res_expected, int test_no) {
vector< int > tc_res = (new NoRightTurnDiv2)->findPath(x, y);
if (tc_res == res_expected)
cout << "--- test " << test_no << ": ok ---" << endl;
else {
cout << "--- test " << test_no << ": failed ---" << endl;
cout << "expected: ";
_print_res(cout, res_expected);
cout << endl << "got: ";
_print_res(cout, tc_res);
cout << endl;
}
}
int main() {
vector< int > x;
vector< int > y;
vector< int > res_expected;
{int tmpa[] = {-10, 0, 10};
x.assign(tmpa, tmpa + 3);}
{int tmpa[] = {10, -10, 10};
y.assign(tmpa, tmpa + 3);}
{int tmpa[] = {0, 1, 2};
res_expected.assign(tmpa, tmpa + 3);}
_run_test(x, y, res_expected, 0);
{int tmpa[] = {0, 0, -3, -3, 3, 3};
x.assign(tmpa, tmpa + 6);}
{int tmpa[] = {-1, 1, -3, 3, -3, 3};
y.assign(tmpa, tmpa + 6);}
{int tmpa[] = {0, 4, 5, 3, 2, 1};
res_expected.assign(tmpa, tmpa + 6);}
_run_test(x, y, res_expected, 1);
{int tmpa[] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
x.assign(tmpa, tmpa + 10);}
{int tmpa[] = {1, 4, 9, 16, 25, 36, 49, 64, 81, 100};
y.assign(tmpa, tmpa + 10);}
{int tmpa[] = {9, 8, 7, 6, 5, 4, 3, 2, 1, 0};
res_expected.assign(tmpa, tmpa + 10);}
_run_test(x, y, res_expected, 2);
{int tmpa[] = {0, 2, -2, 4, -4, 2, -2, 0};
x.assign(tmpa, tmpa + 8);}
{int tmpa[] = {1, 2, 2, 4, 4, 6, 6, 5};
y.assign(tmpa, tmpa + 8);}
{int tmpa[] = {4, 2, 0, 1, 3, 5, 6, 7};
res_expected.assign(tmpa, tmpa + 8);}
_run_test(x, y, res_expected, 3);
{int tmpa[] = {-76, 98, 83, 58, -15, 94, 21, 55, 80, 84, -39, -90, -46, 100, -80, -49, -2, -70, 36, 48, 88, 10, 55, -56, 22, 67, 31, 81, 100, -39, 64, -62, -7, 45, -82, -24, 51, -33, 53, 11, 20, -74, -83, 47, 9, 39, 42, 63, -97, 94};
x.assign(tmpa, tmpa + 50);}
{int tmpa[] = {-90, 68, 91, -92, -6, 88, 99, 10, 39, -69, -61, -4, 71, -5, 90, -51, 21, -53, -21, -86, 41, -9, 42, -23, -4, 12, 94, -59, 55, 18, 70, -88, -86, -17, -97, -33, 87, 80, 91, -80, -79, -79, -78, -99, 57, 67, -52, -46, 61, -10};
y.assign(tmpa, tmpa + 50);}
{int tmpa[] = {39, 32, 40, 31, 19, 27, 47, 46, 0, 34, 43, 3, 9, 13, 28, 1, 5, 2, 6, 14, 48, 42, 41, 49, 20, 38, 26, 37, 12, 11, 17, 10, 33, 25, 8, 30, 36, 44, 29, 23, 15, 18, 7, 22, 45, 16, 4, 35, 24, 21};
res_expected.assign(tmpa, tmpa + 50);}
_run_test(x, y, res_expected, 4);
}
// @end_tests

// Born in Emacs
