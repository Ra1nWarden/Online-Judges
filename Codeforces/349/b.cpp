#include <cstdio>
#include <cmath>
#include <algorithm>

using namespace std;

const int maxn = 100000;
int v[maxn+5];
int n;

int main() {
  scanf("%d", &n);
  for(int i = 0; i < n; i++) {
    scanf("%d", &v[i]);
  }
  sort(v, v+n);
  long long l = 0, r = 0;
  for(int i = n-1; i >= 0; i--) {
    if(l < r) {
      l += v[i];
    } else {
      r += v[i];
    }
  }
  printf("%d\n", abs(l - r) + 1);
  return 0;
}
