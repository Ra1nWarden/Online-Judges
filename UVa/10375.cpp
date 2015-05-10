#include <cstdio>
#include <cstring>
#include <cmath>
#define MAXN 10005

using namespace std;

int check[MAXN];
int primes[MAXN];
int pi;
int p, q, r, s;
int factors[MAXN];

void integerfact(int n, int d) {
  for(int i = 0; i < pi; i++) {
    if(n == 1)
      return;
    if(n % primes[i] == 0) {
      while(n % primes[i] == 0) {
	n /= primes[i];
	factors[i] += d;
      }
    }
  }
}

void factorial(int n, int d) {
  for(int i = 2; i <= n; i++)
    integerfact(i, d);
}

int main() {
  pi = 0;
  memset(check, false, sizeof check);
  for(int i = 2; i <= 10000; i ++) {
    if(!check[i]) {
      primes[pi++] = i;
    }
    for(int j = 0; j < pi; j++) {
      if(primes[j] * i > 10000)
	break;
      check[primes[j] * i] = true;
      if(i % primes[j] == 0)
	break;
    }
  }
  while(scanf("%d %d %d %d", &p, &q, &r, &s) != EOF) {
    memset(factors, 0, sizeof factors);
    factorial(p, 1);
    factorial(q, -1);
    factorial(p-q, -1);
    factorial(r, -1);
    factorial(s, 1);
    factorial(r-s, 1);
    double ans = 1;
    for(int i = 0; i < pi; i++) {
      if(factors[i] != 0)
	ans *= pow(primes[i], factors[i]);
    }
    printf("%.5lf\n", ans);
  }
  return 0;
}
