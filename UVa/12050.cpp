#include <cstdio>

using namespace std;

typedef long long LL;
const int maxn = 40;
LL cnt[maxn+5];
int ans[maxn+5];
int n;

void init() {
  cnt[0] = 0, cnt[1] = cnt[2] = 9;
  for(int i = 3; i < maxn / 2; i+=2)
    cnt[i] = cnt[i+1] = cnt[i-1] * 10;
}

int main() {
  init();
  while(scanf("%d", &n) != EOF && n) {
    int len = 1;
    while(n > cnt[len]) {
      n -= cnt[len++];
    }
    n--;
    int cnt = len /2 + 1;
    while(n) {
      ans[cnt++] = n % 10;
      n /= 10;
    }
    for(int i = cnt; i <= len; i++)
      ans[i] = 0;
    ans[len]++;
    for(int i = 1; i <= len / 2; i++)
      ans[i] = ans[len - i + 1];
    for(int i = 1; i <= len; i++)
      printf("%d", ans[i]);
    printf("\n");
  }
  return 0;
}
