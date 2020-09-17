#include <cstdio>

using namespace std;

int n;
const int maxn = 100000;
int v[maxn+5];
int d[maxn+5];

int main() {
  scanf("%d", &n);
  for(int i = 0; i < n; i++)
    scanf("%d", &v[i]);
  int cur = 0;
  for(int i = 0; i < n; i++) {
    if(v[i] + 1 > cur) {
      d[i] = v[i] + 1;
      cur = v[i] + 1;
    } else {
      d[i] = cur;
    }
  }
  for(int i = n - 2; i >= 0; i--) {
    if(d[i+1] - d[i] > 1) {
      d[i] = d[i+1] - 1;
    }
  }
  long long ans = 0;
  for(int i = 0; i < n; i++) {
    ans += d[i] - 1 - v[i];
  }
  printf("%I64d\n", ans);
  return 0;
}
