#include <cstdio>
#include <algorithm>
#include <cstring>
#define MAXN 2001

using namespace std;

int dp[MAXN];
int n;

struct Triple {
  int a, b, c, area;
  bool operator<(const Triple& rhs) const {
    return area > rhs.area;
  }
};

Triple v[MAXN];
int vi;

int main() {
  int kase = 1;
  while(scanf("%d", &n) != EOF && n) {
    vi = 0;
    for(int i = 0; i < n; i++) {
      int a, b, c;
      scanf("%d %d %d", &a, &b, &c);
      v[vi].a = a; v[vi].b = b; v[vi].c = c; v[vi++].area = a * b;
      v[vi].a = a; v[vi].b = c; v[vi].c = b; v[vi++].area = a * c;
      v[vi].a = b; v[vi].b = a; v[vi].c = c; v[vi++].area = a * b;
      v[vi].a = b; v[vi].b = c; v[vi].c = a; v[vi++].area = c * b;
      v[vi].a = c; v[vi].b = a; v[vi].c = b; v[vi++].area = a * c;
      v[vi].a = c; v[vi].b = b; v[vi].c = a; v[vi++].area = c * b;
    }
    sort(v, v+vi);
    int ans = 0;
    for(int i = 0; i < vi; i++) {
      dp[i] = v[i].c;
      for(int ii = 0; ii < i; ii++) {
	if(v[ii].a > v[i].a && v[ii].b > v[i].b) {
	  dp[i] = max(dp[i], dp[ii] + v[i].c);
	}
      }
      ans = max(ans, dp[i]);
    }
    printf("Case %d: maximum height = %d\n", kase++, ans);
  }
  return 0;
}
