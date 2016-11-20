#include <cstdio>

using namespace std;

const int maxn = 100000;
char str[maxn+5];
int n;

int main() {
  scanf("%d\n", &n);
  scanf("%s", str);
  int a = 0, d = 0;
  for(int i = 0; i < n; i++) {
    if(str[i] == 'A')
      a++;
    else
      d++;
  }
  if(a == d) {
    printf("Friendship\n");
  } else {
    printf("%s\n", a > d ? "Anton" : "Danik");
  }
  return 0;
}
