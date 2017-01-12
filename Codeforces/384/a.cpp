#include <cstdio>

using namespace std;

const int maxn = 100000;
char str[maxn+5];
int n, a, b;

int main() {
  scanf("%d%d%d\n", &n, &a, &b);
  scanf("%s", str+1);
  printf("%d\n", str[a] == str[b] ? 0 : 1);
  return 0;
}
