#include <cstdio>
#include <cstring>

using namespace std;

const int maxn = 10000000;
int bit[maxn+5];
int n;

int lowbit(int x) {
  return x & (-x);
}

int sum(int x) {
  int ret = 0;
  while(x > 0) {
    ret += bit[x];
    x -= lowbit(x);
  }
  return ret;
}

void add(int x, int d) {
  while(x <= maxn - 1) {
    bit[x] += d;
    x += lowbit(x);
  }
}

int main() {
  int tc;
  scanf("%d", &tc);
  while(tc--) {
    scanf("%d", &n);
    memset(bit, 0, sizeof bit);
    long long ans = 0;
    int x;
    for(int i = 0; i < n; i++) {
      scanf("%d", &x);
      ans += i - sum(x-1);
      add(x, 1);
    }
    printf("%lld\n", ans);
  }
  return 0;
}
