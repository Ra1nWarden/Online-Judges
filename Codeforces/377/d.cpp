#include <cstdio>
#include <cstring>

using namespace std;

const int maxn = 100000;
int t[maxn+5];
int v[maxn+5];
int o[maxn+5];
int d[maxn+5];
int n, m;

bool test(int x) {
  memset(d, -1, sizeof d);
  int idx = m;
  for(int i = x; i >= 1; i--) {
    if(t[i] == 0 || d[t[i]] != -1) {
      continue;
    }
    o[idx--] = t[i];
    d[t[i]] = i;
  }
  if(idx != 0)
    return false;
  int total = 0;
  for(int i = 1; i <= m; i++) {
    total += v[o[i]];
    if(total + i > d[o[i]])
      return false;
  }
  return true;
}

int main() {
  scanf("%d%d", &n, &m);
  for(int i = 1; i <= n; i++)
    scanf("%d", &t[i]);
  for(int i = 1; i <= m; i++)
    scanf("%d", &v[i]);
  int l = 1, r = n + 1;
  while(l != r) {
    int mid = (l + r) >> 1;
    if(test(mid)) {
      r = mid;
    } else {
      l = mid + 1;
    }
  }
  if(l == n + 1)
    printf("-1\n");
  else
    printf("%d\n", l);
  return 0;
}
