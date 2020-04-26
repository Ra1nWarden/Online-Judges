#include <cstdio>
#include <cstring>
#include <queue>

using namespace std;

const int maxn = 1000000;
int vis[maxn+5];

int main() {
  int f, s, g, u, d;
  scanf("%d%d%d%d%d", &f, &s, &g, &u, &d);
  memset(vis, -1, sizeof vis);
  queue<int> q;
  q.push(s);
  vis[s] = 0;
  while(!q.empty() && vis[g] == -1) {
    int cur = q.front();
    q.pop();
    if(cur + u <= f && vis[cur + u] == -1) {
      q.push(cur + u);
      vis[cur + u] = vis[cur] + 1;
    }
    if(cur - d > 0 && vis[cur - d] == -1) {
      q.push(cur - d);
      vis[cur - d] = vis[cur] + 1;
    }
  }
  if(vis[g] == -1) {
    printf("use the stairs\n");
  } else {
    printf("%d\n", vis[g]);
  }
  return 0;
}
