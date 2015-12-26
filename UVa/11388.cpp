#include <cstdio>

using namespace std;

int main() {
  int tc;
  scanf("%d", &tc);
  while(tc--) {
    int m, n;
    scanf("%d%d", &m, &n);
    if(n % m) {
      printf("-1\n");
    } else {
      printf("%d %d\n", m, n);
    }
  }
  return 0;
}
