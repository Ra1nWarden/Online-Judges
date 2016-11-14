#include <cstdio>
#include <cstring>

using namespace std;

const int maxn = 200000;
const int mod = 1000000007;
int mods[maxn+5];
int v[maxn+5], visited[maxn+5], d[maxn+5];
int n, f;

void init() {
  mods[0] = 1;
  for(int i = 1; i <= maxn; i++) {
    mods[i] = (mods[i-1] * 1LL * 2) % mod;
  }
}

int main() {
  init();
  scanf("%d", &n);
  for(int i = 1; i <= n; i++)
    scanf("%d", &v[i]);
  f = n;
  memset(visited, 0, sizeof visited);
  memset(d, 0, sizeof d);
  int vis = 1;
  int ans = 1;
  for(int i = 1; i <= n; i++) {
    if(visited[i] != 0)
      continue;
    int cur = i;
    int dis = 0;
    while(visited[cur] == 0) {
      visited[cur] = vis;
      d[cur] = dis;
      dis++;
      cur = v[cur];
    }
    if(visited[cur] == vis) {
      int dd = dis - d[cur];
      f -= dd;
      ans = (ans * 1LL * ((mods[dd] - 2 + mod) % mod)) % mod;
    }
    vis++;
  }
  printf("%d\n", (ans * 1LL * mods[f]) % mod);
  return 0;
}
