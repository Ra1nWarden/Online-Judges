#include <cstdio>
#include <algorithm>
#include <cmath>

using namespace std;

const int maxn = 10000;
int v[maxn+5];

int main() {
  int n;
  while(scanf("%d", &n)) {
    if(n == -1)
      break;
    int sum = 0;
    for(int i = 1; i <= n; i++) {
      scanf("%d", &v[i]);
      sum += v[i];
    }
    if(sum % n != 0) {
      printf("-1\n");
      continue;
    }
    int mid = sum / n;
    int ans = 0;
    for(int i = 1; i <= n; i++) {
      ans += abs(mid - v[i]);
    }
    printf("%d\n", ans / 2); 
  }
  return 0;
}
