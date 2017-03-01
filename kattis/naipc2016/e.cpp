#include <cstdio>
#include <bitset>

using namespace std;

bitset<1000000> num, rev;
const int maxn = 1000000;
char str[maxn+5];

int main() {
  scanf("%s", str);
  int i;
  for(i = 0; true; i++) {
    if(str[i] == 0)
      break;
    if(str[i] == 'A') {
      num.set(i, 0);
      rev.set(i, 1);
    } else {
      num.set(i, 1);
      rev.set(i, 0);
    }
  }
  while(i > 1) {
    rev >>= 1;
    printf("%d\n", (num & rev).count());
    i--;
  }
  return 0;
}
