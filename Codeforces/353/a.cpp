#include <cstdio>
#include <algorithm>

using namespace std;

int main() {
  int a, b, c;
  scanf("%d%d%d", &a, &b, &c);
  if(c == 0) {
    printf("%s\n", a == b ? "YES" : "NO");
  } else {
    int diff = b - a;
    int div = diff / c;
    printf("%s\n", (div >= 0 && (div * c == diff)) ? "YES" : "NO");
  }
  return 0;
}
