#include <cstdio>
#include <algorithm>

using namespace std;

int gcd(int a, int b) {
  return b == 0 ? a : gcd(b, a % b);
}

int main() {
  int tc;
  scanf("%d", &tc);
  int a, b;
  while(tc--) {
    scanf("%d %d", &a, &b);
    printf("%d\n", abs(a - b) / gcd(abs(a), abs(b)));
  }
  return 0;
}
