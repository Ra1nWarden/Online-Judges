#include <cstdio>
#include <cmath>
#include <algorithm>
#define MAXN 5010
#define EPS 1e-8

using namespace std;

struct Segment {
  double l, r, d;
  bool operator<(const Segment& rhs) const {
    return d > rhs.d;
  }
};

Segment segs[MAXN];
int n;
double w;

double check(double pos) {
  double l = atan2(segs[0].d, segs[0].r - pos);
  double r = atan2(segs[0].d, segs[0].l - pos);
  for(int i = 1; i < n; i++) {
    double ll = atan2(segs[i].d, segs[i].r - pos);
    double rr = atan2(segs[i].d, segs[i].l - pos);
    if(ll - r > EPS) {
      return -1;
    } else if(l - rr > EPS) {
      return 1;
    }
    l = max(ll, l);
    r = min(rr, r);
  }
  return 0;
}

bool solve() {
  double l = 0, r = w;
  while(r - l > EPS) {
    double m = (l + r) / 2;
    int ok = check(m);
    if(ok == 0)
      return true;
    else if(ok == -1)
      r = m;
    else
      l = m;
  }
  return false;
}

int main() {
  int tc;
  scanf("%d", &tc);
  while(tc--) {
    scanf("%lf%d", &w, &n);
    for(int i = 0; i < n; i++) {		
      scanf("%lf%lf%lf", &segs[i].d, &segs[i].l, &segs[i].r);
    }
    sort(segs, segs+n);
    bool ans = solve();
    if(ans)
      printf("YES\n");
    else
      printf("NO\n");
  }
  return 0;
}
