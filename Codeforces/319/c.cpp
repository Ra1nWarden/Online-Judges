#include <cstdio>
#include <utility>
#include <cmath>
#include <algorithm>
#define MAXN 1000005
#define INF 1000000000LL

using namespace std;

typedef pair<long long, long long> Coord;

struct Point {
  Coord coord;
  int idx;
  Point() {}
};

Point points[MAXN];
int n;

bool _cmpx(const Point& a, const Point& b) {
  if(a.coord.first != b.coord.first)
    return a.coord.first < b.coord.first;
  return a.coord.second < b.coord.second;
}

bool _cmpy(const Point& a, const Point& b) {
  if(a.coord.second != b.coord.second)
    return a.coord.second < b.coord.second;
  return b.coord.first < b.coord.first;
}

long long calc(int i, int j) {
  return abs(points[i].coord.first - points[j].coord.first) + abs(points[i].coord.second - points[j].coord.second);
}

long long diff(int i) {
  long long before = 0;
  if(i > 0)
    before += calc(i, i-1);
  if(i+2 < n)
    before += calc(i+1, i+2);
  long long after = 0;
  if(i > 0)
    after += calc(i+1, i-1);
  if(i+2 < n)
    after += calc(i, i+2);
  return after - before;
}

int main() {
  scanf("%d", &n);
  long long minx = INF, miny = INF, maxx = -1, maxy = -1;
  for(int i = 0; i < n; i++) {
    scanf("%I64d &I64d", &points[i].coord.first, &points[i].coord.second);
    points[i].idx = i;
    minx = min(minx, points[i].coord.first);
    maxx = max(maxx, points[i].coord.first);
    miny = min(miny, points[i].coord.second);
    maxy = max(maxy, points[i].coord.second);
  }
  if(maxx - minx > maxy - miny) {
    sort(points, points + n, _cmpx);
  } else {
    sort(points, points + n, _cmpy);
  }
  long long sum = 0;
  for(int i = 1; i < n; i++) {
    sum += calc(i, i-1);
  }
  int idx = 0;
  while(sum > 2500000000LL) {
    while(idx < n - 1) {
      long long delta = diff(idx);
      if(delta < 0) {
	swap(points[idx], points[idx+1]);
	sum += delta;
	idx-=2;
	idx = max(0, idx);
	break;
      }
      idx++;
    }
    if(idx == n - 1)
      idx = 0;
  }
  for(int i = 0; i < n; i++) {
    if(i)
      printf(" ");
    printf("%d", points[i].idx + 1);
  }
  printf("\n");
  return 0;
}
