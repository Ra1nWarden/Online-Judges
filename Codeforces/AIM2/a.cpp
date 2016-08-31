#include <cstdio>

using namespace std;

int main() {
  int n, b, d;
  scanf("%d%d%d", &n, &b, &d);
  int x;
  int g = 0;
  int ans = 0;
  for(int i = 0; i < n; i++) {
    scanf("%d", &x);
    if(x > b)
      continue;
    if(g > d) {
      g = 0;
      ans++;
    }
    g += x;
  }
  if(g > d)
    ans++;
  printf("%d\n", ans);
  return 0;
}
