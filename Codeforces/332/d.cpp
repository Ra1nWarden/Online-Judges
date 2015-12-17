#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long LL;
typedef pair<LL, LL> LP;
vector<LP> ans;

int main() {
  LL x;
  scanf("%I64d", &x);
  for(LL n = 1; n > 0; n++) {
    LL total = 6 * x + (n * n * n) - n;
    LL div = (3 * n * n + 3 * n);
    if(total / div < n)
      break;
    if(total % div == 0) {
      LL m = total / div;
      ans.push_back(make_pair(n, m));
      if(n != m)
	ans.push_back(make_pair(m, n));
    }
  }
  sort(ans.begin(), ans.end());
  printf("%d\n", ans.size());
  for(int i = 0; i < ans.size(); i++) {
    printf("%I64d %I64d\n", ans[i].first, ans[i].second);
  }
  return 0;
}
