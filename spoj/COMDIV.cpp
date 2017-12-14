#include <cstdio>
#include <vector>
#include <cstring>

using namespace std;

vector<int> primes;
const int maxn = 1000;

void init() {
  bool check[maxn+1];
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

int gcd(int a, int b) {
  if(b == 0)
    return a;
  return gcd(b, a % b);
}

int main() {
  init();
  int tc;
  scanf("%d", &tc);
  int a, b;
  while(tc--) {
    scanf("%d %d", &a, &b);
    int c = gcd(a, b);
    int ans = 1;
    for(int i = 0; i < primes.size(); i++) {
      if(primes[i] * primes[i] > c)
	break;
      if(c % primes[i] == 0) {
	int count = 1;
	while(c % primes[i] == 0) {
	  c /= primes[i];
	  count++;
	}
	ans *= count;
      }
    }
    if(c > 1)
      ans *= 2;
    printf("%d\n", ans);
  }
  return 0;
}
