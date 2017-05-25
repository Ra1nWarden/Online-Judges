#include <cstdio>
#include <algorithm>

using namespace std;

int g, b;

bool ok(int m) {
  int l = (g + m - 1) / m;
  for(int div = l; div <= g; div++) {
    if(b >= div - 1 && (div + 1) * m >= b) {
      return true;
    }
  }
  l = (b + m - 1) / m;
  for(int div = l; div <= b; div++) {
    if(g >= div - 1 && (div + 1) * m >= g) {
      return true;
    }
  }
  return false;
}

int main() {
  while(scanf("%d%d", &g, &b)) {
    if(g == -1 && b == -1)
      break;
    if(g == 0 && b == 0) {
      printf("0\n");
      continue;
    }
    if(g == 0) {
      printf("%d\n", b);
      continue;
    }
    if(b == 0) {
      printf("%d\n", g);
      continue;
    }
    int left = 1, right = max(g, b);
    while(left != right) {
      int mid = (left + right) >> 1;
      if(ok(mid)) {
	right = mid;
      } else {
	left = mid + 1;
      }
    }
    printf("%d\n", left);
  }
  return 0;
}
