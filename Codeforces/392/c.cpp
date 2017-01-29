#include <cstdio>

using namespace std;

long long n, m, x, y;
long long k;

int main() {
  scanf("%I64d%I64d%I64d%d%d", &n, &m, &k, &x, &y);
  if(k <= n * m) {
    printf("1 %d %d\n", k == n * m ? 1 : 0, (x - 1) * m + y <= k ? 1 : 0);
    return 0;
  }
  if(n == 1) {
    long long maxv = k % m == 0 ? k / m : k / m + 1;
    long long minv = k / m;
    printf("%I64d %I64d %I64d\n", maxv, minv, (k % m) < y ? minv : maxv);
    return 0;
  }
  k -= n * m;
  long long each = (n - 1) * m;
  long long rounds = k / each;
  long long maxv = k % each > 0 ? rounds + 1 : rounds;
  if(n == 2)
    maxv = (maxv + 1) / 2;
  long long minv = rounds / 2;
  long long scnt;
  if(x == 1) {
    if(rounds & 1LL) {
      scnt = rounds / 2 + 1;
    } else {
      scnt = (k % each) - ((n - 2) * m) < y ? rounds / 2 : rounds / 2 + 1;
    }
  } else if(x == n) {
    if(rounds & 1LL) {
      scnt = (k % each) - ((n - 2) * m) < y ? rounds / 2 : rounds / 2 + 1;
    } else {
      scnt = rounds / 2; 
    }
  } else {
    long long left = k % each;
    if(rounds & 1LL) {
      scnt = (x - 2) * m + y <= left ? rounds + 1 : rounds; 
    } else {
      scnt = (n - 1 - x) * m + y <= left ? rounds + 1 : rounds;
    }
  }
  printf("%I64d %I64d %I64d\n", maxv + 1, minv + 1, scnt + 1);
  return 0;
}
