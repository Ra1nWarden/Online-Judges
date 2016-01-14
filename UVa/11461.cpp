#include <cstdio>
#include <cmath>

using namespace std;

int cnt(int num) {
  int l = 0, r = 316;
  while(l != r) {
    int m = l + (r - l) / 2 + 1;
    if(m * m > num) {
      r = m - 1;
    } else {
      l = m;
    }
  }
  return r;
}

int main() {
  int a, b;
  while(scanf("%d%d", &a, &b) != EOF && (a || b)) {
    a--;
    printf("%d\n", cnt(b) - cnt(a));
  }
  return 0;
}
