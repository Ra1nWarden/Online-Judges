#include <cstdio>
#include <set>
#include <cstring>
#include <cmath>
#define EPS 1e-8
#define PI acos(-1.0)

using namespace std;

struct Point {
  double x, y;
  Point();
  Point(double _x, double _y);
  void transXY(double B, Point p);
  double operator*(const Point& b) const;
  Point operator-(const Point& b) const;
};

int sgn(double x) {
  if(fabs(x) < EPS)
    return 0;
  else
    return x < 0 ? -1 : 1;
}

class double_compare {
public:
  bool operator() (const double& a, const double& b) {
    return sgn(a - b) < 0;
  }
};

double dist(Point a, Point b);

Point points[4];
Point pivots[4];

int main() {
  int tc;
  scanf("%d", &tc);
  while(tc--) {
    for(int i = 0; i < 4; i++) {
      scanf("%lf %lf %lf %lf", &points[i].x, &points[i].y, &pivots[i].x, &pivots[i].y);
    }
    int ans = -1;
    for(int i = 0; i < 256; i++) {
      int rotates[4];
      int icpy = i;
      for(int j = 0; j < 4; j++) {
	rotates[j] = icpy % 4;
	//printf("i=%d %d=%d\n", i, j, rotates[j]);
	icpy /= 4;
      }
      Point pointscpy[4];
      memcpy(pointscpy, points, sizeof points);
      for(int j = 0; j < 4; j++) {
	for(int k = 0; k < rotates[j]; k++) {
	  //printf("rotating %d\n", j);
	  pointscpy[j].transXY(PI / 2, pivots[j]);
	}
      }
      bool square = true;
    
      //printf("i = %d\n", i);
      set<double, double_compare> lines;
      for(int j = 0; j < 4; j++) {
	for(int k = j + 1; k < 4; k++) {
	  double length = dist(pointscpy[j], pointscpy[k]);
	  // printf("j: %lf %lf k: %lf %lf\n", pointscpy[j].x, pointscpy[j].y, pointscpy[k].x, pointscpy[k].y);
	  // printf("j=%d k=%d inserting %lf\n", j, k, length);
	  if(sgn(length - 0.0) > 0)
	    lines.insert(length);
	  else if(sgn(length - 0.0) == 0)
	    square = false;
	}
      }
      
      if(square && lines.size() == 2) {
	//printf("i = %d two length %lf and %lf\n", i, *lines.begin(), *(++lines.begin()));
	square = sgn(sqrt(pow(*lines.begin(), 2) * 2) - *(++lines.begin())) == 0;
      } else {
	//printf("false: size %d\n", lines.size());
	square = false;
      }


      if(square) {
	int rn = 0;
	for(int j = 0; j < 4; j++)
	  rn += rotates[j];
	//printf("i = %d rotation count = %d\n", i, rn);
	if(ans == -1) {
	  ans = rn;
	} else {
	  ans = min(rn, ans);
	}
      }
    }
    printf("%d\n", ans);
  }
  return 0;
}


Point::Point() {}

Point::Point(double _x, double _y) : x(_x), y(_y) {}

void Point::transXY(double B, Point p) {
  double tx = x - p.x, ty = y - p.y;
  x = p.x + tx * cos(B) - ty * sin(B);
  y = p.y + tx * sin(B) + ty * cos(B);
}

double dist(Point a, Point b) {
  return sqrt((a - b) * (a - b));
}

double Point::operator*(const Point& b) const {
  return x * b.x + y * b.y;
}

Point Point::operator-(const Point& b) const {
  return Point(x - b.x, y - b.y);
}
