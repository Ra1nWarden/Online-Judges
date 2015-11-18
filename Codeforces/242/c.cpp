#include <cstdio>
#include <map>

using namespace std;

const int maxn = 1000000;
int v[maxn];

int main() {
  int n;
  scanf("%d", &n);
  v[0] = 0;
  for(int i = 1; i < n; i++) {
    v[i] = v[i-1] ^ i;
  }
  int ans = 0;
  for(int i = 1; i <= n; i++) {
    int num;
    scanf("%d", &num);
    ans ^= num;
    ans ^= v[n % i];
    if((n / i) % 2)
      ans ^= v[i - 1];
  }
  printf("%d\n", ans);
  return 0;
}
