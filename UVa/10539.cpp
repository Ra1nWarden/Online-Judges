#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#define MAXN 1000000

using namespace std;

bool check[MAXN+5];
vector<long long> primes;
vector<long long> required;

void init() {
  memset(check, false, sizeof check);
  for(int i = 2; i <= MAXN; i++) {
    if(!check[i])
      primes.push_back(i);
    for(int j = 0; j < primes.size(); j++) {
      if(primes[j] * i > MAXN)
	break;
      check[primes[j] * i] = true;
      if(i % primes[j] == 0)
	break;
    }
  }
  for(int i = 0; i < primes.size(); i++) {
    int prime = primes[i];
    long long prod = prime;
    while(prod < 1000000000000LL) {
      prod *= prime;
      required.push_back(prod);
    }
  }
  sort(required.begin(), required.end());
}

int main() {
  init();
  int tc;
  scanf("%d", &tc);
  while(tc--) {
    long long l, u;
    scanf("%lld %lld", &l, &u);
    int li = lower_bound(required.begin(), required.end(), l) - required.begin();
    int ui = lower_bound(required.begin(), required.end(), u) - required.begin();
    if(required[ui] > u)
      ui--;
    printf("%d\n", ui - li + 1);
  }
  return 0;
}
