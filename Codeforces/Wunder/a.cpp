#include <cstdio>
#include <vector>

using namespace std;

void solve(int n, vector<int>& ans) {
  int cur = 1;
  int add = 1;
  while(n >= (cur << 1)) {
    cur <<= 1;
    add++;
  }
  ans.push_back(add);
  n -= cur;
  if(n)
    solve(n, ans);
}

int main() {
  int n;
  scanf("%d", &n);
  vector<int> ans;
  solve(n, ans);
  for(int i = 0; i < ans.size(); i++) {
    if(i)
      printf(" ");
    printf("%d", ans[i]);
  }
  printf("\n");
  return 0;
}
