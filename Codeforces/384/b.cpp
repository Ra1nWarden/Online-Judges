#include <cstdio>

using namespace std;

int main() {
  int n;
  long long k;
  scanf("%d %I64d\n", &n, &k);
  int ans = 1;
  while(!(k & 1LL)) {
    k >>= 1;
    ans++;
  }
  printf("%d\n", ans);
  return 0;
}
