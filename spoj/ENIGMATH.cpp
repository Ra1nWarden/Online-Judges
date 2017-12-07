#include <cstdio>

using namespace std;

int gcd(int a, int b) {
  if(b == 0) {
    return a;
  }
  return gcd(b, a % b);
}

int main() {
  int tc;
  scanf("%d", &tc);
  while(tc--) {
    int a, b;
    scanf("%d %d", &a, &b);
    int p = gcd(a, b);
    printf("%d %d\n", b / p, a / p);
  }
  return 0;
}
