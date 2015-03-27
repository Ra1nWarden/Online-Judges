#include <cstdio>
#include <algorithm>
#define MAXN 105
#define INF 2000000000

using namespace std;

int n, m;

int main() {
  while(scanf("%d %d", &n, &m) != EOF) {
    int res = INF;
    for(int i = 0; i < m; i++) {
      int a, b;
      scanf("%d %d", &a, &b);
      res = min(res, n % a == 0 ? n / a * b : (n / a + 1) * b);
    }

    printf("%d\n", res);
  }
  return 0;
}
