#include <cstdio>

using namespace std;

const int maxn = 100000;
char str[maxn+5];

int main() {
  scanf("%s", str);
  int diff = 1;
  for(int i = 0; i >= 0; i += diff) {
    if(str[i] == '\0') {
      i--;
      diff = -1;
    }
    printf("%c", str[i]);
  }
  printf("\n");
  return 0;
}
