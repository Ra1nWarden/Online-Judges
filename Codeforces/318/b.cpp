#include <cstdio>
#include <queue>
#include <cstring>
#define MAXN 100005

using namespace std;

int v[MAXN];
int ans[MAXN];
int n;

int main() {
  scanf("%d", &n);
  queue<int> q;
  memset(ans, 0, sizeof ans);
  for(int i = 0; i < n; i++) {
    scanf("%d", &v[i]);
    ans[i] =  min(i - 0 + 1, n - 1 - i + 1);
    if(ans[i] > v[i]) {
      ans[i] = v[i];
      q.push(i);
    }
  }
  while(!q.empty()) {
    int u = q.front();
    q.pop();
    if(u - 1 >= 0 && ans[u-1] > ans[u] + 1) {
      ans[u-1] = ans[u] + 1;
      q.push(u-1);
    }
    if(u + 1 < n && ans[u+1] > ans[u] + 1) {
      ans[u+1] = ans[u] + 1;
      q.push(u+1);
    }
  }
  int res = ans[0];
  for(int i = 1; i < n; i++) {
    res = max(res, ans[i]);
  }
  printf("%d\n", res);
  return 0;
}
