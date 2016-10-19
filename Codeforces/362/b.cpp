#include <cstdio>
#include <cstdlib>

using namespace std;

char a;
char d[110];

int main() {
  scanf("%c.%s", &a, d);
  int ei;
  for(ei = 0; ei >=0; ei++) {
    if(d[ei] == 'e')
      break;
  }
  int b = atoi(d + (ei + 1));
  if(b == 0) {
    if(ei == 1 && d[0] == '0') {
      printf("%c\n", a);
    } else {
      printf("%c.", a);
      for(int i = 0; i < ei; i++)
	printf("%c", d[i]);
      printf("\n");
    }
  } else {
    bool lead = true;
    if(a != '0') {
      printf("%c", a);
      lead = false;
    }
    for(int i = 0; i < ei; i++) {
      if(b == 0) {
	if(lead)
	  printf("0");
	printf(".");
	lead = false;
      }
      if(d[i] != '0' || !lead) {
	printf("%c", d[i]);
	lead = false;
      }
      b--;
    }
    if(lead) {
      printf("0");
      b = 0;
    }
    while(b > 0) {
      printf("0");
      b--;
    }
    printf("\n");
  }
  return 0;
}
