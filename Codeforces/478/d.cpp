#include <cstdio>
#include <set>
#include <cmath>
#include <map>
#include <algorithm>

using namespace std;

map<long long, long long> val;
map<pair<int, int>, int> parallel;

int main() {
  int n, a, b;
  scanf("%d%d%d", &n, &a, &b);
  long long ans = 0;
  for(int i = 0; i < n; i++) {
    int x, vx, vy;
    scanf("%d%d%d", &x, &vx, &vy);
    ans += val[a * 1LL * vx - vy] - parallel[{vx, vy}];
    val[a * 1LL * vx - vy]++;
    parallel[{vx, vy}]++;
  }
  printf("%I64d\n", ans * 2);
  return 0;
}
