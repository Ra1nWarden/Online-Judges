#include <cstdio>
#include <algorithm>

using namespace std;

const int maxn = 100000;
int v[maxn+5];
int diff[maxn+5];
int n;

int main() {
  scanf("%d", &n);
  for(int i = 0; i < n; i++) {
    scanf("%d", &v[i]);
  }
  for(int i = 0; i < n - 1; i++) {
    diff[i] = v[i+1] - v[i];
  }
  int prev = 0;
  int expect = 0;
  int ans = 0;
  int nonzero = -1;
  for(int i = 0; i < n - 1; i++) {
    if(diff[i] == 0)
      continue;
    if(expect != 0 && expect != diff[i]) {
      ans = max(ans, i - prev);
      prev = nonzero;
    }
    expect = -diff[i];
    nonzero = i+1;
  }
  ans = max(ans, n - prev - 1);
  printf("%d\n", ans + 1);
  return 0;
}
