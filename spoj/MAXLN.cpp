#include <cstdio>

using namespace std;

int main() {
  int tc;
  scanf("%d", &tc);
  for(int i = 1; i <= tc; i++) {
    long long num;
    scanf("%lld", &num);
    printf("Case %d: %lld.25\n", i, 4 * num * num);
  }
  return 0;
}
