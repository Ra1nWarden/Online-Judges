#include <cstdio>

using namespace std;

int n, m;
int ans;

int main() {
  while(scanf("%d", &n) != EOF) {
    ans = -1;
    scanf("%d", &m);
    for(int i = 0; i < m; i++) {
      int u, d;
      scanf("%d %d", &u, &d);
      int x = (n * d) / (u + d) + 1;
      int res = (u + d) * x - n * d;
      if (ans == -1 || res < ans) {
	ans = res;
      }
    }
    printf("%d\n", ans);
  }
  return 0;
}
