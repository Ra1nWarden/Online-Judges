#include <cstdio>

using namespace std;

int gcd(int a, int b) {
  return b == 0 ? a : gcd(b, a % b);
}

int main() {
  int n, m, k;
  scanf("%d %d %d", &n, &m, &k);
  if((n * 1LL * m  * 2) % k != 0) {
    printf("NO\n");
    return 0;
  }
  int div = gcd(n * 2, k);
  int nn, mm;
  if(div > 1) {
    nn = n * 2 / div;
    int kk = k / div;
    mm = m / kk;
  } else {
    nn = n;
    mm = m * 2 / k;
  }
  
  printf("YES\n");
  printf("0 0\n");
  printf("%d 0\n", nn);
  printf("0 %d\n", mm);
  return 0;
}
