#include <cstdio>

using namespace std;

int main() {
  int tc;
  scanf("%d", &tc);
  while(tc--) {
    long long num;
    scanf("%lld", &num);
    long long ans = 0;
    for(long long div = 1; div <= num; div++) {
      long long add = num / div;
      long long upper = num / add;
      ans += (add * (upper - div + 1));
      div = upper;
    }
    printf("%lld\n", ans);
  }
  return 0;
}
