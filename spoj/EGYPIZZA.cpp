#include <cstdio>
#include <algorithm>

using namespace std;

int main() {
  int n;
  scanf("%d", &n);
  int ans = 0;
  int half = 0;
  int quarter = 0;
  int triple = 0;
  while(n--) {
    int a, b;
    scanf("%d/%d", &a, &b);
    if(a == 1 && b == 2) {
      half++;
    } else if(a == 1 && b == 4) {
      quarter++;
    } else if(a == 3 && b == 4) {
      triple++;
    }
  }
  ans = triple + 1;
  quarter -= min(quarter, triple);
  ans += (half * 2 + quarter + 3) / 4;
  printf("%d\n", ans);
  return 0;
}
