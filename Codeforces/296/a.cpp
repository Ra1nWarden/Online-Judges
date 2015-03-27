#include <cstdio>
#include <algorithm>

using namespace std;

int main() {
  long long a, b;
  scanf("%I64d %I64d", &a, &b);
  long long res = 0;
  long long small = min(a, b);
  long long big = max(a, b);
  while(big != small) {
    long long count = big / small;
    res += count;
    big -= count * small;
    if(big == 0)
      break;
    swap(big, small);
  }
  if(big != 0)
    res++;
  printf("%I64d\n", res);
  return 0;
}
