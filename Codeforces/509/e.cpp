#include <cstdio>
#include <algorithm>
#include <vector>
#include <cstring>

using namespace std;

const int maxn = 1000;
int v[maxn+5];
int n;
bool vis[maxn+5];
vector<vector<int> > children;
vector<int> children_len;

int main() {
  scanf("%d", &n);
  bool legal = true;
  int a, b;
  for(int i = 0; i < n-1; i++) {
    scanf("%d %d", &a, &b);
    if(b != n) {
      legal = false;
      break;
    }
    v[i] = a;
  }
  if(!legal) {
    printf("NO\n");
    return 0;
  }

  sort(v, v+n-1);

  memset(vis, false, sizeof vis);

  int prev = 0;
  for(int i = 0; i < n-1; i++) {
    if(v[i] != prev) {
      vector<int> child;
      child.push_back(v[i]);
      vis[v[i]] = true;
      children.push_back(child);
      children_len.push_back(1);
    } else {
      children_len.back()++;
    }
    prev = v[i];
  }
  
  int cur = 0;
  for(int next = 1; next <= n-1; next++) {
    if(vis[next])
      continue;
    while(cur < children.size() && children[cur].size() == children_len[cur])
      cur++;
    if(cur >= children.size() || children[cur][0] < next) {
      legal = false;
      break;
    }
    children[cur].push_back(next);
  }

  if(!legal) {
    printf("NO\n");
    return 0;
  }

  printf("YES\n");
  for(int i = 0; i < children.size(); i++) {
    int prev = n;
    for(int j = children[i].size() - 1; j >= 0; j--) {
      printf("%d %d\n", prev, children[i][j]);
      prev = children[i][j];
    }
  }
  
  return 0;
}
