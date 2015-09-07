#include <cstdio>
#include <algorithm>
#define MAXN 105

using namespace std;

struct Point {
  int x, y;
  bool operator<(const Point& rhs) const {
    return x < rhs.x;
  }
};

Point pv[MAXN];
int yv[MAXN], on[MAXN], on2[MAXN], left[MAXN];
int n, m;

int solve() {
  sort(yv, yv+n);
  sort(pv, pv+n);
  m = unique(yv, yv+n) - yv;
  if(m <= 2) {
    return n;
  } else {
    int ans = 0;
    for(int i = 0; i < m; i++) {
      for(int j = i+1; j < m; j++) {
	int ymin = yv[i];
	int ymax = yv[j];
	int mm = 0;
	left[mm] = on2[mm] = on[mm] = 0;
	for(int k = 0; k < n; k++) {
	  if(k == 0 || pv[k].x != pv[k-1].x) {
	    mm++;
	    on[mm] = on2[mm] = 0;
	    left[mm] = left[mm - 1] + on2[mm - 1] - on[mm - 1];
	  }
	  if(pv[k].y > ymin && pv[k].y < ymax)
	    on[mm]++;
	  if(pv[k].y >= ymin && pv[k].y <= ymax)
	    on2[mm]++;
	}
	if(mm == 2)
	  return n;
	int max_val = 0;
	for(int k = 1; k<= mm; k++) {
	  ans = max(ans, left[k] + on2[k] + max_val);
	  max_val = max(max_val, on[k] - left[k]);
	}
      }
    }
    return ans;
  }
}

int main() {
  int kase = 1;
  while(~scanf("%d", &n) && n) {
    for(int i = 0; i < n; i++) {
      scanf("%d %d", &pv[i].x, &pv[i].y);
      yv[i] = pv[i].y;
    }
    printf("Case %d: %d\n", kase++, solve());
  }
  return 0;
}
