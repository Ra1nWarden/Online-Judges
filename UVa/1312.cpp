#include <algorithm>
#include <cstdio>
#define MAXN 105

using namespace std;

int n, m, w, h;
typedef pair<int, int> Point;
Point trees[MAXN];
int y[MAXN];

bool _cmp(const Point& a, const Point& b) {
  if(a.first != b.first)
    return a.first < b.first;
  return a.second < b.second;
}

int main() {
  int tc;
  scanf("%d", &tc);
  while(tc--) {
    scanf("%d%d%d", &n, &w, &h);
    for(int i = 0; i < n; i++) {
      scanf("%d%d", &trees[i].first, &trees[i].second);
      y[i] = trees[i].second;
    }
    y[n] = 0;
    y[n+1] = h;
    sort(y, y+n+2);
    m = unique(y, y+n+2) - y;
    sort(trees, trees+n, _cmp);
    int ans = -1;
    int xx, yy;
    for(int i = 0; i < m; i++) {
      for(int j = i + 1; j < m; j++) {
	int height = y[j] - y[i];
	int prev = 0;
	int width, l;
	for(int k = 0; k < n; k++) {
	  if(trees[k].second >= y[j] || trees[k].second <= y[i])
	    continue;
	  width = trees[k].first - prev;
	  l = min(width, height);
	  if(l > ans) {
	    ans = l;
	    xx = prev;
	    yy = y[i];
	  }
	  prev = trees[k].first;
	}
	width = w - prev;
	l = min(width, height);
	if(l > ans) {
	  ans = l;
	  xx = prev;
	  yy = y[i];
	}
      }
    }
    printf("%d %d %d\n", xx, yy, ans);
    if(tc)
      printf("\n");
  }
  return 0;
}
