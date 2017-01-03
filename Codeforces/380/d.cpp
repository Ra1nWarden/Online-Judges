#include <cstdio>

using namespace std;

int n, a, b, k;
const int maxn = 200000;
char v[maxn+5];
int ans[maxn+5];

int main() {
  scanf("%d%d%d%d\n%s", &n, &a, &b, &k, v);
  int cnt = 0;
  int all = 0;
  for(int i = 0; i < n; i++) {
    if(v[i] == '0') {
      cnt++;
    } else {
      all += cnt / b;
      cnt = 0;
    }
  }
  all += cnt / b;
  int diff = all - a + 1;
  cnt = 0;
  int ai = 0;
  for(int i = 0; i < n && diff > 0; i++) {
    if(v[i] == '0') {
      if(cnt == b - 1) {
	ans[ai++] = i;
	cnt = 0;
	diff--;
      } else {
	cnt++;
      }
    } else {
      cnt = 0;
    }
  }
  printf("%d\n", ai);
  for(int i = 0; i < ai; i++) {
    if(i)
      printf(" ");
    printf("%d", ans[i] + 1);
  }
  printf("\n");
  return 0;
}
