#include <cstdio>
#include <vector>
#include <cstring>
#define MAXN 1000

using namespace std;

bool check[MAXN+1];
vector<int> primes;

int main() {
  memset(check, false, sizeof check);
  for(int i = 2; i <= MAXN; i++) {
    if(!check[i]) {
      primes.push_back(i);
    }
    for(int j = 0; j < primes.size(); j++) {
      if(i * primes[j] > MAXN)
	break;
      check[i * primes[j]] = true;
      if(i % primes[j] == 0)
	break;
    }
  }
  int tc;
  scanf("%d", &tc);
  while(tc--) {
    int num;
    scanf("%d", &num);
    num++;
    int ans = num;
    for(int i = 0; i < primes.size(); i++) {
      if(num % primes[i] == 0) {
	ans = ans / primes[i] * (primes[i] - 1);
	while(num % primes[i] == 0) {
	  num /= primes[i];
	}
      }
    }
    if(num != 1)
      ans = ans / num * (num - 1);
    printf("%d\n", ans);
  }
  return 0;
}
