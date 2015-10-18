#include <algorithm>
#include <cstdio>

using namespace std;

const int maxn = 100000;

int v[maxn+5];
int ans[maxn+5];
int n;

int main() {
  scanf("%d", &n);
  for(int i = 0; i < n; i++) {
    scanf("%d", &v[i]);
  }
  int max_val = -1;
  for(int i = n - 1; i >= 0; i--) {
    if(v[i] > max_val) {
      ans[i] = 0;
    } else {
      ans[i] = max_val - v[i] + 1;
    }
    max_val = max(max_val, v[i]);
  }
  for(int i = 0; i < n; i++) {
    if(i > 0)
      printf(" ");
    printf("%d", ans[i]);
  }
  printf("\n");
  return 0;
}
