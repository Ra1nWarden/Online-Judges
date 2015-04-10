#include <cstdio>
#include <cstdlib>
#include <cstring>
#define MAXL (1<<8)+5

using namespace std;

char str[MAXL];
char codes[8][MAXL];

char getch() {
  char next;
  while(true) {
    next = getchar();
    if(next != '\n' && next != '\r')
      break;
  }
  return next;
}

int getnumber(int n) {
  int ans = 0;
  for(int i = 0; i < n; i++) {
    char next = getch();
    if(next == '1') {
      ans += (1 << (n - i - 1));
    }
  }
  return ans;
}

int main() {
  while(true) {
    int index = 0;
    while(true) {
      char next = getchar();
      if(next == '\n' || next == '\r')
	break;
      if(next == EOF)
	return 0;
      str[index++] = next;
    }
    if(index == 0)
      break;
    str[index] = '\0';
    for(int i = 0; i < strlen(str); i++) {
      int len = 1;
      int offset = 0;
      while(true) {
	int total = 0;
	for(int j = 1; j <= len; j++) {
	  total += (1 << j) - 1;
	}
	if(total > i) {
	  offset = i - (total - (1 << len) + 1);
	  break;
	}
	len++;
      }
      //printf("putting %c to codes[%d][%d]\n", str[i], len, offset);
      codes[len][offset] = str[i];
    }
    while(true) {
      int length = getnumber(3);
      if(length == 0) {
	printf("\n");
	getchar(); // consume the last end of line character
	break;
      }
      while(true) {
	int num = getnumber(length);
	if(num == (1 << length) - 1)
	  break;
	//printf("printing codes[%d][%d]\n", length, num);
	printf("%c", codes[length][num]);
      }
    }
  }
  return 0;
}
