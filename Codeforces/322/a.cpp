#include <cstdio>
#include <cmath>
#include <algorithm>

using namespace std;

int main() {
  int a, b;
  scanf("%d%d", &a, &b);
  printf("%d %d\n", min(a, b), abs(a - b) / 2);
  return 0;
}
