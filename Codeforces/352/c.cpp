#include <cstdio>
#include <utility>
#include <functional>
#include <cmath>
#include <algorithm>

using namespace std;

typedef pair<int, int> Point;
Point a, b, t;
const int maxn = 100000;
Point points[maxn+5];
int n;
typedef pair<double, int> Node;
Node savinga[maxn+5];
Node savingb[maxn+5];

double distance_to(const Point& p1, const Point& p2) {
  return sqrt(pow(p1.first - p2.first, 2) + pow(p1.second - p2.second, 2));
}

double cal_distance(const Point& p) {
  return distance_to(p, t) * 2;
}

double diff_distance(const Point& p, const Point& r) {
  return distance_to(p, t) - distance_to(p, r);
}

int main() {
  scanf("%d%d%d%d%d%d", &a.first, &a.second, &b.first, &b.second, &t.first, &t.second);
  scanf("%d", &n);
  double total = 0;
  for(int i = 0; i < n; i++) {
    scanf("%d%d", &points[i].first, &points[i].second);
    total += cal_distance(points[i]);
    savinga[i] = make_pair(diff_distance(points[i], a), i);
    savingb[i] = make_pair(diff_distance(points[i], b), i);
  }
  if(n == 1) {
    printf("%.10f\n", min(distance_to(points[0], a) + distance_to(points[0], t), distance_to(points[0], b) + distance_to(points[0], t)));
    return 0;
  }
  sort(savinga, savinga + n, greater<pair<double, int> >());
  sort(savingb, savingb + n, greater<pair<double, int> >());
  if(savinga[0].first < 0 && savingb[0].first < 0) {
    printf("%.10lf\n", total - max(savinga[0].first, savingb[0].first));
    return 0;
  }
  double res1 = max(savinga[0].first, 0.0);
  if(savingb[0].second == savinga[0].second) {
    res1 += max(savingb[1].first, 0.0);
  } else {
    res1 += max(savingb[0].first, 0.0);
  }
  double res2 = max(savingb[0].first, 0.0);
  if(savinga[0].second == savingb[0].second) {
    res2 += max(savinga[1].first, 0.0);
  } else {
    res2 += max(savinga[0].first, 0.0);
  }
  printf("%.10lf\n", total - max(res1, res2));
  return 0;
}
