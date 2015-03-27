#include <cstdio>

using namespace std;

int main() {
  int n, m;
  scanf("%d %d", &n, &m);
  if(m >= 2 * n)
    printf("%d\n", n);
  else if (n >= 2 * m)
    printf("%d\n", m);
  else
    printf("%d\n", (m+n) / 3);
  return 0;
}
