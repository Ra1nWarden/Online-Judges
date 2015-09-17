#include <cstdio>
#include <random>
#include <algorithm>
#include <chrono>
#define MAXN 1000005

using namespace std;

typedef pair<long long, long long> Point;
Point points[MAXN];
int n;
int ans[MAXN];

long long dist(const Point& a, const Point& b) {
  return abs(a.first - b.first) + abs(a.second - b.second);
}

long long sum() {
  long long ret = 0;
  for(int i = 1; i < n; i++) {
    ret += dist(points[ans[i]], points[ans[i-1]]);
  }
  return ret;
}

int main() {
  scanf("%d", &n);
  for(int i = 0; i < n; i++) {
    scanf("%I64d%I64d", &points[i].first, &points[i].second);
    ans[i] = i;
  }
  while(sum() > 2800000000) {
    shuffle(ans, ans+n, default_random_engine(chrono::system_clock::now().time_since_epoch().count()));
  }
  for(int i = 0; i < n; i++) {
    if(i)
      printf(" ");
    printf("%d", ans[i] + 1);
  }
  printf("\n");
  return 0;
  
}
