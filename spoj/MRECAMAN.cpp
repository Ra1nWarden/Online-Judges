#include <cstdio>
#include <unordered_set>

using namespace std;

const int maxk = 500000;
long long ans[maxk+5];

void init() {
  ans[0] = 0LL;
  unordered_set<long long> vis;
  for(int i = 1; i <= maxk; i++) {
    long long num = ans[i-1] - i;
    if(num <= 0 || vis.count(num)) {
      num = ans[i-1] + i;
    }
    ans[i] = num;
    vis.insert(num);
  }
}

int main() {
  init();
  int k;
  while(scanf("%d", &k) != EOF) {
    if(k == -1)
      break;
    printf("%lld\n", ans[k]);
  }
  return 0;
}
