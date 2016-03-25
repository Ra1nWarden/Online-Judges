#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int maxn = 1000;
int v[maxn+5];
int cnt[maxn+5];
int ci;
int n;

int main() {
  scanf("%d", &n);
  for(int i = 0; i < n; i++)
    scanf("%d", &v[i]);
  sort(v, v+n);
  memset(cnt, 0, sizeof cnt);
  ci = -1;
  int prev = 0;
  for(int i = 0; i < n; i++) {
    if(v[i] > prev) {
      ci++;
    }
    cnt[ci]++;
    prev = v[i];
  }
  ci++;
  sort(cnt, cnt+ci);
  prev = 0;
  int ans = 0;
  for(int i = 0; i < ci; i++) {
    if(cnt[i] > prev) {
      ans += (cnt[i] - prev) * (ci - 1 - i);
    }
    prev = cnt[i];
  }
  printf("%d\n", ans);
  return 0;
}
