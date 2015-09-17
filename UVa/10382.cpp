#include <cstdio>
#include <utility>
#include <algorithm>
#include <cmath>
#define EPS 1e-8
#define MAXN 10005

using namespace std;

double n, l, w;
typedef pair<double, double> Interval;
Interval v[MAXN];
int vi;
bool _cmp(const Interval& a, const Interval& b) {
  return a.first < b.first;
}

int main() {
  while(~scanf("%lf%lf%lf", &n, &l, &w)) {
    vi = 0;
    for(int i = 0; i < n; i++) {
      double pos, rad;
      scanf("%lf %lf", &pos, &rad);
      if(2 * rad <= w)
	continue;
      double half = sqrt(rad * rad - w * w / 4.0);
      v[vi++] = make_pair(pos - half, pos + half);
    }
    sort(v, v+vi, _cmp);
    double pos = 0;
    int ans = 0;
    double next_pos = 0;
    int i = 0;
    while(i < n) {
      if(v[i].first > pos) {
    	break;
      }
      while(i < n && v[i].first - pos < EPS) {
    	next_pos = max(next_pos, v[i].second);
    	i++;
      }
      ans++;
      pos = next_pos;
    }
    if(pos > l || fabs(pos - l) < EPS) {
      printf("%d\n", ans);
    } else {
      printf("-1\n");
    }
    // int ans = 0;
    // double left = 0, right = 0;
    // bool flag = false;
    // if(v[0].first <= 0) {
    //   int i = 0;
    //   while(i < n) {
    // 	int j = i;
    // 	while(j < n & left >= v[j].first) {
    // 	  if(v[j].second > right)
    // 	    right = v[j].second;
    // 	  j++;
    // 	}
    // 	if(j == i)
    // 	  break;
    // 	ans++;
    // 	left = right;
    // 	i = j;
    // 	if(left >= l) {
    // 	  flag = true;
    // 	  break;
    // 	}
    //   }
    // }
    // if(flag)
    //   printf("%d\n", ans);
    // else
    //   printf("-1\n");
  }
  return 0;
}
