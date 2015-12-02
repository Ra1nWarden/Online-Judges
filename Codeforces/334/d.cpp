#include <cstdio>
#include <cstring>

using namespace std;

const int mod = 1000000007;
const int maxn = 1000000;
int p, k;
bool vis[maxn+5];

int main() {
  scanf("%d%d", &p, &k);
  memset(vis, false, sizeof vis);
  int ans = 1;
  for(int i = 1; i < p; i++) {
    if(vis[i])
      continue;
    int idx = i;
    while(!vis[idx]) {
      vis[idx] = true;
      idx = (idx * 1LL * k) % p;
    }
    ans = (ans * 1LL * p) % mod;
  }
  int zero = 0;
  for(int i = 0; i < p; i++) {
    if((i * 1LL * k) % p == i)
      zero++;
  }
  ans = (ans * 1LL * zero) % mod;
  printf("%d\n", ans);
  return 0;
}
