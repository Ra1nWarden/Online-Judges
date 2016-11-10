#include <cstdio>
#include <cctype>
#include <algorithm>

using namespace std;

const int maxn = 255;
int n;
char str[maxn+5];

int main() {
  scanf("%d\n%s", &n, str);
  int a = 0, b = 0;
  bool p = false;
  int w = 0;
  for(int i = 0; i < n; i++) {
    if(isalpha(str[i])) {
      w++;
    } else {
      if(!p) {
	a = max(a, w);
      } else if(w) {
	b++;
      }
      w = 0;
      if(str[i] == '(') {
	p = true;
      } else if(str[i] == ')') {
	p = false;
      }
    }
  }
  if(w) {
    if(!p) {
      a = max(a, w);
    } else if(w) {
      b++;
    }
    w = 0;
  }
  printf("%d %d\n", a, b);
  return 0;
}
