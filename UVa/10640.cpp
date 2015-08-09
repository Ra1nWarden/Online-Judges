#include <cstdio>

using namespace std;

int a, b;

int main() {
  int tc;
  scanf("%d", &tc);
  for(int kase = 1; kase <= tc; kase++) {
    scanf("%d %d", &a, &b);
    if(b >= a * 3) {
      printf("Case %d: -1\n", kase);
      continue;
    }
    int n = (3 * b - a) / (3 * a - b);
    if(n % 2) {
      if(n * (3 * a - b) < (3 * b - a)) {
	n += 2;
      }
    } else {
      n++;
    }
    if(n > 10000)
      printf("Case %d: -1\n", kase);
    else
      printf("Case %d: %d\n", kase, n);
  }
  return 0;
}
