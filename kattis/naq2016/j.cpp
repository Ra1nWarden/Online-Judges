#include <cstdio>
#include <cstring>

using namespace std;

const int maxn = 100;
const int maxl = 105;
char str[maxl+5];
int n;

int main() {
  scanf("%d\n", &n);
  while(n--) {
    scanf("%s\n", str);
    printf("%d\n", strlen(str));
  }
  return 0;
}
