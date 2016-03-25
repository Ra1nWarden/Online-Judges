#include <cstdio>
#include <cstring>

using namespace std;

const int maxn = 100000;
char str[maxn+5];
int len;

bool mirror(char ch) {
  return ch == 'A' || ch == 'H' || ch == 'I' || ch == 'M' || ch == 'O' || ch == 'T' || ch == 'U' || ch == 'V' || ch == 'W' || ch == 'X' || ch == 'Y';
}

int main() {
  scanf("%s", str);
  len = strlen(str);
  bool ok = true;
  for(int i = 0; i <= len / 2; i++) {
    if(str[i] != str[len - 1 - i]) {
      ok = false;
      break;
    }
    if(!mirror(str[i])) {
      ok = false;
      break;
    }
  }
  printf("%s\n", ok ? "YES" : "NO");
  return 0;
}
