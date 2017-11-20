#include <cstdio>
#include <algorithm>
#include <functional>

using namespace std;

const int maxn = 1000000;
int v[maxn+5];
int w[maxn+5];
int n, k;

int main() {
  scanf("%d", &n);
  for(int i = 0; i < n; i++) {
    scanf("%d", &v[i]);
  }
  scanf("%d", &k);
  int l = 0, r = 0;
  for(int i = 0; i < n; i++) {
    if(i >= k) {
      printf("%d ", w[l]);
    }
    r = upper_bound(w + l, w + r, v[i], greater<int>()) - w;
    w[r++] = v[i];
    if(i >= k && w[l] == v[i - k])
      l++;
  }
  printf("%d\n", w[l]);
  return 0;
}
