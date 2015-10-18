#include <cstdio>
#include <cstring>
#include <vector>

using namespace std;

typedef long long LL;

const int maxn = 40000;
const LL mod = 1000000007LL;
int n, m;
vector<int> children[maxn+5];
LL fn[maxn+5];

void gcd(LL a, LL b, LL& d, LL& x, LL& y) {
  if(!b) {
    d = a;
    x = 1;
    y = 0;
  } else {
    gcd(b, a % b, d , y, x);
    y -= x * (a / b);
  }
}

long long inverse(int a) {
  long long d, k, x;
  gcd(a, mod, d, x, k);
  x *= (1 / d);
  while(x < 0)
    x += mod;
  return x;
}

LL f(int a) {
  if(fn[a] != -1)
    return fn[a];
  int ans = 1;
  for(int i = 0; i < children[a].size(); i++) {
    ans += f(children[a][i]);
  }
  return fn[a] = ans;
}

int main() {
  int tc;
  scanf("%d", &tc);
  while(tc--) {
    scanf("%d%d", &n, &m);
    for(int i = 1; i <= n; i++) {
      children[i].clear();
    }
    for(int i = 0; i < m; i++) {
      int a, b;
      scanf("%d%d", &a, &b);
      children[b].push_back(a);
    }
    LL ans = 1;
    for(int i = 1; i <= n; i++) {
      ans = (ans * i) % mod;
    }
    memset(fn, -1, sizeof fn);
    for(int i = 1; i <= n; i++) {
      ans = (ans * inverse(f(i))) % mod;
    }
    printf("%lld\n", ans);
  }
  return 0;
}
