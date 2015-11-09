#include <cstdio>

using namespace std;

const int maxn = 26;
const int maxl = 200000;
char convert[maxn];
char str[maxl+5];
int n, m;

int main() {
  scanf("%d %d\n", &n, &m);
  scanf("%s\n", str);
  for(int i = 0; i < maxn; i++) {
    convert[i] = 'a' + i;
  }
  for(int i = 0; i < m; i++) {
    char a, b;
    scanf("%c %c\n", &a, &b);
    if(a == b)
      continue;
    for(int j = 0; j < maxn; j++) {
      if(convert[j] == a) {
	convert[j] = b;
      } else if(convert[j] == b) {
	convert[j] = a;
      }
    }
  }
  for(int i = 0; i < n; i++) {
    str[i] = convert[str[i] - 'a'];
  }
  printf("%s\n", str);
  return 0;
}
