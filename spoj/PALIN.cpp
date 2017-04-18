#include <cstdio>
#include <cstring>

using namespace std;

const int maxl = 1000000;
char num[maxl+5];
int len;

int main() {
  int tc;
  scanf("%d\n", &tc);
  while(tc--) {
    scanf("%s\n", num);
    len = strlen(num);
    int li = len / 2 - 1;
    int ri = len / 2;
    if(len & 1)
      ri++;
    bool inc = true;
    while(li >= 0) {
      if(num[li] > num[ri]) {
	inc = false;
	break;
      } else if(num[li] < num[ri]) {
	break;
      }
      li--;
      ri++;
    }
    if(inc) {
      int idx = len / 2;
      if(!(len & 1))
	idx--;
      while(idx >= 0) {
	if(num[idx] == '9') {
	  num[idx] = '0';
	  idx--;
	} else {
	  num[idx]++;
	  break;
	}
      }
      if(idx == -1) {
	printf("1");
	for(int i = 0; i < len - 1; i++) {
	  printf("0");
	}
	printf("1\n");
	continue;
      }
    }
    for(int i = 0; i < len / 2; i++) {
      printf("%c", num[i]);
    }
    if(len & 1) {
      printf("%c", num[len / 2]);
    }
    for(int i = len / 2 - 1; i >= 0; i--) {
      printf("%c", num[i]);
    }
    printf("\n");
  }
  return 0;
}
