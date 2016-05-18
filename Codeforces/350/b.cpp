#include <cstdio>

using namespace std;

const int maxn = 100000;
int v[maxn+5];
int n, k;

int main() {
  scanf("%d%d", &n, &k);
  for(int i = 0; i < n; i++)
    scanf("%d", &v[i]);
  for(int i = 1; i <= n; i++) {
    if(k <= i) {
      printf("%d\n", v[k - 1]);
      break;
    } else {
      k -= i;
    }
  }
  return 0;
}
