#include <cstdio>
#include <algorithm>
#include <functional>

using namespace std;

const int maxn = 100000;
int v[maxn+1];
int vi;
int n;

int main() {
  scanf("%d", &n);
  long long ans = 0;
  vi = 0;
  for(int i = 0; i < n; i++) {
    int num;
    scanf("%d", &num);
    if(num & 1) {
      v[vi++] = num;
    } else {
      ans += num;
    }
  }
  if(vi & 1) {
    sort(v, v+vi, greater<int>());
    for(int i = 0; i < vi - 1; i++)
      ans += v[i];
  } else {
    for(int i = 0; i < vi; i++)
      ans += v[i];
  }
  printf("%I64d\n", ans);
  return 0;
}
