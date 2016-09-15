#include <cstdio>
#include <cstring>

using namespace std;

const int maxn = 100000;
int v[maxn+5];
bool cap[maxn+5];
int n, k;

int main() {
  scanf("%d%d", &n, &k);
  for(int i = 1; i <= n; i++) {
    scanf("%d", &v[i]);
  }
  memset(cap, false, sizeof cap);
  int x;
  for(int i = 1; i <= k; i++) {
    scanf("%d", &x);
    cap[x] = true;
  }
  long long ans = 0;
  int prefix = 0;
  int cur = 0;
  for(int i = 1; i <= n; i++) {
    if(cap[i]) {
      ans += v[i] * 1LL * prefix;
    } else {
      ans += v[i] * 1LL * cur;
    }
    cur += v[i];
    prefix += v[i];
    if(i > 1 && !cap[i-1])
      cur -= v[i-1];
  }
  if(!cap[1] && !cap[n])
    ans += v[1] * 1LL * v[n];
  printf("%I64d\n", ans);
  return 0;
}
