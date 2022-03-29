#include <cstdio>
#include <cstring>

using namespace std;

const int maxn = 100;
int v[maxn*2+5];
bool vis[maxn*2+5];
int idx[maxn+5][2];
int n;
int bit[maxn*2+5];

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

void add(int x) {
  while(x <= maxn*2) {
    bit[x] += 1;
    x += lowbit(x);
  }
}

int main() {
  scanf("%d", &n);
  memset(idx, 0, sizeof idx);
  for(int i = 1; i <= 2 * n; i++) {
    scanf("%d", &v[i]);
    if(idx[v[i]][0] == 0)
      idx[v[i]][0] = i;
    else
      idx[v[i]][1] = i;
  }
  
  memset(bit, 0, sizeof bit);
  memset(vis, false, sizeof vis);
  int ans = 0;
  for(int i = 1; i <= n*2; i++) {
    if(vis[v[i]])
      continue;
    vis[v[i]] = true;
    int a = idx[v[i]][0];
    int b = idx[v[i]][1];
    int dist = b - a - 1;
    if(b > a + 1) {
      dist -= sum(b-1) - sum(a);
    }
    add(a);
    add(b);
    ans += dist;
  }

  printf("%d\n", ans);
  
  return 0;
}
