#include <cstdio>

using namespace std;

const int maxn = 1000;
int n;
char str[maxn+5];

int main() {
  scanf("%d\n%s", &n, str+1);
  int start, end;
  char c = '.';
  bool diff = false;
  for(int i = 1; i <= n; i++) {
    if(str[i] != '.') {
      if(c == '.') {
	start = i;
	c = str[i];
      } else if(c != str[i]) {
	diff = true;
	end = i;
	break;
      }
    } else if(c != '.') {
      if(c == 'L') {
	end = start - 1;
      } else {
	end = i;
      }
      break;
    }
  }
  printf("%d %d\n", start, end);
  return 0;
}
