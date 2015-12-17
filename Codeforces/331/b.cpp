#include <cstdio>

using namespace std;

int main() {
  int h = 0;
  int n;
  scanf("%d", &n);
  long long ans = 0;
  while(n--) {
    int num;
    scanf("%d", &num);
    ans += num > h ? num - h : h - num;
    h = num;
  }
  printf("%I64d\n", ans);
  return 0;
}
