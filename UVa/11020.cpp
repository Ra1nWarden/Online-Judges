#include <cstdio>
#include <set>
#include <utility>

using namespace std;

typedef pair<int, int> Point;

int main() {
  int tc;
  int kase = 1;
  scanf("%d", &tc);
  while(tc--) {
    int n;
    scanf("%d", &n);
    multiset<Point> s;
    printf("Case #%d:\n", kase++);
    while(n--) {
      int a, b;
      scanf("%d%d", &a, &b);
      Point p = make_pair(a, b);
      if(s.empty()) {
	s.insert(p);
      } else {
	multiset<Point>::iterator itr = s.lower_bound(p);
	if(itr == s.begin() || (--itr)->second > b) {
	  s.insert(p);
	  itr = s.upper_bound(p);
	  while(itr != s.end()) {
	    if(itr->second >= b) {
	      s.erase(itr++);
	    } else {
	      break;
	    }
	  }
	}
      }
      printf("%d\n", s.size());
    }
    if(tc)
      printf("\n");
  }
  return 0;
}
