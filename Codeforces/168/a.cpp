#include <cstdio>
#include <map>

using namespace std;

const int maxn = 100000;
int n, k;
int v[maxn+5];
int fa[maxn+5];
map<int, int> pos;

int find_set(int a) {
  return fa[a] == a ? a : fa[a] = find_set(fa[a]);
}

void union_set(int a, int b) {
  fa[find_set(a)] = find_set(b);
}

map<int, int> cnt;

int main() {
  scanf("%d%d", &n, &k);
  for(int i = 1; i <= n; i++) {
    scanf("%d", &v[i]);
    fa[i] = i;
    pos[v[i]] = i;
  }
  for(int i = 1; i <= n; i++) {
    if(v[i] % k == 0) {
      int div = v[i] / k;
      if(pos.count(div)) {
	union_set(pos[div], i);
      }
    }
  }
  for(int i = 1; i <= n; i++) {
    int p = find_set(i);
    if(cnt.count(p))
      cnt[p]++;
    else
      cnt[p] = 1;
  }
  int ans = 0;
  for(map<int, int>::iterator itr = cnt.begin(); itr != cnt.end(); itr++) {
    ans += (itr->second + 1) / 2;
  }
  printf("%d\n", ans);
  return 0;
}

