#include <cstdio>

using namespace std;

bool isprime(int n) {
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
  if(isprime(n)) {
    printf("1\n");
  } else if(!(n & 1)) {
    printf("2\n");
  } else if(isprime(n - 2)) {
    printf("2\n");
  } else {
    printf("3\n");
  }
  return 0;
}
