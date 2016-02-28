#include <cstring>
#include <cstdio>

using namespace std;

const int maxn = 100000;
int C[maxn+5];

int lowbit(int x) {
  return x & (-x);
}

int sum(int x) {
  int ret = 0;
  while(x > 0) {
    ret += C[x];
    x -= lowbit(x);
  }
  return ret;
}

void add(int x, int d) {
  while(x <= maxn) {
    C[x] += d;
    x += lowbit(x);
  }
}

int v[maxn+5];
int left[maxn+5];
int n;

int main() {
  int tc;
  scanf("%d", &tc);
  while(tc--) {
    scanf("%d", &n);
    for(int i = 0; i < n; i++)
      scanf("%d", &v[i]);
    long long ans = 0;
    memset(C, 0, sizeof C);
    for(int i = 0; i < n; i++) {
      left[i] = sum(v[i] - 1);
      add(v[i], 1);
    }
    memset(C, 0, sizeof C);
    for(int i = n - 1; i >= 0; i--) {
      int low = sum(v[i] - 1);
      add(v[i], 1);
      ans += low * 1LL * (i - left[i]);
      ans += (n - 1 - i - low) * 1LL * left[i];
    }
    printf("%lld\n", ans);
  }
  return 0;
}
