#include <cstdio>
#include <algorithm>
#define MAXN 100005

using namespace std;

long long v[MAXN];

int main() {
  int n;
  scanf("%d", &n);
  for(int i = 0; i < n; i++)
    scanf("%I64d", &v[i]);
  sort(v, v+n);
  int ans = 0;
  long long sum = 0;
  for(int i = 0; i < n; i++) {
    if(sum <= v[i]) {
      ans++;
      sum += v[i];
    }
  }
  printf("%d\n", ans);
  return 0;
}
