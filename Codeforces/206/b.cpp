#include <algorithm>
#include <cstdio>

using namespace std;

int main() {
  int c1, c2, c3, c4;
  int n, m;
  scanf("%d%d%d%d", &c1, &c2, &c3, &c4);
  scanf("%d%d", &n, &m);
  int cost_a = 0;
  for(int i = 0; i < n; i++) {
    int cnt;
    scanf("%d", &cnt);
    cost_a += min(c1 * cnt, c2);
  }
  cost_a = min(cost_a, c3);
  int cost_b = 0;
  for(int i = 0; i < m; i++) {
    int cnt;
    scanf("%d", &cnt);
    cost_b += min(c1 * cnt, c2);
  }
  cost_b = min(cost_b, c3);
  printf("%d\n", min(cost_a + cost_b, c4));
  return 0;
}
