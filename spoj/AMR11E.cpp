#include <cstdio>
#include <cstring>

using namespace std;

const int maxn = 10000;
int cnt[maxn+5];
int ans[maxn+5];

void init() {
  memset(cnt, 0, sizeof cnt);
  for(int i = 2; i < maxn; i++) {
    if(cnt[i]) {
      continue;
    }
    for(int j = i; j < maxn; j += i) {
      cnt[j]++;
    }
  }
  int idx = 1;
  for(int i = 0; i < maxn; i++) {
    if(cnt[i] > 2) {
      ans[idx++] = i;
    }
  }
}

int main() {
  init();
  int tc;
  scanf("%d", &tc);
  while(tc--) {
    int num;
    scanf("%d", &num);
    printf("%d\n", ans[num]);
  }
  return 0;
}
