#include <cstdio>
#include <algorithm>
#include <set>
#include <functional>

using namespace std;

const int maxn = 26;
int v[maxn+5];
int n;

int main() {
  set<int> vis;
  scanf("%d", &n);
  for(int i = 0; i < n; i++) {
    scanf("%d", &v[i]);
  }
  long long ans = 0;
  sort(v, v+n, greater<int>());
  for(int i = 0; i < n; i++) {
    int num = v[i];
    while(vis.count(num)) {
      num--;
    }
    ans += (long long) num;
    if(num)
      vis.insert(num);
  }
  printf("%I64d\n", ans);
  return 0;
}
