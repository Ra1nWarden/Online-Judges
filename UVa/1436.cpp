#include <cstdio>
#include <map>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;

map<int, vector<int> > adjList;
map<int, int> factors;
int n, m;
const int maxn = 500000;
int total[maxn+1];
const int maxv = 800;
bool check[maxv+1];
vector<int> primes;

int cnt(int root) {
  if(total[root] != -1)
    return total[root];
  int ans = 1;
  for(int i = 0; i < adjList[root].size(); i++) {
    ans += cnt(adjList[root][i]);
  }
  return total[root] = ans;
}

void init() {
  memset(check, true, sizeof check);
  for(int i = 2; i <= maxv; i++) {
    if(check[i])
      primes.push_back(i);
    for(int j = 0; j < primes.size(); j++) {
      if(i * primes[j] > maxv)
	break;
      check[i * primes[j]] = false;
      if(i % primes[j] == 0)
	break;
    }
  }
}

void update(int num, bool inc) {
  for(int i = 0; i < primes.size(); i++) {
    int delta = 0;
    while(num % primes[i] == 0) {
      delta++;
      num /= primes[i];
    }
    if(delta) {
      if(inc) {
	factors[primes[i]] += delta;
      } else {
	factors[primes[i]] -= delta;
      }
    }
  }
  if(num > 1) {
    if(inc) {
      factors[num]++;
    } else {
      factors[num]--;
    }
  }
}

int power(int b, int p) {
  if(p == 0)
    return 1;
  int sub = power(b, p / 2);
  sub = (sub * 1LL * sub) % m;
  if(p & 1) {
    return (sub * 1LL * b) % m;
  } else {
    return sub;
  }
}

int main() {
  init();
  int tc;
  scanf("%d", &tc);
  while(tc--) {
    factors.clear();
    adjList.clear();
    scanf("%d %d", &n, &m);
    for(int i = 2; i <= n; i++) {
      int p;
      scanf("%d", &p);
      adjList[p].push_back(i);
    }
    memset(total, -1, sizeof total);
    int all = cnt(1);
    for(int i = 2; i < n; i++) {
      update(i, true);
    }
    for(int i = 2; i <= n; i++)
      update(total[i], false);
    int ans = 1;
    for(map<int, int>::iterator itr = factors.begin(); itr != factors.end(); itr++) {
      ans = (ans * 1LL * power(itr->first, itr->second)) % m;
    }
    printf("%d\n", ans);
  }
  return 0;
}
