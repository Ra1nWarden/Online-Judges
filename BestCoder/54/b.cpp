#include <cstdio>
#include <vector>
#include <queue>
#include <cstring>
#define MAXN 100000

using namespace std;

bool check[MAXN+1];
vector<int> primes;

int main() {
  memset(check, false, sizeof check);
  for(int i = 2; i <= MAXN; i++) {
    if(!check[i])
      primes.push_back(i);
    for(int j = 0; j < primes.size(); j++) {
      if(i * 1LL * primes[j] > MAXN)
	break;
      check[i * primes[j]] = true;
      if(i % primes[j] == 0)
	break;
    }
  }
  int tc;
  scanf("%d", &tc);
  while(tc--) {
    int n;
    scanf("%d", &n);
    priority_queue<int> pq;
    for(int i = 0; i < n; i++) {
      int num;
      scanf("%d", &num);
      if(num == 1)
	continue;
      vector<int> facts;
      for(int j = 0; j < n && facts.size() < 2; j++) {
	if(num % primes[j] == 0) {
	  while(num % primes[j] == 0 && facts.size() < 2) {
	    facts.push_back(primes[j]);
	    num /= primes[j];
	  }
	}
      }
      if(facts.size() < 2 && num != 1)
	facts.push_back(num);
      for(int j = 0; j < facts.size(); j++) {
	pq.push(facts[j]);
      }
      while(pq.size() > 2)
	pq.pop();
    }
    long long ans = -1;
    if(pq.size() >= 2) {
      int a = pq.top();
      pq.pop();
      int b = pq.top();
      pq.pop();
      ans = a * 1LL * b;
    }
    printf("%lld\n", ans);
  }
  return 0;
}
