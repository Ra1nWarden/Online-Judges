#include <cstdio>
#include <algorithm>

using namespace std;

const int maxn = 300000;
int v[maxn+5];
int n, m;

int main() {
  scanf("%d%d", &n, &m);
  for(int i = 0; i < n; i++)
    scanf("%d", &v[i]);
  int sum = 0;
  int l = 0, r = 0;
  int ans = 0;
  while(r < n || l < n) {
    if(sum <= m)
      ans = max(sum, ans);
    if(sum <= m && r < n) {
      sum += v[r++];
    } else {
      sum -= v[l++];
    }
  }
  printf("%d\n", ans);
  return 0;
}
