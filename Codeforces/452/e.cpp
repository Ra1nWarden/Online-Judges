#include <cstdio>
#include <utility>
#include <set>
#include <iterator>

using namespace std;

const int maxn = 200000;
int v[maxn+5];
int n;

typedef pair<int, int> II;

int main() {
  scanf("%d", &n);
  for(int i = 0; i < n; i++)
    scanf("%d", &v[i]);
  int num = v[0];
  int start = 0;
  set<II> lens;
  set<II> segs;
  for(int idx = 1; idx < n; idx++) {
    if(v[idx] != num) {
      lens.insert(make_pair(-(idx - start), start));
      segs.insert(make_pair(start, idx - start));
      start = idx;
      num = v[idx];
    }
  }
  lens.insert(make_pair(-(n - start), start));
  segs.insert(make_pair(start, n - start));

  int ans = 0;
  while(true) {
    if(lens.empty()) {
      break;
    }
    ans++;
    auto head = lens.begin();
    auto found = segs.find(make_pair(head->second, -head->first));
    if(found != segs.begin() && next(found) != segs.end()) {
      auto pre = prev(found);
      auto aft = next(found);
      lens.erase(head);
      segs.erase(found);
      if(v[pre->first] == v[aft->first]) {
	segs.insert(make_pair(pre->first, pre->second + aft->second));
	lens.erase(make_pair(-pre->second, pre->first));
	lens.erase(make_pair(-aft->second, aft->first));
	lens.insert(make_pair(-(pre->second + aft->second), pre->first));
	segs.erase(pre);
	segs.erase(aft);
      }
    } else {
      lens.erase(head);
      segs.erase(found);
    }
  }
  printf("%d\n", ans);
  return 0;
}
