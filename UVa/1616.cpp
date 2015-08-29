#include <cmath>
#include <cstdio>
#include <algorithm>
#define MAXN 100005
#define EPS 1e-11

using namespace std;

typedef pair<int, int> Seg;
int n;
long double maxval;
Seg v[MAXN];

bool valid(long double d) {
  long double m = 0;
  for(int i = 0; i < n; i++)  {
    m = max(m, (long double) v[i].first);
    if(m + d - v[i].second > EPS)
      return false;
    m += d;
  }
  return true;
}

bool _cmp(const Seg& a, const Seg& b) {
  if(a.first != b.first)
    return a.first < b.first;
  return a.second < b.second;
}

int main() {
  while(scanf("%d", &n) != EOF) {
    maxval = 100000.0;
    for(int i = 0; i < n; i++) {
      scanf("%d%d", &v[i].first, &v[i].second);
      maxval = min(maxval, (long double) (v[i].second - v[i].first));
    }
    sort(v, v+n, _cmp);
    long double r = maxval;
    long double l = 0;
    while(r-l > EPS) {
      long double m = (l + r) / 2;
      if(valid(m)) {
	l = m;
      } else {
	r = m;
      }
    }
    long double minval = 0x3f3f3f3f;
    int p, q;
    for(int i = 1; i <= MAXN; i++) {
      int j = floor(l * i);
      if(fabs((long double) (j) / i - l) < minval) {
	p = j;
	q = i;
	minval = fabs((long double) (j) / i - l);
      }

      j = ceil(l * i);
      if(fabs((long double) (j)/ i - l) < minval) {
	p = j;
	q = i;
	minval = fabs((long double) (j) / i - l);
      }
    }
    printf("%d/%d\n", p, q);
  }
  return 0;
}
