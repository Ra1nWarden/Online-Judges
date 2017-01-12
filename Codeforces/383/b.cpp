#include <cstdio>
#include <map>

using namespace std;

map<int, int> m;

int main() {
  int n, x;
  scanf("%d%d", &n, &x);
  int num;
  long long ans = 0;
  for(int i = 0; i < n; i++) {
    scanf("%d", &num);
    int y = x ^ num;
    if(m.count(y))
      ans += m[y];
    if(m.count(num)) {
      m[num] = m[num] + 1;
    } else {
      m[num] = 1;
    }
  }
  printf("%I64d\n", ans);
  return 0;
}
