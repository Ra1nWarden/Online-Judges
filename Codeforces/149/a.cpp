#include <cstdio>
#include <vector>

using namespace std;

typedef pair<int, int> II;

int main() {
  int x, y, a, b;
  scanf("%d%d%d%d", &x, &y, &a, &b);
  vector<II> ans;
  for(int i = max(a, b + 1); i <= x; i++) {
    for(int j = b; j < min(i, y + 1); j++) {
      ans.push_back(make_pair(i, j));
    }
  }
  printf("%d\n", ans.size());
  for(int i = 0; i < ans.size(); i++) {
    printf("%d %d\n", ans[i].first, ans[i].second);
  }
  return 0;
}
