#include <algorithm>
#include <cstdio>
#define MAXN 200005

using namespace std;

int w, h;
int n;

// true = left
// false = right
typedef pair<double, bool> DB;

DB v[MAXN];
int index;

bool _cmp(const DB& a, const DB& b) {
  if(a.first != b.first)
    return a.first < b.first;
  else
    return !a.second && b.second;
}

void update(int pos, int speed, int cap, double& start, double& end) {
  if(speed == 0) {
    if(pos <= 0 || pos >= cap)
      end = start - 1;
  } else {
    if(speed > 0) {
      start = max(start, (double)(0 - pos) / speed);
      end = min(end, (double)(cap - pos) / speed);
    } else {
      start = max(start, (double)(cap - pos) / speed);
      end = min(end, (double)(0 - pos) / speed);
    }
  }
}

int main() {
  int tc;
  scanf("%d", &tc);
  while(tc--) {
    scanf("%d %d", &w, &h);
    scanf("%d", &n);
    int x, y, a, b;
    index = 0;
    while(n--) {
      scanf("%d %d %d %d", &x, &y, &a, &b);
      double start = 0;
      double end = 1e9;
      update(x, a, w, start, end);
      update(y, b, h, start, end);
      if(end > start) {
	v[index].first = start;
	v[index].second = true;
	index++;
	v[index].first = end;
	v[index].second = false;
	index++;
      }
    }
    sort(v, v+index, _cmp);
    int counter = 0;
    int ans = 0;
    for(int i = 0; i < index; i++) {
      DB next = v[i];
      if(v[i].second) {
	counter++;
	ans = max(ans, counter);
      } else {
	counter--;
      }
    }
    printf("%d\n", ans);
  }
  return 0;
}
