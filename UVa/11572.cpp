#include <cstdio>
#include <map>
#define MAXN 1000005

using namespace std;

int v[MAXN];
int n;
map<int, int> m;

int main() {
  int tc;
  scanf("%d", &tc);
  while(tc--) {
    m.clear();
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
      scanf("%d", &v[i]);
    }
    int ans = 0;
    int L = 0;
    int R = 0;
    while(R < n) {
      int num = v[R];
      if(m.count(num) == 0 || m[num] < L) {
	ans = max(ans, R - L + 1);
	m[num] = R;
	R++;
      } else {
	L = m[num] + 1;
	m[num] = R;
	ans = max(ans, R - L + 1);
	R++;
      }
    }
    printf("%d\n", ans);
  }
  return 0;
}
