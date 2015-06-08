#include <cstring>
#include <cstdio>
#include <vector>
#include <cmath>
#define MAXN 66000

using namespace std;

bool check[MAXN];
int primes[6600];
int pi;

void init() {
  memset(check, false, sizeof check);
  pi = 0;
  for(int i = 2; i <= MAXN; i++) {
    if(!check[i])
      primes[pi++] = i;
    for(int j = 0; j < pi; j++) {
      if(primes[j] * i > MAXN)
	break;
      check[primes[j] * i] = true;
      if(i % primes[j] == 0)
	break;
    }
  }
}

int gcd(int a, int b) {
  return b == 0 ? a : gcd(b, a%b);
}

int gcd(vector<int> facts) {
  if(facts.size() == 2) {
    return gcd(facts[0], facts[1]);
  } else {
    facts.pop_back();
    return gcd(facts.back(), gcd(facts));
  }
}

int solve(int num) {
  vector<int> ans;
  for(int i = 0; i < pi; i++) {
    int prime = primes[i];
    if(num % prime == 0) {
      int cnt = 0;
      while(num % prime == 0) {
	num /= prime;
	cnt++;
      }
      ans.push_back(cnt);
    }
  }
  if(abs(num) != 1)
    ans.push_back(1);
  int ret;
  if(ans.size() == 1)
    ret = ans[0];
  else
    ret = gcd(ans);
  if(num == -1 && ret % 2 == 0) {
    while(ret % 2 == 0)
      ret /= 2;
  }
  return ret;
}

int main() {
  init();
  int num;
  while(scanf("%d", &num) != EOF && num) {
    printf("%d\n", solve(num));
  }
  return 0;
}
