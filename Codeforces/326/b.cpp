#include <cstdio>
#include <cstring>
#include <vector>

using namespace std;

const int maxn = 1e6;
bool check[maxn+5];
vector<long long> primes;

void init() {
  memset(check, false, sizeof check);
  for(int i = 2; i <= maxn; i++) {
    if(!check[i])
      primes.push_back(i);
    for(int j = 0; j < primes.size(); j++) {
      if(i * primes[j] > maxn)
	break;
      check[i * primes[j]] = true;
      if(i % primes[j] == 0)
	break;
    }
  }
}

int main() {
  init();
  long long n;
  scanf("%I64d", &n);
  long long ans = 1;
  for(int i = 0; i < primes.size(); i++) {
    if(n % primes[i] == 0) {
      ans *= primes[i];
      while(n % primes[i] == 0)
	n /= primes[i];
    }
  }
  ans *= n;
  printf("%I64d\n", ans);
  return 0;
}
