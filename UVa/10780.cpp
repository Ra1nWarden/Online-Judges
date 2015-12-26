#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int maxp = 1300;
const int maxn = 10000;
bool check[maxn+1];
int primes[maxp];
int pi;

void init() {
  pi = 0;
  memset(check, false, sizeof check);
  for(int i = 2; i <= maxn; i++) {
    if(!check[i])
      primes[pi++] = i;
    for(int j = 0; j < pi; j++) {
      if(primes[j] * i > maxn)
	break;
      check[primes[j] * i] = true;
      if(i % primes[j] == 0)
	break;
    }
  }
}

int total(int n, int p) {
  int ans = 0;
  while(n >= p) {
    ans += n / p;
    n /= p;
  }
  return ans;
}

int main() {
  init();
  int tc;
  scanf("%d", &tc);
  for(int kase = 1; kase <= tc; kase++) {
    int m, n;
    scanf("%d %d", &m, &n);
    printf("Case %d:\n", kase);
    int ans = n;
    for(int i = 0; i < pi; i++) {
      if(m % primes[i] == 0) {
	int cnt = 0;
	while(m % primes[i] == 0) {
	  m /= primes[i];
	  cnt++;
	}
	int target = total(n, primes[i]);
	ans = min(ans, target / cnt);
      }
    }
    if(ans) {
      printf("%d\n", ans);
    } else {
      printf("Impossible to divide\n");
    }
  }
  return 0;
}
