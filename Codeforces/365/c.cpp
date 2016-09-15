#include <cstdio>
#include <utility>
#include <algorithm>

using namespace std;

typedef pair<int, int> Point;
const int maxn = 10000;
Point points[maxn+5];
double t[maxn+5];
int n, w, v, u;
const double eps = 1e-8;

int main() {
  scanf("%d%d%d%d", &n, &w, &v, &u);
  int l = -1, r = -1, b = -1;
  for(int i = 0; i < n; i++) {
    scanf("%d %d", &points[i].first, &points[i].second);
    t[i] = (double) points[i].first / v;
    if(l == -1 || points[i].first < points[l].first || (points[i].first == points[l].first && points[i].second < points[l].second)) {
      l = i;
    }
    if(r == -1 || points[i].first > points[r].first || (points[i].first == points[r].first && points[i].second < points[r].second)) {
      r = i;
    }
    if(b == -1 || points[i].second < points[b].second || (points[i].second == points[b].second && points[i].first > points[b].first)) {
      b = i;
    }
  }
  // before
  double tt = (double) points[l].second / u;
  if(t[l] - tt > eps) {
    int idx = l;
    while(true) {
      int idx2 = (idx - 1 + n) % n;
      if(points[idx2].second <= points[idx].second) {
	printf("%.10lf\n", (double) w / u);
	return 0;
      } else {
	tt = (double) points[idx2].second / u;
	if(tt - t[idx2] > eps) {
	  break;
	}
      }
      idx = idx2;
    }
  }
  // after
  int idx = b;
  tt = max((double) points[idx].second / u, t[idx]);
  while(true) {
    int idx2 = (idx + 1) % n;
    if(points[idx2].first <= points[idx].first) {
      tt += (double) (w - points[idx].second) / u;
      printf("%.10lf\n", tt);
      break;
    } else {
      tt = max(tt + (double) (points[idx2].second - points[idx].second) / u, t[idx2]);
    }
    idx = idx2;
  }
  return 0;
}
