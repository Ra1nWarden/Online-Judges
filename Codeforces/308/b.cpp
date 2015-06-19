#include <cstdio>

using namespace std;

long long sum[10];

void init() {
  long long start = 9;
  long long mult = 1;
  for(mult = 1; mult <= 9; mult++) {
    sum[mult] = start * mult;
    start *= 10;
  }
}

int main() {
  init();
  int num;
  scanf("%d", &num);
  long long ans = 0;
  int length = 0;
  int numcpy = num;
  while(numcpy > 0) {
    numcpy /= 10;
    length++;
  }
  for(int i = 1; i < length; i++) {
    ans += sum[i];
  }
  int base = 1;
  for(int i = 1; i < length; i++)
    base *= 10;
  ans += (num - base + 1) * 1LL * length;
  printf("%I64d\n", ans);
  return 0;
}
