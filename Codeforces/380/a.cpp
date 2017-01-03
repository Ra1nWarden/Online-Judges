#include <cstdio>
#include <cstring>

using namespace std;

const int maxn = 100;
int n;
char str[maxn+5];
int v[maxn+5];
bool p[maxn+5];

int main() {
  scanf("%d\n%s", &n, str);
  memset(v, -1, sizeof v);
  int counter = 0;
  int state = 0;
  for(int i = 0; i < n; i++) {
    switch(state) {
    case 0:
      if(str[i] == 'o') {
	state = 1;
      }
      break;
    case 1:
      counter++;
      if(str[i] == 'g') {
	state = 2;
      } else if(str[i] == 'o') {
	state = 1;
      } else {
	state = 0;
      }
      break;
    case 2:
      if(str[i] == 'o') {
	v[i] = v[i-1] = v[i-2] = counter;
	state = 3;
      } else {
	state = 0;
      }
      break;
    case 3:
      if(str[i] == 'g') {
	state = 2;
      } else if(str[i] == 'o') {
	state = 1;
      } else {
	state = 0;
      }
      break;
    }
  }
  memset(p, false, sizeof p);
  for(int i = 0; i < n; i++) {
    if(v[i] != -1) {
      if(!p[v[i]]) {
	printf("***");
	p[v[i]] = true;
      }
    }
    else {
      printf("%c", str[i]);
    }
  }
  printf("\n");
  return 0;
}
