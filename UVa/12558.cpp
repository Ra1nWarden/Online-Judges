#include <cstdio>
#include <vector>
#include <set>
#define MAXK 6

using namespace std;

typedef long long LL;

set<LL> kv;
LL a, b, k, maxd;
vector<LL> ans;

bool better(const vector<LL>& v) {
  if(ans.empty()) {
    return true;
  }
  for(int i = v.size() - 1; i > -1; i--) {
    if(v[i] < ans[i])
      return true;
    else if(v[i] > ans[i])
      return false;
  }
  return false;
}

LL gcd(LL m, LL n) {
  return n == 0 ? m : gcd(n, m%n);
}

LL lcm(LL m, LL n) {
  return m * n / gcd(m, n);
}

pair<LL, LL> subtract(LL p, LL q, LL pp, LL qq) {
  LL qqq = lcm(q, qq);
  LL ppp = p * (qqq / q) - pp * (qqq / qq);
  LL d = gcd(ppp, qqq);
  return make_pair(ppp / d, qqq / d);
}

LL cmp_frac(LL p, LL q, LL pp, LL qq) {
  return (p * qq - pp * q);
}

bool dfs(LL p, LL q, vector<LL>& v) {
  if(v.size() == maxd) {
    if(p == 0) {
      if(better(v)) {
	ans = v;
      }
      return true;
    }
    else
      return false;
  }
  bool flag = false;
  for(LL next = v.empty() ? q / p : max(q / p, v.back() + 1); next > 0; next++) {
    if(kv.count(next)) {
      continue;
    }
    if(cmp_frac(p, q, 1, next) < 0) {
      continue;
    }
    if(cmp_frac(p, q, maxd - v.size(), next) > 0) {
      break;
    }
    pair<LL, LL> new_frac = subtract(p, q, 1, next);
    v.push_back(next);
    if(dfs(new_frac.first, new_frac.second, v)) {
      flag = true;
    }
    v.pop_back();
  }
  return flag;
}

void print_ans() {
  for(int i = 0; i < ans.size(); i++) {
    if(i > 0)
      printf("+");
    printf("1/%lld", ans[i]);
  }
}

int main() {
  int tc;
  scanf("%d", &tc);
  for(int kase = 1; kase <= tc; kase++) {
    scanf("%lld%lld%lld", &a, &b, &k);
    kv.clear();
    for(int i = 0; i < k; i++) {
      int num;
      scanf("%lld", &num);
      kv.insert(num);
    }
    ans.clear();
    for(maxd = 1; maxd > 0; maxd++) {
      vector<LL> sub_ans;
      if(dfs(a, b, sub_ans))
	break;
    }
    printf("Case %d: %d/%d=", kase, a, b);
    print_ans();
    printf("\n");
  }
  return 0;
}
