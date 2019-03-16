#include <cstdio>
#include <utility>
#include <algorithm>

using namespace std;

const int maxn = 100;
typedef pair<int, int> Node;
Node v[maxn * 2 + 5];
int n;

int main() {
  int tc;
  scanf("%d", &tc);
  while(tc--) {
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
      int a, b;
      scanf("%d %d", &a, &b);
      v[i * 2] = make_pair(a, 1);
      v[i * 2 + 1] = make_pair(b, 0);
    }
    sort(v, v + (2 * n));
    int cur = 0;
    int ans = 0;
    for(int i = 0; i < 2 * n; i++) {
      if(v[i].second == 0) {
	cur--;
      } else {
	cur++;
      }
      ans = max(ans, cur);
    }
    printf("%d\n", ans);
  }
  return 0;
}
