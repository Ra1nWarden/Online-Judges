#include <iostream>
#include <cstdlib>
#include <vector>
#include <cmath>
#include <sstream>
#include <cstring>
#define EPS 2e-9
#define INF 2e9
#define MAXN 700

using namespace std;

bool matched[MAXN][MAXN];

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

int main() {
  int tc;
  cin >> tc;
  string line;
  getline(cin, line);
  getline(cin, line);
  bool init = true;
  while(tc--) {
    if(!init)
      cout << endl;
    memset(matched, false, sizeof matched);
    vector<Point> points;
    while(getline(cin, line)) {
      if(line.empty())
	break;
      stringstream ss(line.c_str());
      int a, b;
      ss >> a >> b;
      points.push_back(Point(a, b));
    }
    int result = 0;
    for(int i = 0; i < points.size(); i++) {
      for(int j = i+1; j < points.size(); j++) {
	if(matched[i][j])
	  continue;
	Line curline(points[i], points[j]);
	vector<int> matchedindex;
	for(int k = j+1; k < points.size(); k++) {
	  if(curline.online(points[k])) {
	    matched[i][k] = true;
	    matched[j][k] = true;
	    for(int l = 0; l < matchedindex.size(); l++) {
	      matched[matchedindex[l]][k] = true;
	    } 
	    matchedindex.push_back(k);
	  }
	}
	result = max(result, (int) matchedindex.size() + 2);
      }
    }
    cout << result << endl;
    init = false;
  }
  return 0;
}
