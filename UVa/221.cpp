#include <cstdio>
#include <algorithm>
#define MAXN 105

using namespace std;

struct Building {
  int id;
  double x, y, w, d, h;
  bool operator<(const Building& rhs) const {
    return x < rhs.x || (x == rhs.x && y < rhs.y);
  }
};

Building b[MAXN];

int n;
double x[MAXN * 2];

bool cover(int i, double mx) {
  return b[i].x <= mx && b[i].x + b[i].w >= mx;
}

bool visible(int i, double mx) {
  if(!cover(i, mx))
    return false;
  for(int k = 0; k < n; k++) {
    if(b[k].y < b[i].y && b[k].h >= b[i].h && cover(k, mx))
      return false;
  }
  return true;
}

int main() {
  int kase = 1;
  while(scanf("%d", &n) != EOF && n) {
    if(kase > 1)
      printf("\n");
    for(int i =0; i < n; i++) {
      scanf("%lf %lf %lf %lf %lf", &b[i].x, &b[i].y, &b[i].w, &b[i].d, &b[i].h);
      x[i*2] = b[i].x;
      x[i*2+1] = b[i].x + b[i].w;
      b[i].id = i+1;
    }
    sort(b, b+n);
    sort(x, x+2*n);
    int m = unique(x, x+2*n) - x;
    printf("For map #%d, the visible buildings are numbered as follows:\n%d", kase++, b[0].id);
    for(int i = 1; i < n; i++) {
      bool vis = false;
      for(int j = 0; j < m - 1; j++) {
	double mid = (x[j+1] + x[j]) / 2.0;
	if(visible(i, mid)) {
	  vis = true;
	  break;
	}
      }
      if(vis)
	printf(" %d", b[i].id);
    }
    printf("\n");
  }
  return 0;
}
