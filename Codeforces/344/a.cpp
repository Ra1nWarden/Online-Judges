#include <cstdio>

using namespace std;

int main() {
  int n;
  scanf("%d", &n);
  long long sum = 0;
  for(int i = 0; i < 2; i++) {
    long long sub = 0;
    long long num;
    for(int j = 0; j < n; j++) {
      scanf("%I64d", &num);
      sub |= num;
    }
    sum += sub;
  }
  printf("%I64d\n", sum);
  return 0;
}
