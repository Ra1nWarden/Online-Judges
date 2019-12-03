#include <cstdio>

using namespace std;

int gcd(int a, int b) {
  if(!b)
    return a;
  return gcd(b, a % b);
}

int main() {
  int tc;
  scanf("%d", &tc);
  int a, b, c;
  for(int kase = 1; kase <= tc; kase++) {
    scanf("%d %d %d", &a, &b, &c);
    printf("Case %d: %s\n", kase, (c % gcd(a, b)) ? "No" : "Yes");
  }
  return 0;
}
