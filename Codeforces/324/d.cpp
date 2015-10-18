#include <cstdio>
#include <cmath>

using namespace std;

bool is_prime(int n) {
  if(n <= 1) {
    return false;
  }
  for(int i = 2; i * i <= n; i++) {
    if(n % i == 0) {
      return false;
    }
  }
  return true;
}

int main() {
  int n;
  scanf("%d", &n);
  if(is_prime(n)) {
    printf("1\n%d\n", n);
  } else if(is_prime(n - 2)) {
    printf("2\n2 %d\n", n-2);
  } else {
    printf("3\n");
    int p = n - 1;
    while(!is_prime(p))
      p--;
    int q = 2;
    while(!is_prime(q) || !is_prime(n - p - q))
      q++;
    printf("%d %d %d\n", p, q, n - p - q);
  }
  return 0;
}
