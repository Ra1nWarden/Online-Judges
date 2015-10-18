#include <cstdio>
#include <utility>
#include <algorithm>
#define MAXL 150005

using namespace std;

char a[MAXL], b[MAXL];
bool v[MAXL];
int prefix[MAXL];
int n, k;
typedef pair<int, int> Node;
Node q[MAXL];
int qi;

int main() {
  while(scanf("%d %d\n", &n, &k) && (n || k)) {
    scanf("%s\n%s\n", a, b);
    prefix[0] = 0;
    for(int i = 0; i < n; i++) {
      v[i] = a[i] == b[i];
      prefix[i+1] = prefix[i];
      if(!v[i])
	prefix[i+1]++;
    }
    qi = 0;
    q[qi++] = make_pair(0, 0);
    int ans = 0;
    for(int i = 1; i <= n; i++) {
      int cur = 100 * prefix[i] - k * i;
      int l = 0, r = qi - 1;
      while(l < r) {
	int m = l + (r - l) / 2;
	if(q[m].second >= cur)
	  r = m;
	else
	  l = m + 1;
      }
      if(q[l].second >= cur) {
	ans = max(ans, i - q[l].first);
      }
      if(cur > q[qi-1].second)
	q[qi++] = make_pair(i, cur);
    }
    if(ans == 0)
      printf("No solution.\n");
    else
      printf("%d\n", ans);
  }
  return 0;
}
