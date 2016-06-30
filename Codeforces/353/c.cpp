#include <cstdio>
#include <map>
#include <algorithm>

using namespace std;

int main() {
  int n;
  scanf("%d", &n);
  map<long long, int> m;
  int ans = n;
  long long sum = 0;
  for(int i = 0; i < n; i++) {
    int num;
    scanf("%d", &num);
    sum += num;
    m[sum]++;
    ans = min(ans, n - m[sum]);
  }
  printf("%d\n", ans);
  return 0;
}
