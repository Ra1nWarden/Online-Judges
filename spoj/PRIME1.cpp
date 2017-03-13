#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;

const int maxn = 40000;
bool check[maxn+5];

vector<int> sieve() {
  memset(check, false, sizeof check);
  vector<int> result;
  for(int i = 2; i <= maxn; i++) {
    if(!check[i])
      result.push_back(i);
    for(int j = 0; j < result.size(); j++) {
      if(i * result[j] > maxn)
	break;
      check[i * result[j]] = true;
      if(i % result[j] == 0)
	break;
    }
  }
  return result;
}

int main() {
  vector<int> primes = sieve();
  int tc;
  scanf("%d", &tc);
  while(tc--) {
    int l, r;
    scanf("%d %d", &l, &r);
    for(int i = max(2, l); i <= r; i++) {
      bool prime = true;
      for(int j = 0; j < primes.size(); j++) {
	if(primes[j] * primes[j] > i)
	  break;
	if(i % primes[j] == 0) {
	  prime = false;
	  break;
	}
      }
      if(prime) {
	printf("%d\n", i);
      }
    }
    if(tc)
      printf("\n");
  }
  return 0;
}
