#include <queue>
#include <cstdio>
#include <cstring>

using namespace std;

const int maxn = 200000;
int n;
int v[maxn+5];
int ans[maxn+5];

int main() {
  scanf("%d", &n);
  for(int i = 1; i <= n; i++) {
    scanf("%d", &v[i]);
  }
  memset(ans, -1, sizeof ans);
  queue<int> q;
  q.push(1);
  ans[1] = 0;
  while(!q.empty()) {
    int u = q.front();
    q.pop();
    if(u + 1 <= n && ans[u+1] == -1) {
      ans[u+1] = ans[u] + 1;
      q.push(u+1);
    }
    if(u - 1 > 0 && ans[u-1] == -1) {
      ans[u-1] = ans[u] + 1;
      q.push(u-1);
    }
    if(ans[v[u]] == -1) {
      ans[v[u]] = ans[u] + 1;
      q.push(v[u]);
    }
  }
  for(int i = 1; i <= n; i++) {
    if(i > 1)
      printf(" ");
    printf("%d", ans[i]);
  }
  printf("\n");
  return 0;
}
