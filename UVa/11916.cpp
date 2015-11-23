#include <cstdio>
#include <set>
#include <cstring>
#include <cmath>

using namespace std;

int n, k, b, r;
typedef pair<int, int> Point;
set<Point> blocked;
const int mod = 100000007;
const int maxb = 510;
int xv[maxb], yv[maxb];
const int maxn = 76543;

int hs[maxn], head[maxn], next[maxn], id[maxn], top;

void insert(int x, int y) {
  int k = x % maxn;
  hs[top] = x, id[top] = y, next[top] = head[k], head[k] = top++;
}

int find(int x) {
  int k = x % maxn;
  for(int i = head[k]; i != -1; i = next[i]) {
    if(hs[i] == x) {
      return id[i];
    }
  }
  return -1;
}

int power_mod(int a, long long p) {
  int ans = 1;
  while(p) {
    if(p & 1) {
      ans = (ans * 1LL * a) % mod;
    }
    a = (a * 1LL * a) % mod;
    p >>= 1;
  }
  return ans;
}

int mod_inverse(int a) {
  return power_mod(a, mod-2);
}

int baby_step_giant_step(int a, int b) {
  memset(head, -1, sizeof head);
  top = 1;
  if(b == 1) {
    return 0;
  }
  int m = sqrt(mod + 0.5), j;
  long long x = 1, p = 1;
  for(int i = 0; i < m; i++, p = (p * a) % mod) {
    insert(p * b % mod, i);
  }
  for(long long i = m; i <= mod; i += m) {
    if((j = find(x = x * p % mod)) != -1) {
      return i - j;
    }
  }
  return -1;
}

int main() {
  int tc;
  scanf("%d", &tc);
  for(int kase = 1; kase <= tc; kase++) {
    scanf("%d%d%d%d", &n, &k, &b, &r);
    int m = 1;
    blocked.clear();
    for(int i = 0; i < b; i++) {
      scanf("%d%d", &xv[i], &yv[i]);
      blocked.insert(make_pair(xv[i], yv[i]));
      m = max(m, xv[i]);
    }

    int c = 0;
    for(int i = 0; i < b; i++) {
      if(xv[i] != m && !blocked.count(make_pair(xv[i] + 1, yv[i])))
	c++;
    }
    c += n;
    for(int i = 0; i < b; i++) {
      if(xv[i] == 1)
	c--;
    }
    int cnt = (power_mod(k, c) * 1LL * power_mod(k-1, m * 1LL * n - b - c)) % mod;
    if(cnt == r) {
      printf("Case %d: %d\n", kase, m);
      continue;
    }
    c = 0;
    for(int i = 0; i < b; i++) {
      if(xv[i] == m)
	c++;
    }
    m++;
    cnt = (cnt * 1LL * power_mod(k, c)) % mod;
    cnt = (cnt * 1LL * power_mod(k-1, n-c)) % mod;
    if(cnt == r) {
      printf("Case %d: %d\n", kase, m);
      continue;
    }
    printf("Case %d: %d\n", kase, baby_step_giant_step(power_mod(k-1, n), r * 1LL * mod_inverse(cnt) % mod) + m);
  }
  return 0;
}
