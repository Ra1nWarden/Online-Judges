#include <cstdio>
#include <utility>

using namespace std;

int t1, t2, s1, s2, w;
typedef pair<int, int> Point;

int main() {
  int tc;
  scanf("%d", &tc);
  for(int kase = 1; kase <= tc; kase++) {
    scanf("%d%d%d%d%d", &t1, &t2, &s1, &s2, &w);
    int white = 0;
    Point a = make_pair(t1, t1+w);
    Point b = make_pair(s2-w, s2);
    Point c = make_pair(t2, t2+w);
    Point d = make_pair(s1-w, s1);
    if(a.first >= d.first && a.second < s2) {
      if(b.first <= c.first) {
	// 1
	white += (s2 - a.second) * (b.first - t1);
      } else {
	// 2
	white += (s2 - c.second + s2 - a.second) * (t2 - t1);
      }
    } else if(a.first < d.first) {
      if(d.first >= t2) {
	white += (s2 - s1) * (t2 - t1) * 2;
      }
      else if(b.first <= c.first) {
	// 3
	white += (b.first - t1 + d.first - t1) * (s2 - s1);
      } else {
	// 4
	white += (s2 - s1) * (d.first - t1) * 2 + (s2 - s1 + s2 - c.second) * (t2 - d.first);
      }
    }
    a = make_pair(t1, t1-w);
    b = make_pair(s2+w, s2);
    c = make_pair(t2, t2-w);
    d = make_pair(s1+w, s1);

    if(a.first >= d.first) {
      if(a.second >= s2) {
	white += (s2 - s1) * (t2 - t1) * 2;
      }
      else if(b.first <= c.first) {
	// 1
	white += (a.second - s1) * (t2 - t1) * 2 + (t2 - b.first + t2 - t1) * (s2 - a.second);
      } else {
	// 2
	white += (a.second - s1 + c.second - s1) * (t2 - t1);
      }
    } else if(a.first < d.first && d.first < t2){
      if(b.first <= c.first) {
	// 3
	white += (t2 - b.first + t2 - d.first) * (s2 - s1);
      } else {
	// 4
	white += (t2 - d.first) * (c.second - s1);
      }
    }

    int shadow = (t2 - t1) * (s2 - s1) * 2 - white;
    printf("Case #%d: %.8lf\n", kase, shadow * 1.0 / ((t2 - t1) * (s2 - s1) * 2));
  }
  return 0;
}
