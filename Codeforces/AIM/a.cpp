#include <cstdio>

using namespace std;

int main() {
  int d, l, v1, v2;
  scanf("%d%d%d%d", &d, &l, &v1, &v2);
  printf("%.8lf\n", (l - d) * 1.0 / (v1 + v2));
  return 0;
}
