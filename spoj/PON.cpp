#include <cstdlib>
#include <cstdio>
#include <cmath>
#include <ctime>

using namespace std;

long long MultModular(long long a, long long b, long long c) {
  a %= c;
  b %= c;
  long long ret = 0;
  long long tmp = a;
  while(b) {
    if(b & 1) {
      ret += tmp;
      if(ret > c) {
	ret -= c;
      }
    }
    tmp <<= 1;
    if(tmp > c) {
      tmp -= c;
    }
    b >>= 1;
  }
  return ret;
}

long long PowerModular(long long a, long long n, long long m) {
  long long ret = 1LL;
  long long temp = a % m;
  while(n) {
    if(n & 1) {
      ret = MultModular(ret, temp, m);
    }
    temp = MultModular(temp, temp, m);
    n >>= 1;
  }
  return ret;
}

bool MillerRabinHelper(long long a, long long n, long long x, long long t) {
  long long ret = PowerModular(a, x, n);
  long long last = ret;
  for(long long i = 1; i <= t; i++) {
    ret = PowerModular(ret, 2LL, n);
    if(ret == 1LL && last != 1LL && last != n - 1) {
      return true;
    }
    last = ret;
  }
  return ret != 1LL;
}

bool check(long long n) {
  if(n < 2)
    return false;
  if(n == 2)
    return true;
  if(!(n & 1))
    return false;
  long long x = n - 1;
  long long t = 0;
  while(!(x & 1)) {
    x >>= 1;
    t++;
  }
  srand(time(NULL));
  for(int i = 0; i < 10; i++) {
    long long a = rand() % (n - 1) + 1;
    if(MillerRabinHelper(a, n, x, t)) {
      return false;
    }
  }
  return true;
}

int main() {
  int t;
  scanf("%d", &t);
  long long num;
  while(t--) {
    scanf("%lld", &num);
    printf("%s\n", check(num) ? "YES" : "NO");
  }
  return 0;
}
