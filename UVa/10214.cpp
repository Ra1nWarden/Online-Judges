#include <cstring>
#include <cstdio>
#define MAXN 2005

using namespace std;

bool check[MAXN];
int pn[MAXN];
int pi;

int gcd(int a, int b) {
  return b == 0 ? a : gcd(b, a%b);
}

long long phi(int n) {
  long long ans = n;
  for(int i = 0; i < pi; i++) {
    if(n % pn[i] == 0)
      ans = ans / pn[i] * (pn[i] - 1);
  }
  return ans;
}

int init() {
  pi = 0;
  memset(check, true, sizeof check);
  for(int i = 2; i <= 2000; i++) {
    if(check[i]) {
      pn[pi++] = i;
    }
    for(int j = 0; j < pi; j++) {
      if(pn[j] * i > 2000)
	break;
      check[pn[j] * i] = false;
      if(i % pn[j] == 0)
	break;
    }
  }
}

int main() {
  init();
  int a, b;
  while(scanf("%d %d", &a, &b) != EOF && (a || b)) {
    long long total = 1;
    for(int i = 1; i <= a; i++) {
      int k = b / i;
      total += phi(i) * k;
      for(int j = 1; j <= b % i; j++) {
	if(gcd(i, j) == 1)
	  total++;
      }
    }
    total *= 4;
    printf("%.7lf\n", (double) total / ((2 * a + 1) * 1LL * (2 * b + 1) - 1));
  }
  return 0;
}
