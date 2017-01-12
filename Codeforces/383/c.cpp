#include <cstdio>
#include <cstring>

using namespace std;

const int maxn = 100;
int n;
int v[maxn+5];
bool vis[maxn+5];
long long ans;

long long gcd(long long a, long long b) {
  return b == 0 ? a : gcd(b, a % b);
}

long long lcm(long long a, long long b) {
  return a * (b / gcd(a, b));
}

int main() {
  scanf("%d", &n);
  for(int i = 1; i <= n; i++)
    scanf("%d", &v[i]);
  memset(vis, false, sizeof vis);
  ans = 1;
  bool ok = true;
  for(int i = 1; i <= n; i++) {
    if(vis[i])
      continue;
    long long each = 0;
    int cur = i;
    while(!vis[cur]) {
      vis[cur] = true;
      cur = v[cur];
      each++;
    }
    if(cur != i) {
      ok = false;
      break;
    }
    ans = lcm(ans, (each & 1) ? each : each / 2);
  }
  printf("%I64d\n", ok ? ans : -1LL);
  return 0;
}
