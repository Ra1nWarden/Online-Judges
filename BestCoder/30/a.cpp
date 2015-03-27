#include <cstdio>
#include <algorithm>
#include <map>
#define MAXN 101
#define MAXINT 2147483647

using namespace std;

long long v[MAXN];
int n;
map<long long, int> cnt;

int main() {
  int tc = 1;
  while(scanf("%d", &n) != EOF) {
    cnt.clear();
    for(int i = 0; i < n; i++) {
      scanf("%lld", &v[i]);
      // scanf("%I64d", &v[i]);
      cnt[v[i]]++;
    }
    sort(v, v+n);
    long long* end = unique(v, v+n);
    if(end == v + 1) {
      printf("Case #%d: -1\n", tc++);
      continue;
    }
    int res = 0;
    for(int i =0; v+i < end; i++) {
      if((v[i] + v[(i-1)%n]) % MAXINT == v[(i+1)%n])
	res += cnt[v[i]];
    }
    printf("Case #%d: %d\n", tc++, res);
  }
  return 0;
}
