#include <cstdio>
#include <cstring>

using namespace std;

const int maxn = 100000;
bool check[maxn+5];
const int maxp = 10000;
int primes[maxp+5];
int pi;

void init() {
  pi = 0;
  memset(check, false, sizeof check);
  for(int i = 2; i <= maxn; i++) {
    if(!check[i]) {
      primes[pi++] = i;
    }
    for(int j = 0; j < pi; j++) {
      if(primes[j] * 1LL * i > maxn)
	break;
      check[primes[j] * i] = true;
      if(i % primes[j])
	break;
    }
  }
  printf("pi=%d\n", pi);
}

int main() {
  init();
  return 0;
}
