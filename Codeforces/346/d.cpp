#include <cstdio>
#include <utility>

using namespace std;

const int maxn = 1000;
typedef pair<int, int> Point;
Point points[maxn+5];
int n;

bool check(const Point& a, const Point& b) {
  return a.first * b.second - a.second * b.first > 0;
}

int main() {
  scanf("%d", &n);
  for(int i = 0; i <= n; i++) {
    scanf("%d%d", &points[i].first, &points[i].second);
  }
  int ans = 0;
  for(int i = 1; i < n; i++) {
    Point a = make_pair(points[i].first - points[i-1].first, points[i].second - points[i-1].second);
    Point b = make_pair(points[i+1].first - points[i].first, points[i+1].second - points[i].second);
    if(check(a, b))
      ans++;
  }
  printf("%d\n", ans);
  return 0;
}
