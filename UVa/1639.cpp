#include <cstdio>
#include <cmath>
#define MAXN 200005

using namespace std;

int n;
double p;
long double memo[2*MAXN];

long double choose(int m, int n) {
  return memo[m] - memo[m-n] - memo[n];
}

long double v1(int i) {
  return choose(2*n-i, n-i) + (n+1) * log(p) + (n-i) * log(1-p);
}

long double v2(int i) {
  return choose(2*n-i, n-i) + (n+1) * log(1-p) + (n-i) * log(p);
} 

double solve() {
  double ans = 0.0;
  for(int i = 1; i <= n; i++) {
    ans += i * (exp(v1(i)) + exp(v2(i)));
  }
  return ans;
}

int main() {
  memo[0] = 0;
  for(int i = 1; i <= 400000; i++)
    memo[i] = memo[i-1] + log(i);
  int kase = 1;
  while(scanf("%d %lf", &n, &p) != EOF) {
    printf("Case %d: %.6lf\n", kase++, solve());
  }
  return 0;
}
