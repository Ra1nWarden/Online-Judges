#include <cstdio>
#include <vector>
#include <cstring>
#include <set>
#include <algorithm>
#define MAXN 1000001

using namespace std;

bool check[MAXN+5];
vector<int> primes;
set<int> half_primes;

int main() {
  memset(check, false, sizeof check);
  for(int i = 5; i <= MAXN; i += 4) {
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
  for(int i = 0; i < primes.size(); i++) {
    for(int j = i; j < primes.size(); j++) {
      if(primes[i] * 1LL * primes[j] > MAXN)
	break;
      half_primes.insert(primes[i] * primes[j]);
    }
  }
  vector<int> nums(half_primes.begin(), half_primes.end());
  int x;
  while(scanf("%d", &x) != EOF && x) {
    int i = lower_bound(nums.begin(), nums.end(), x) - nums.begin();
    if(i < nums.size() && nums[i] > x)
      i--;
    printf("%d %d\n", x, i+1);
  }
  return 0;
}
