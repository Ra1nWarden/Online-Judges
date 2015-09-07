#include <cstdio>
#include <algorithm>

using namespace std;

int n, m;

int main() {
  while(scanf("%d%d", &n, &m) != EOF) {
    bool connected = false;
    for(int i = 0; i < m; i++) {
      int a, b;
      scanf("%d%d", &a, &b);
      if(min(a, b) == 1 && max(a, b) == n) {
	connected = true;
      }
    }
    if(connected)
      printf("1 %d\n", n*(n-1)/2);
    else
      printf("1 %d\n", 1);
  }
  return 0;
}
