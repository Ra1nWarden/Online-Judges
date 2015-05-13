#include <cstdio>
#include <map>
#define MAXN 100005

using namespace std;

int n;

long long gcd(long long a, long long b) {
  return b == 0 ? a : gcd(b, a%b);
}

int main() {
  int tc;
  scanf("%d", &tc);
  while(tc--) {
    scanf("%d", &n);
    map<long long, int> m;
    long long ans = 0;
    for(int i = 0; i < n; i++) {
      long long x;
      scanf("%lld", &x);
      map<long long, int> nm;
      for(map<long long, int>::iterator itr = m.begin(); itr != m.end(); itr++) {
	long long newd = gcd(itr->first, x);
	if(nm.count(newd)) {
	  if(nm[newd] > itr->second) {
	    // printf("1 i=%d updating gcd from %lld to %lld\n", i, itr->first, newd);
	    nm[newd] = itr->second;
	    ans = max(ans, (i - itr->second + 1) * 1LL * newd);
	  }
	} else {
	  // printf("2 i=%d updating gcd from %lld to %lld\n", i, itr->first, newd);
	  nm[newd] = itr->second;
	  ans = max(ans, (i - itr->second + 1) * 1LL * newd);
	}
      }
      // printf("3 i=%d adding gcd %lld\n", i, x);
      if(nm.count(x) == 0) {
	nm[x] = i;
	ans = max(ans, x);
      }
      m = nm;
    }
    printf("%lld\n", ans);
  }
  return 0;
}
