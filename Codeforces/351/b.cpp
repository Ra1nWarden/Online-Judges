#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

int n, m;
const int maxm = 100000;
bool used[maxm+5];

int main() {
  scanf("%d%d", &n, &m);
  int minb = n;
  int maxa = 1;
  memset(used, false, sizeof used);
  for(int i = 0; i < m; i++) {
    int a, b;
    scanf("%d%d", &a, &b);
    if(a > b)
      swap(a, b);
    used[a] = true;
    used[b] = true;
    minb = min(minb, b);
    maxa = max(maxa, a);
  }
  int ans = minb > maxa ? 1 : 0;
  for(int i = maxa+1; i < minb; i++) {
    if(!used[i])
      ans++;
  }
  printf("%d\n", ans);
  return 0;
}
