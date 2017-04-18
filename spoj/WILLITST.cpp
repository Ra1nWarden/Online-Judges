#include <cstdio>

using namespace std;

int main() {
  long long num;
  scanf("%lld", &num);
  while(num != 3 && num != 1) {
    if(num & 1) {
      num = (num + 1) / 2 * 3;
    } else {
      num = num >> 1;
    }
  }
  printf("%s\n", num == 1 ? "TAK" : "NIE");
  return 0;
}
