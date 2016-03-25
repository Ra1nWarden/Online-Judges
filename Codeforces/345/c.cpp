#include <cstdio>
#include <map>

using namespace std;

typedef pair<int, int> Point;
map<int, int> xcnt, ycnt;
map<Point, int> cnt;

int main() {
  int n;
  scanf("%d", &n);
  for(int i = 0; i < n; i++) {
    int x, y;
    scanf("%d%d", &x, &y);
    xcnt[x]++;
    ycnt[y]++;
    cnt[make_pair(x, y)]++;
  }
  long long ans = 0;
  for(map<int, int>::iterator itr = xcnt.begin(); itr != xcnt.end(); itr++) {
    ans += itr->second * 1LL * (itr->second - 1);
  }
  for(map<int, int>::iterator itr = ycnt.begin(); itr != ycnt.end(); itr++) {
    ans += itr->second * 1LL * (itr->second - 1);
  }
  for(map<Point, int>::iterator itr = cnt.begin(); itr != cnt.end(); itr++) {
    ans -= itr->second * 1LL * (itr->second - 1);
  }
  printf("%I64d\n", ans / 2);
  return 0;
}
