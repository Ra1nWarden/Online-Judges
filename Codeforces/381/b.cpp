#include <cstdio>
#include <cstring>

using namespace std;

const int maxn = 100;
int v[maxn+5];
int sum[maxn+5];
int n, m;

int main() {
  scanf("%d%d", &n, &m);
  memset(v, 0, sizeof v);
  memset(sum, 0, sizeof sum);
  int cur = 0;
  for(int i = 1; i <= n; i++) {
    scanf("%d", &v[i]);
    cur += v[i];
    sum[i] = cur;
  }
  int l, r;
  int total = 0;
  for(int i = 0; i < m; i++) {
    scanf("%d%d", &l, &r);
    if(sum[r] - sum[l-1] > 0) {
      total += sum[r] - sum[l-1];
    }
  }
  printf("%d\n", total);
  return 0;
}
