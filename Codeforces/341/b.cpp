#include <cstdio>
#include <cstring>

using namespace std;

const int maxn = 2000;
int v1[maxn+5], v2[maxn+5];
const int v1_diff = -2;
const int v2_diff = 999;

long long count(int num) {
  return num * 1LL * (num - 1) / 2;
}

int main() {
  memset(v1, 0, sizeof v1);
  memset(v2, 0, sizeof v2);
  int n;
  scanf("%d", &n);
  for(int i = 0; i < n; i++) {
    int x, y;
    scanf("%d%d", &x, &y);
    v1[x + y + v1_diff]++;
    v2[x - y + v2_diff]++;
  }
  long long ans = 0;
  for(int i = 0; i <= 2000; i++) {
    ans += count(v1[i]);
    ans += count(v2[i]);
  }
  printf("%I64d\n", ans);
  return 0;
}
