#include <cstdio>

using namespace std;

const int maxn = 100;
char str[maxn+5];
int n;
int ans[maxn+5];
int ai;

int main() {
  scanf("%d\n%s", &n, str);
  ai = 0;
  int cnt = 0;
  for(int i = 0; i < n; i++) {
    if(str[i] == 'B') {
      cnt++;
    } else {
      if(cnt != 0) {
	ans[ai++] = cnt;
	cnt = 0;
      }
    }
  }
  if(cnt != 0) {
    ans[ai++] = cnt;
  }
  printf("%d\n", ai);
  if(ai) {
    for(int i = 0; i < ai; i++) {
      if(i)
	printf(" ");
      printf("%d", ans[i]);
    }
    printf("\n");
  }
  return 0;
}
