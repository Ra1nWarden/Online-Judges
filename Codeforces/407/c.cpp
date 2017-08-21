#include <cstdio>
#include <cstdlib>
#include <algorithm>

using namespace std;

const int maxn = 100000;
int v[maxn+5];
int n, pre;

int main() {
  scanf("%d", &n);
  scanf("%d", &pre);
  for(int i = 0; i < n - 1; i++) {
    int cur;
    scanf("%d", &cur);
    v[i] = abs(cur - pre);
    pre = cur;
  }
  long long ans = 0;
  long long num = 0;
  long long minVal = 0;
  for(int i = 0; i < n - 1; i++) {
    if(i&1) {
      num -= v[i];
    } else {
      num += v[i];
    }
    ans = max(ans, num - minVal);
    minVal = min(minVal, num);
  }
  num = 0;
  minVal = 0;
  for(int i = 1; i < n - 1; i++) {
    if(i&1) {
      num += v[i];
    } else {
      num -= v[i];
    }
    ans = max(ans, num - minVal);
    minVal = min(minVal, num);
  }
  printf("%I64d\n", ans);
  return 0;
}
