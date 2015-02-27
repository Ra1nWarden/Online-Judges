#include <cstdio>
#define MAXN 10001

using namespace std;

int f[MAXN];

int main() {
  int n, k, m;
  while(scanf("%d %d %d", &n, &k, &m) != EOF && (n || k || m)) {
    f[1] = 0;
    for(int i = 2; i <= n; i++) {
      f[i] = (f[i - 1] + k) % i;
    }
    int ans = (m - k + 1 + f[n]) % n;
    if(ans <= 0)
      ans += n;
    printf("%d\n", ans);
  }
  return 0;
}
