#include <cstdio>
#include <cstring>

using namespace std;

const int maxl = 100;
char x[maxl+5];
char y[maxl+5];
char z[maxl+5];
int len;

int main() {
  scanf("%s\n", x);
  scanf("%s", y);
  len = strlen(x);
  bool ok = true;
  for(int i = 0; i < len; i++) {
    if(x[i] < y[i]) {
      ok = false;
      break;
    } else {
      z[i] = y[i];
    }
  }
  z[len] = '\0';
  if(ok) {
    printf("%s\n", z);
  } else {
    printf("-1\n");
  }
  return 0;
}
