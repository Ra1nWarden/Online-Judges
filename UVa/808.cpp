#include <cstdio>
#include <utility>
#include <algorithm>
#include <cmath>
#define MAXN 10005

using namespace std;

typedef pair<int, int> Point;

Point points[MAXN];
int dx[] = {0,-1,-1,0,1,1};
int dy[] = {-1,0,1,1,0,-1};

void init() {
  int pos = 1;
  int side = 1;
  points[pos] = make_pair(0, 0);
  while(++pos <= 10000) {
    points[pos] = make_pair(side, -1);
    for(int dir = 0; dir < 6; dir++) {
      for(int l = 1; l < (dir == 0 ? side : side + 1); l++) {
	pos++;
	if(pos > 10000)
	  return;
	points[pos] = make_pair(points[pos-1].first + dx[dir], points[pos-1].second + dy[dir]);
      }
    }
    side++;
  }
}

int main() {
  init();
  int a, b;
  while(scanf("%d %d", &a, &b) != EOF && (a || b)) {
    int x = points[a].first - points[b].first;
    int y = points[a].second - points[b].second;
    int ans;
    if(x * y > 0) {
      ans = abs(x + y);
    } else {
      ans = max(abs(x), abs(y));
    }
    printf("The distance between cells %d and %d is %d.\n", a, b, ans);
  }
  return 0;
}
