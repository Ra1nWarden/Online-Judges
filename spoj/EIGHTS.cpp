#include <cstdio>

using namespace std;

int main() {
  int tc;
  scanf("%d", &tc);
  long long k;
  while(tc--) {
    scanf("%lld", &k);
    printf("%lld\n", 250 * 1LL * (k - 1) + 192);
  }
  return 0;
}
