#include <cstdio>
#include <vector>
#include <cstring>

using namespace std;

const int maxn = 10000;
const int maxp = 1300;
bool check[maxn+5];
int primes[maxp];
int pi;

void init() {
  pi = 0;
  memset(check, false, sizeof check);
  for(int i = 2; i <= maxn; i++) {
    if(!check[i]) {
      primes[pi++] = i;
    }
    for(int j = 0; j < pi; j++) {
      if(primes[j] * i >= maxn)
	break;
      check[primes[j] * i] = true;
      if(i % primes[j] == 0)
	break;
    }
  }
}

int main() {
  init();
  int tc;
  scanf("%d", &tc);
  while(tc--) {
    int a, c;
    scanf("%d %d", &a, &c);
    if(c % a) {
      printf("NO SOLUTION\n");
    } else {
      int fact = c / a;
      int ans = 1;
      for(int i = 0; i < pi; i++) {
	if(fact % primes[i] == 0) {
	  while(c % primes[i] == 0) {
	    ans *= primes[i];
	    c /= primes[i];
	    if(fact % primes[i] == 0)
	      fact /= primes[i];
	  }
	}
      }
      ans *= fact;
      printf("%d\n", ans);
    }
  }    
  return 0;
}
