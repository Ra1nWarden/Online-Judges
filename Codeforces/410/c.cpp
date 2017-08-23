#include <cstdio>

using namespace std;

int gcd(int a, int b) {
  return b == 0 ? a : gcd(b, a % b);
}

int main() {
  int n;
  scanf("%d", &n);
  int d = 0;
  int v;
  int s = 0;
  int ans = 0;
  while(n--) {
    scanf("%d", &v);
    d = gcd(d, v);
    if(v&1) {
      s++;
    } else {
      ans += (s + 1) / 2 + (s % 2);
      s = 0;
    }
  }
  ans += (s + 1) / 2 + (s % 2);
  printf("YES\n");
  printf("%d\n", d > 1 ? 0 : ans);
  return 0;
}
