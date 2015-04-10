#include <cstdio>

using namespace std;

long long n;

int main() {
  scanf("%I64d", &n);
  long long start = 0;
  if(n % 3 == 2) {
    start = 1;
  } else if(n % 3 == 1) {
    start = 2;
  } else {
    start = 3;
  }
  int ans = 0;
  for(long long i = start; i < 1000000; i += 3) {
    long long count = (1 + i) * i;
    count += (i - 1) * i / 2; 
    if(count <= n)
      ans++;
    else
      break;
  }
  printf("%d\n", ans);
  return 0;
}
