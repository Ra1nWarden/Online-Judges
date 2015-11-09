#include <cstdio>

using namespace std;

int main() {
  int n;
  scanf("%d", &n);
  int ans = 0;
  int min_price = -1;
  while(n--) {
    int a, p;
    scanf("%d%d",&a, &p);
    if(min_price == -1 || p < min_price) {
      min_price = p;
    }
    ans += min_price * a;
  }
  printf("%d\n", ans);
  return 0;
}
