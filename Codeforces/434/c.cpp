#include <cstdio>
#include <cstring>

using namespace std;

const int maxn = 3000;
char str[maxn+5];

bool isvowel(char c) {
  return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
}

int main() {
  scanf("%s\n", str);
  char cur = 0;
  int cnt = 0;
  int combo = 0;
  for(int i = 0; i >= 0; i++) {
    if(!str[i]) {
      break;
    }
    if(isvowel(str[i])) {
      cur = 0;
      cnt = 0;
      combo = 0;
    } else {
      cnt++;
      if(cur == 0) {
	cur = str[i];
	combo++;
      } else if(str[i] == cur) {
	combo++;
      } else {
	cur = str[i];
	combo = 1;
      }
    }
    if(cnt > 2 && combo < cnt) {
      printf(" ");
      cnt = 1;
      combo = 1;
    }
    printf("%c", str[i]);
  }
  printf("\n");
  return 0;
}
