#include <cstdio>
#include <utility>
#include <algorithm>
#define MAXN 100005

using namespace std;

typedef pair<int, int> Seg;
int n;
Seg v[MAXN];

bool _cmp(const Seg& a, const Seg& b) {
  if(a.second != b.second)
    return a.second < b.second;
  return a.first < b.first;
}

int main() {
  int tc;
  scanf("%d", &tc);
  while(tc--) {
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
      scanf("%d%d", &v[i].first, &v[i].second);
    }
    sort(v, v+n, _cmp);
    int ans = 0;
    int pos = v[0].second;
    for(int i = 1; i < n; i++) {
      if(pos != v[i].second) {
	if(pos < v[i].first) {
	  ans++;
	  pos = v[i].second;
	} else {
	  pos++;
	}
      }
    }
    printf("%d\n", ans);
  }
  return 0;
}
