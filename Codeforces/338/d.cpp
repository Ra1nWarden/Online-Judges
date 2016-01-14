#include <cstdio>
#include <map>
#include <stack>

using namespace std;

const long long mod = 1e9 + 7;

long long power(long long b, long long p, long long m) {
  long long ans = 1;
  long long cur_p = 1;
  stack<long long> cur;
  cur.push(b);
  while(p) {
    if(cur_p > p) {
      cur_p >>= 1;
      cur.pop();
    } else if(cur_p * 2 > p) {
      ans = (ans * cur.top()) % m;
      p -= cur_p;
    } else {
      cur_p <<= 1;
      cur.push((cur.top() * cur.top()) % m);
    }
  }
  return ans;
}

// long long power2(long long b, long long p) {
//   if(p == 0)
//     return 1;
//   long long sub = power2(b, p >> 1);
//   if(p & 1)
//     return (sub * sub * b) % mod;
//   else
//     return (sub * sub) % mod;
// }

// long long power3(long long b, long long p, long long m) {
//   b %= m;
//   if(p == 0)
//     return 1;
//   return ((p % 2 == 1) ? b : 1) * power3(b * b, p / 2, m) % m;
// }

int main() {
  int m;
  scanf("%d", &m);
  map<int, int> cnt;
  while(m--) {
    int p;
    scanf("%d", &p);
    cnt[p]++;
  }
  long long d = 1, ans = 1;
  for(map<int, int>::iterator itr = cnt.begin(); itr != cnt.end(); itr++) {
    long long fp = power((itr->first), ((itr->second) + 1) * 1LL * (itr->second) / 2, mod);
    ans = (power(ans, ((itr->second) + 1), mod) * power(fp, d, mod)) % mod;
    d = d * ((itr->second) + 1) % (mod - 1);
  }
  printf("%d\n", (int) ans);
  return 0;
}
