#include <cstdio>

const int maxn = 100000;
char str[maxn+5];

int main() {
  scanf("%s\n", str);
  int i = 0;
  while(str[i] == 'a')
    i++;
  if(str[i] == 0) {
    str[i-1] = 'z';
    printf("%s\n", str);
    return 0;
  }
  while(str[i] != 0) {
    if(str[i] == 'a')
      break;
    str[i] = str[i] - 1;
    i++;
  }
  printf("%s\n", str);
  return 0;
}
