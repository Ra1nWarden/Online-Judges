#include <cstdio>
#include <cstring>
#define MAXL 25

using namespace std;

char s[MAXL];
int len;

int main() {
  scanf("%s", s);
  len = strlen(s);
  printf("%d\n", 26 + 25 * len);
  return 0;
}
