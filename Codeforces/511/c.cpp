#include <cstdio>
#include <vector>
#include <map>
#include <algorithm>
#include <cstring>

using namespace std;

const int maxa = 15000000;
const int maxn = 300000;
int v[maxn+5];
int n;
bool slots[maxa+5];

vector<int> generate() {
  memset(slots, true, sizeof slots);
  vector<int> ans;
  for(int i = 2; i < maxa; i++) {
    if(slots[i]) {
      ans.push_back(i);
      for(int j = i + i; j < maxa; j += i) {
	slots[j] = false;
      }
    }
  }
  return ans;
}

int gcd(int a, int b) {
  return b == 0 ? a : gcd(b, a % b);
}

void insert(map<int, int>& cnt, int x, int& update) {
  if(cnt.count(x))
    cnt[x]++;
  else
    cnt[x]=1;
  update = max(update, cnt[x]);
}

int main() {
  vector<int> primes = generate();
  scanf("%d", &n);
  int cur;
  for(int i = 0; i < n; i++) {
    scanf("%d", &v[i]);
    if(i == 1) {
      cur = gcd(v[0], v[1]);
    } else if(i > 1) {
      cur = gcd(cur, v[i]);
    }
  }
  map<int, int> cnt;
  int update = 0;
  for(int i = 0; i < n; i++) {
    int reduced = v[i] / cur;
    for(int j = 0; primes[j] * 1LL * primes[j] <= reduced; j++) {
      if(reduced % primes[j] != 0)
	continue;
      while(reduced % primes[j] == 0) {
	reduced /= primes[j];
      }
      insert(cnt, primes[j], update);
    }
    if(reduced > 1)
      insert(cnt, reduced, update);
  }
  int ans = n - update;
  if(ans == n)
    printf("-1\n");
  else
    printf("%d\n", ans);
  return 0;
}
