#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <utility>
#include <algorithm>
#define MAXM 60005
#define INF 2000000000

using namespace std;

int m, n;

typedef pair<int, int> Point;

Point a, b;
int h[MAXM];

int main() {
  int tc;
  scanf("%d", &tc);
  while(tc--) {
    scanf("%d%d", &m, &n);
    scanf("%d%d", &a.first, &a.second);
    scanf("%d%d", &b.first, &b.second);
    if(a.first > b.first)
      swap(a, b);
    n -= 2;
    for(int i = 0; i < m; i++) {
      h[i] = INF;
    }
    for(int i = 0; i < n; i++) {
      int x, y;
      scanf("%d%d", &x, &y);
      h[x] = min(h[x], abs(a.second - y));
    }
    h[a.first] = h[b.first] = 0;
    for(int i = a.first + 1; i < b.first; i++)
      h[i] = min(h[i], h[i-1] + 1);
    for(int i = b.first - 1; i > a.first; i--)
      h[i] = min(h[i], h[i+1] + 1);
    int ans = 0;
    for(int i = a.first + 1; i < b.first; i++)
      if(h[i] > 0)
	ans += min(h[i] - 1, a.second) + min(h[i] - 1, m - a.second - 1) + 1;
    printf("%d\n", ans);
  }
  return 0;
}
