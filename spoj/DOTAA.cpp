#include <cstdio>

using namespace std;

int main() {
  int tc;
  int n, m, d;
  scanf("%d", &tc);
  while(tc--) {
    scanf("%d%d%d", &n, &m, &d);
    int x;
    while(n--) {
      scanf("%d", &x);
      m -= (x - 1) / d;
    }
    printf("%s\n", m <= 0 ? "YES" : "NO");
  }
  return 0;
}
