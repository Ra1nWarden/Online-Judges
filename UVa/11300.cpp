#include <cstdio>
#include <algorithm>
#include <cstdlib>
#define MAXN 1000001

using namespace std;

typedef long long ll;

ll v[MAXN];
ll c[MAXN];

int main() {
  ll n;
  while(scanf("%lld", &n) != EOF && n) {
    //getchar();
    c[0] = 0;
    ll sum = 0;
    for(int i = 1; i <= n; i++) {
      scanf("%lld", &v[i]);
      //getchar();
      sum += v[i];
    }
    ll avg = sum / n;
    
    for(int i = 1; i < n; i++) {
      c[i] = c[i-1] + v[i] - avg;
    }
    sort(c, c+n);
    
    
    ll x1 = c[n/2];
    ll ans = 0;
    for(int i = 0; i < n; i++) {
      ans += abs(c[i] - x1);
    }
    printf("%lld\n", ans);
  }
  return 0;
}
