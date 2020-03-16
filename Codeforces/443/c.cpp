#include <cstdio>

using namespace std;

int main() {
  int n;
  scanf("%d\n", &n);
  int zero = 0, one = (1 << 10) - 1;
  char ops;
  int num;
  while(n--) {
    scanf("%c %d\n", &ops, &num);
    if(ops == '|') {
      zero |= num;
      one |= num;
    }
    if(ops == '^') {
      zero ^= num;
      one ^= num;
    }
    if(ops == '&') {
      zero &= num;
      one &= num;
    }
  }
  int o = 0, x = 0, a = (1 << 10) - 1;
  for(int i = 0; i < 10; i++) {
    if(zero & (1 << i)) {
      if(one & (1 << i)) {
	o |= (1 << i);
      } else {
	x |= (1 << i);
      }
    } else if(!(one & (1 << i))) {
      a ^= (1 << i);
    }
  }
  printf("3\n& %d\n^ %d\n| %d\n", a, x, o);
  return 0;
}
