#include <cstdio>
#include <cstring>

using namespace std;

const int maxn = 10000;
int s[maxn+5];
int v[maxn+5];
int n;

int main() {
  int tc;
  scanf("%d", &tc);
  int u;
  while(tc--) {
    scanf("%d %d", &n, &u);
    int l, r, val;
    memset(s, 0, sizeof s);
    for(int i = 0; i < u; i++) {
      scanf("%d %d %d", &l, &r, &val);
      s[l] += val;
      s[r+1] -= val;
    }
    int cur = 0;
    for(int i = 0; i < n; i++) {
      cur += s[i];
      v[i] = cur;
    }
    int q;
    scanf("%d", &q);
    while(q--) {
      int idx;
      scanf("%d", &idx);
      printf("%d\n", v[idx]);
    }
  }
  return 0;
}
