#include <cstdio>
#include <cmath>
#include <utility>

using namespace std;

typedef pair<int, int> Point;

const int maxn = 100000;
Point points[maxn];
int n;

long long dist(const Point& a, const Point& b) {
  return (a.first - b.first) * 1LL * (a.first - b.first) + (a.second - b.second) * 1LL * (a.second - b.second);
}

long long area(const Point& a, const Point& b, const Point& c) {
  Point ba = make_pair(b.first - a.first, b.second - a.second);
  Point ca = make_pair(c.first - a.first, c.second - a.second);
  long long val = ba.first * 1LL * ca.second - ba.second * 1LL * ca.first;
  if(val < 0)
    val = -val;
  return val;
}

int main() {
  scanf("%d", &n);
  for(int i = 0; i < n; i++)
    scanf("%d %d", &points[i].first, &points[i].second);
  Point a = points[0];
  int idx = -1;
  long long minval = -1;
  for(int i = 1; i < n; i++) {
    long long cur = dist(a, points[i]);
    if(minval == -1 || cur < minval) {
      minval = cur;
      idx = i;
    }
  }
  int cidx = -1;
  minval = -1;
  for(int i = 1; i < n; i++) {
    if(i == idx)
      continue;
    long long cur = area(a, points[idx], points[i]);
    if(cur == 0)
      continue;
    if(minval == -1 || cur < minval) {
      minval = cur;
      cidx = i;
    }
  }
  Point ba = make_pair(points[idx].first - a.first, points[idx].second - a.second);
  Point ca = make_pair(points[cidx].first - a.first, points[cidx].second - a.second);
  long long dir = ba.first * 1LL * ca.second - ba.second * 1LL * ca.first;
  if(dir > 0) {
    printf("%d %d %d\n", 1, idx + 1, cidx + 1);
  } else {
    printf("%d %d %d\n", 1, cidx + 1, idx + 1);
  }
  return 0;
}
