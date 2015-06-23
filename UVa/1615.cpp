#include <cstdio>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

long long l, d;
typedef pair<double, double> Interval;

Interval find_interval(long long x, long long y) {
  double len = sqrt(d * d - y * y);
  return make_pair(max(x - len, (double) 0), min((double) l, x + len));
}

int main() {
  while(scanf("%lld %lld", &l, &d) != EOF) {
    long long n;
    scanf("%lld", &n);
    vector<Interval> intervals;
    for(long long i = 0; i < n; i++) {
      long long x, y;
      scanf("%lld %lld", &x, &y);
      intervals.push_back(find_interval(x, y));
    }
    long long ans = 0;
    double right_most = -1;
    for(long long i = 0; i < intervals.size(); i++) {
      if(intervals[i].first > right_most) {
	ans++;
	right_most = intervals[i].second;
      }
    }
    printf("%lld\n", ans);
  }
  return 0;
}
