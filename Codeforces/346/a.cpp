#include <cstdio>

using namespace std;

int main() {
  int n, a, b;
  scanf("%d%d%d", &n, &a, &b);
  a--;
  a += b;
  while(a < 0)
    a += n;
  a %= n;
  printf("%d\n", a + 1);
  return 0;
}
