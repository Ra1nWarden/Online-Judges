#include <cstdio>
#include <cstring>
#include <set>
#include <cmath>

using namespace std;

const int maxn = 64;
bool check[maxn+1];
int primes[maxn+1];
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

unsigned long long cap = ((1LL << 63) - 1) | (1LL << 63);

unsigned long long power_calc(int base, int p) {
  if(p == 0)
    return 1;
  unsigned long long sub = power_calc(base, p / 2);
  if(sub == 0)
    return 0;
  if(p % 2)
    return cap / sub >= sub * base ? sub * sub * base : 0;
  else
    return cap / sub >= sub ? sub * sub : 0;
}

int main() {
  init();
  set<unsigned long long> ans;
  ans.insert(1);
  for(int i = 4; i <= maxn; i++) {
    if(check[i]) {
      for(int b = 2; b > 0; b++) {
	unsigned long long sub = power_calc(b, i);
	if(sub)
	  ans.insert(sub);
	else
	  break;
      }
    }
  }
  for(set<unsigned long long>::iterator itr = ans.begin(); itr != ans.end(); itr++) {
    printf("%llu\n", *itr);
  }
  return 0;
}
