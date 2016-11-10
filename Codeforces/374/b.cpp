#include <cstdio>
#include <cstring>

using namespace std;

const int maxn = 100;
char str[maxn+5][maxn+5];
int n, k;
char p[maxn+5];

int f(int x) {
  return (x - 1) / k * 5 + x;
}

int main() {
  scanf("%d%d\n", &n, &k);
  for(int i = 0; i < n; i++) {
    scanf("%s\n", str[i]);
  }
  scanf("%s", p);
  int pl = strlen(p);
  int l = 0, r = 0;
  for(int i = 0; i < n; i++) {
    int len = strlen(str[i]);
    if(len < pl) {
      l++;
    } else if(len == pl) {
      r++;
    }
  }
  printf("%d %d\n", f(l+1), f(l+r));
  return 0;
}
