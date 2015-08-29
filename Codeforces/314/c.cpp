#include <cstdio>
#include <map>
#define MAXN 200005

using namespace std;

map<long long, int> rm;
map<long long, int> lm;
long long v[MAXN];

int main() {
  long long n, k;
  scanf("%lld %lld", &n, &k);
  long long ans = 0;
  for(int i = 0; i < n; i++) {
    long long num;
    scanf("%lld", &num);
    v[i] = num;
    rm[num]++;
  }
  for(int i = 0; i < n; i++) {
    rm[v[i]]--;
    if(v[i] % k == 0) {
      if(lm.count(v[i] / k) && lm[v[i] / k] > 0) {
	if(rm.count(v[i] * k) && rm[v[i] * k] > 0) {
	  ans += lm[v[i] / k] * 1LL * rm[v[i] * k];
	}
      }
    }
    lm[v[i]]++;
  }
  printf("%lld\n", ans);
  return 0;
}
