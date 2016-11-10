#include <cstdio>
#include <algorithm>

using namespace std;

int main() {
  int x1, x2, x3;
  scanf("%d%d%d", &x1, &x2, &x3);
  printf("%d\n", max(x1, max(x2, x3)) - min(x1, min(x2, x3)));
  return 0;
}
