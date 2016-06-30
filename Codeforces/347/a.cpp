#include <cstdio>
#include <cstring>

using namespace std;

const int maxl = 100;
char a[maxl+5];
char b[maxl+5];

int main() {
  scanf("%s %s\n", a, b);
  if(strcmp(a, b) == 0) {
    printf("%s\n", a);
  } else {
    printf("1\n");
  }
  return 0;
}
