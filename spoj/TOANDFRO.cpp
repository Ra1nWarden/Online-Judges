#include <cstdio>
#include <cstring>

using namespace std;

const int maxl = 200;
char str[maxl+5];

int main() {
  int c;
  while(scanf("%d\n", &c)) {
    if(c == 0)
      break;
    scanf("%s\n", str);
    int len = strlen(str);
    for(int i = 0; i < c; i++) {
      int idx = i;
      int delta = c * 2 - i * 2 - 1;
      while(idx < len) {
	printf("%c", str[idx]);
	idx += delta;
	delta = c * 2 - delta;
      }
    }
    printf("\n");
  }
  return 0;
}
