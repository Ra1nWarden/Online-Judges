#include <iostream>
#include <cmath>
#include <cstdlib>
#include <vector>
#include <map>
#define EPS 2e-9
#define INF 2e9

using namespace std;

struct Point {
  Point() {};
  Point(int a, int b) : x(a), y(b) {};
  double x, y;
  bool operator<(const Point& another) const {
    return x == another.x ? y < another.y : x < another.x;
  };
  bool operator==(const Point& another) const {
    return x == another.x && y == another.y;
  };
};

struct Line {
  double k, b;
  Point start, end;
  Line() {};
  Line(Point ap, Point bp) {
    if(ap.x == bp.x) {
      k = INF;
      b = ap.x;
    } else {
      k = (ap.y - bp.y) / (ap.x - bp.x);
      b = bp.y - k * bp.x;
    }
    start = min(ap, bp);
    end = max(ap, bp);
  };
};

vector<Line> lines;
map<int, int> resultv;

int fall(Point p) {
  int result = -1;
  double closest = 0;
  for(int i = 0; i < lines.size(); i++) {
    if(p.x < lines[i].start.x || p.x > lines[i].end.x || lines[i].k == INF)
      continue;
    if(lines[i].start == p || lines[i].end == p)
      continue;
    double proj = lines[i].k * p.x + lines[i].b + EPS;
    if(proj <= p.y && proj > closest) {
      closest = proj;
      result = i;
    }
  }
  return result;
}

int fallpoint(int index) {
  if(resultv.count(index))
    return resultv[index];
  else {
    Point lowerpoint = lines[index].k > 0 ? min(lines[index].start, lines[index].end) : max(lines[index].start, lines[index].end);
    int fallindex = fall(lowerpoint);
    if(fallindex == -1)
      return resultv[index] = lowerpoint.x;
    else
      return resultv[index] = fallpoint(fall(lowerpoint));
  }
}

int solve(int x, int y) {
  Point p(x, y);
  if(fall(p) == -1)
    return x;
  else {
    return fallpoint(fall(p));
  }
}

int main() {
  int tc;
  cin >> tc;
  bool init = true;
  while(tc--) {
    if(!init)
      cout << endl;
    int lineno;
    cin >> lineno;
    lines.clear();
    for(int i = 0; i < lineno; i++) {
      int x1, y1, x2, y2;
      cin >> x1 >> y1 >> x2 >> y2;
      Point a(x1, y1);
      Point b(x2, y2);
      lines.push_back(Line(a, b));
    }
    resultv.clear();
    int queries;
    cin >> queries;
    for(int i = 0; i < queries; i++) {
      int x, y;
      cin >> x >> y;
      cout << solve(x, y) << endl;
    }
    init = false;
  }
  return 0;
}
