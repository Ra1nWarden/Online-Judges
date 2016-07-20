#include <cstdio>

using namespace std;

bool f1(int num) {
  int d1 = 123456;
  int d2 = 1234;
  for(int i = 0; i * d1 <= num; i++) {
    if((num - i * d1) % d2 == 0)
      return true;
  }
  return false;
}

bool f(int num) {
  int div = 1234567;
  for(int i = 0; i * div <= num; i++) {
    if(f1(num - i * div))
      return true;
  }
  return false;
}

int main() {
  int n;
  scanf("%d", &n);
  printf("%s\n", f(n) ? "YES" : "NO");
  return 0;
}
