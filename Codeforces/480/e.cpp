#include <cstdio>
#include <queue>
#include <vector>
#include <cstring>

using namespace std;

const int maxn = 1000000;
vector<int> adjMat[maxn+5];
int parent[maxn+5][20];
int depth[maxn+5];
int n, k;
bool vis[maxn+5];

int walk(int u, int len) {
  int bit = 0;
  while((1 << bit) <= len) {
    if(len & (1 << bit)) {
      u = parent[u][bit];
    }
    bit++;
  }
  return u;
}

int main() {
  scanf("%d %d", &n, &k);
  int u, v;
  for(int i = 0; i < n - 1; i++) {
    scanf("%d %d", &u, &v);
    adjMat[u].push_back(v);
    adjMat[v].push_back(u);
  }
  memset(parent, 0, sizeof parent);
  memset(depth, -1, sizeof depth);
  depth[n] = 0;
  queue<int> q;
  q.push(n);
  while(!q.empty()) {
    int cur = q.front();
    q.pop();
    for(int i = 0; i < adjMat[cur].size(); i++) {
      int child = adjMat[cur][i];
      if(depth[child] != -1) {
	continue;
      }
      parent[child][0] = cur;
      depth[child] = depth[cur] + 1;
      q.push(child);
    }
  }

  for(int i = 1; i < 20; i++) {
    for(int node = 1; node <= n; node++) {
      parent[node][i] = parent[parent[node][i-1]][i-1];
    }
  }

  memset(vis, false, sizeof vis);
  vis[n] = true;
  int vis_count = 1;
  for(int i = n - 1; i >= 1 && vis_count < n - k; i--) {
    if(vis[i]) {
      continue;
    }
    int left = 1, right = depth[i];
    while(left != right) {
      int mid = (left + right) >> 1;
      int walked = walk(i, mid);
      if(vis[walked]) {
	right = mid;
      } else {
	left = mid + 1;
      }
    }
    if(vis_count + left > n - k) {
      continue;
    }
    int cur = i;
    while(!vis[cur]) {
      vis[cur] = true;
      vis_count++;
      cur = parent[cur][0];
    }
  }

  for(int i = 1; i <= n && k; i++) {
    if(!vis[i]) {
      printf("%d", i);
      k--;
      if(k)
	printf(" ");
    }
  }
  printf("\n");

  return 0;
}
