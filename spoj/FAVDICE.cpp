#include <cstdio>
#include <cmath>

using namespace std;

int main() {
  int tc;
  scanf("%d", &tc);
  while(tc--) {
    int n;
    scanf("%d", &n);
    double ans = 0;
    for(int i = 1; i <= n; i++) {
      ans += 1.0 / i;
    }
    printf("%.2lf\n", ans * n);
  }
  return 0;
}
