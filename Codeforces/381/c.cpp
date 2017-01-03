#include <cstdio>
#include <algorithm>

using namespace std;

int main() {
  int n, m;
  scanf("%d%d", &n, &m);
  int ans = n + 1;
  for(int i = 0; i < m; i++) {
    int l, r;
    scanf("%d%d", &l, &r);
    ans = min(ans, r - l + 1);
  }
  printf("%d\n", ans);
  for(int i = 0; i < n; i++) {
    if(i)
      printf(" ");
    printf("%d", i % ans);
  }
  printf("\n");
  return 0;
}
