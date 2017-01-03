#include <cstdio>
#include <algorithm>

using namespace std;

const int maxn = 200000;
int v[maxn+5];
int n;

int main() {
  scanf("%d", &n);
  for(int i = 0; i < n; i++)
    scanf("%d", &v[i]);
  sort(v, v+n);
  long long ans = 0;
  int prev = 0;
  for(int i = 0; i < n; i++) {
    if(v[i] == prev)
      continue;
    long long cur = 0;
    int start = i;
    for(int mult = 1; mult > 0; mult++) {
      int end = lower_bound(v, v + n, (mult + 1) * v[i]) - v;
      cur += mult * 1LL * v[i] * (end - start);
      if(end == n)
	break;
      start = end;
    }
    ans = max(ans, cur);
    prev = v[i];
  }
  printf("%I64d\n", ans);
  return 0;
}
