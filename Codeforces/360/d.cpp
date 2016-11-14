#include <cstdio>
#include <cstring>
#include <vector>
#include <set>

using namespace std;

const int maxp = 1000;
const int maxk = 1000000;
int pv[maxp+5];
int pi, n, k;
bool primes[maxp+5];

void init() {
  pi = 0;
  memset(primes, false, sizeof primes);
  for(int i = 2; i <= maxp; i++) {
    if(!primes[i])
      pv[pi++] = i;
    for(int j = 0; j < pi; j++) {
      if(i * pv[j] > i)
	break;
      primes[i * pv[j]] = true;
      if(i % pv[j] == 0)
	break;
    }
  }
}

int power(int a, int b) {
  if(b == 0)
    return 1;
  else if(b & 1) {
    int c = power(a, b / 2);
    return c * c * a;
  } else {
    int c = power(a, b / 2);
    return c * c;
  }
}

vector<int> div(int num) {
  vector<int> ans;
  for(int i = 0; i < pi; i++) {
    int cnt = 0;
    while(num % pv[i] == 0) {
      num /= pv[i];
      cnt++;
    }
    if(cnt > 0) {
      ans.push_back(power(pv[i], cnt));
    }
  }
  if(num > 1)
    ans.push_back(num);
  return ans;
}

int main() {
  init();
  scanf("%d%d", &n, &k);
  vector<int> factors = div(k);
  set<int> m;
  int x;
  while(n--) {
    scanf("%d", &x);
    for(int i = 0; i < factors.size(); i++) {
      if(m.count(factors[i]))
	continue;
      if(x % factors[i] == 0)
	m.insert(factors[i]);
    }
  }
  printf("%s\n", m.size() == factors.size() ? "Yes" : "No");
  return 0;
}
