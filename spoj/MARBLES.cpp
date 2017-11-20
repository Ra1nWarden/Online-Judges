#include <cstdio>

using namespace std;

long long combi(long long a, long long b) {
  if(b > a) {
    return 0;
  }
  if(b > a / 2) {
    return combi(a, a - b);
  }
  long long result = 1;
  for(long long i = 1; i <= b; i++) {
    result *= a--;
    result /= i;
  }
  return result;
}

int main() {
  int tc;
  scanf("%d", &tc);
  while(tc--) {
    long long n, k;
    scanf("%lld %lld", &n, &k);
    long long a = n - 1;
    long long b = k - 1;
    printf("%lld\n", combi(a, b));
  }
  return 0;
}
