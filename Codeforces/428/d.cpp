#include <cstdio>
#include <vector>
#include <cstring>
#include <algorithm>
#include <map>

using namespace std;

const int mod = 1000000007;
const int maxn = 200000;
const int maxa = 1000000;
int n;
vector<int> primes;
int v[maxn+5];
int power[maxn+5];

int lowbit(int x) {
  return x & (-x);
}

struct BIT {
  int c[25];
  void init() {
    memset(c, 0, sizeof c);
  }
  int sum(int x) {
    int ret = 0;
    while(x > 0) {
      ret += c[x];
      x -= lowbit(x);
    }
    return ret;
  }
  void add(int x, int d) {
    while(x <= 20) {
      c[x] += d;
      x += lowbit(x);
    }
  }
};

BIT bit;

int total(int p) {
  return (1 << p) - 1;
}

void init() {
  bool check[maxa+1];
  memset(check, false, sizeof check);
  for(int i = 2; i <= maxa; i++) {
    if(!check[i])
      primes.push_back(i);
    for(int j = 0; j < primes.size(); j++) {
      if(i * primes[j] > maxa)
	break;
      check[i * primes[j]] = true;
      if(i % primes[j] == 0)
	break;
    }
  }
}

int calc(int p) {
  printf("calc(%d)\n", p);
  int cnt[20];
  memset(cnt, 0, sizeof cnt);
  int max_power = 0;
  memset(power, 0, sizeof power);
  for(int i = 0; i < n; i++) {
    int num = v[i];
    while(num % p == 0) {
      power[i]++;
      num /= p;
    }
    cnt[power[i]]++;
    max_power = max(max_power, power[i]);
  }
  printf("max_power=%d ", max_power);
  bit.init();
  for(int i = 1; i <= max_power; i++) {
    bit.add(i, cnt[i]);
  }
  int ans = 0;
  int cur = p;
  int base[20];
  for(int i = 1; cur <= maxa; i++) {
    base[i] = cur;
    cur = (cur * 1LL * p) % mod;
  }
  for(int i = 0; i < n; i++) {
    if(power[i] == 0)
      continue;
    printf("total(%d - %d)=%d ", bit.sum(max_power), bit.sum(power[i] - 1), total(bit.sum(max_power) - bit.sum(power[i] - 1)));
    ans = (ans + (base[power[i]] * 1LL * total(bit.sum(max_power) - bit.sum(power[i] - 1))) % mod) % mod;
    printf("i=%d ans=%d ", i, ans);
    for(int j = power[i] - 1; j >= 1; j--) {
      ans = (ans + (base[j] * 1LL * total(cnt[j])) % mod) % mod;
      printf("cnt[%d]=%d ans=%d ", j, cnt[j], ans);
    }
    printf("ans=%d\n", ans);
    cnt[power[i]]--;
    bit.add(power[i], -1);
  }
  return ans;
}

int main() {
  init();
  scanf("%d", &n);
  for(int i = 0; i < n; i++)
    scanf("%d", &v[i]);
  int ans = 0;
  for(int i = 0; i < primes.size(); i++) {
    if(primes[i] > 1000)
      break;
    ans = (ans + calc(primes[i])) % mod;
  }
  map<int, int> cm;
  for(int i = 0; i < n; i++) {
    if(v[i] <= 1000)
      continue;
    vector<int>::iterator itr = lower_bound(primes.begin(), primes.end(), v[i]);
    if(itr != primes.end()) {
      if(cm.count(v[i])) {
	cm[v[i]]++;
      } else {
	cm[v[i]] = 1;
      }
    }
  }
  for(map<int, int>::iterator itr = cm.begin(); itr != cm.end(); itr++) {
    ans = (ans + (itr->first * 1LL * total(itr->second)) % mod) % mod;
  }
  printf("%d\n", ans);
  return 0;
}
