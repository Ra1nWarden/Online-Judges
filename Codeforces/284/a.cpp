#include <iostream>
#include <cstdio>

using namespace std;

int main() {
  int n, x;
  scanf("%d %d", &n, &x);
  int start = 1;
  int result = 0;
  for(int i = 0; i < n; i++) {
    int l, r;
    scanf("%d %d", &l, &r);
    result += (l - start) % x;
    result += (r - l + 1);
    start = r + 1;
  }
  printf("%d\n", result);
  return 0;
}
