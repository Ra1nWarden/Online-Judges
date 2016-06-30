#include <cstdio>
#include <algorithm>
#define MAXN 100005

using namespace std;
typedef pair<long long, long long> Tuple;

Tuple v[MAXN];
long long n, d;

int main() {
  scanf("%I64d%I64d", &n, &d);
  for(long long i = 0; i < n; i++) {
    scanf("%I64d%I64d", &v[i].first, &v[i].second);
  }
  sort(v, v+n);
  long long ans = -1;
  long long min_i = 0;
  long long cur = v[0].second;
  for(long long i = 1; i < n; i++) {
    if(v[i].first - v[min_i].first >= d) {
      ans = max(ans, cur);
      while(min_i < i && v[i].first - v[min_i].first >= d) {
	cur -= v[min_i++].second;
      }
    }
    cur += v[i].second;
  }
  ans = max(ans, cur);
  printf("%I64d\n", ans);
  return 0;
}
