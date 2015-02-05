#include <iostream>
#include <vector>
#include <iomanip>
#include <cmath>
#include <algorithm>
#include <cstring>
#include <cstdlib>
#define EPS 2e-9
#define INF 2e9
#define MAXN 300

using namespace std;

struct Point {
  Point(int a, int b) : x(a), y(b) {};
  double x, y;
  bool operator<(const Point& another) const {
    return x == another.x ? y < another.y : x < another.x;
  };
};

struct Line {
  double k, b;
  Line(Point ap, Point bp) {
    if(ap.x == bp.x) {
      k = INF;
      b = ap.x;
    } else {
      k = (ap.y - bp.y) / (ap.x - bp.x);
      b = bp.y - k * bp.x;
    }
  };
  bool online(Point c) {
    if(k == INF)
      return c.x == b;
    return fabs(c.x * k + b - c.y) < EPS;
  };
};

bool matched[MAXN][MAXN];

int main() {
  int x, y;
  while(cin >> x >> y) {
    vector<Point> points;
    while(x || y) {
      points.push_back(Point(x, y));
      cin >> x >> y;
    }
    if(points.empty())
      break;
    sort(points.begin(), points.end());
#ifdef _DEBUG
    cout << "sorted points:" << endl;
    for(int i = 0; i < points.size(); i++) {
      cout << "(" << points[i].x << ", " << points[i].y << ")" << endl;
    }
    cout << "end of sorted points debug" << endl;
#endif
    bool found = false;
    bool headprint = false;
    memset(matched, false, sizeof matched);
    for(int i = 0; i < points.size(); i++) {
      for(int j = i+1; j < points.size(); j++) {
	if(matched[i][j])
	  continue;
	Line curline(points[i], points[j]);
	vector<int> intersect;
	for(int k = j + 1; k < points.size(); k++) {
	  if(curline.online(points[k])) {
	    matched[i][k] = true;
	    //matched[i][j] = true;
	    matched[j][k] = true;
	    for(int l = 0; l < intersect.size(); l++)
	      matched[intersect[l]][k] = true;
	    intersect.push_back(k);
	  }
	}
	if(!intersect.empty()) {
	  found = true;
	  if(!headprint) {
	    cout << "The following lines were found:" << endl;
	    headprint = true;
	  }
	  cout << "(" << setw(4) << right << points[i].x << "," << setw(4) << right << points[i].y << ")(" << setw(4) << right << points[j].x << "," << setw(4) << right << points[j].y << ")";
	  for(int k = 0; k < intersect.size(); k++) {
	    cout << "(" << setw(4) << right << points[intersect[k]].x << "," << setw(4) << right << points[intersect[k]].y << ")";
	  }
	  cout << endl;
	}
      }
    }
    if(!found)
      cout << "No lines were found" << endl;
  }
  return 0;
}
