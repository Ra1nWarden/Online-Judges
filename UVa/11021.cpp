#include <cstdio>
#include <cmath>
#include <map>

using namespace std;

const int maxn = 1000;
double p[maxn+1];
int n, k, m;
map<int, double> memo;

double f(int d) {
  if(memo.count(d))
    return memo[d];
  if(d == 0)
    return 0;
  double ans = p[0];
  for(int i = 1; i < n; i++) {
    ans += p[i] * pow(f(d-1), i);
  }
  return memo[d] = ans;
}

int main() {
  int tc;
  scanf("%d", &tc);
  for(int kase = 1; kase <= tc; kase++) {
    memo.clear();
    scanf("%d%d%d", &n, &k, &m);
    for(int i = 0; i < n; i++) {
      scanf("%lf", &p[i]);
    }
    printf("Case #%d: %.7lf\n", kase, pow(f(m), k));
  }
  return 0;
}
