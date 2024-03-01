#include <cstdio>
#include <vector>
#include <stack>
#include <cstring>

using namespace std;

const int maxn = 300000;
int av[maxn+5], bv[maxn+5];
int n, m;
int qv[maxn+5], dv[maxn+5], xv[maxn+5];
vector<int> adjMat[maxn+5];
vector<int> queries[maxn+5];
int depth[maxn+5];
int vis[maxn+5];
long long ans[maxn+5];
long long BIT[maxn+5];

int lowbit(int x) {
  return x & (-x);
}

long long query(int x) {
  long long ans = 0;
  while(x > 0) {
    ans += BIT[x];
    x -= lowbit(x);
  }
  return ans;
}

void add(int l, int x) {
  while(l <= n) {
    BIT[l] += x;
    l += lowbit(l);
  }
}

void add(int l, int len, int x) {
  //printf("add %d %d %d\n", l, len, x);
  add(l, x);
  if(l+len+1 <= n)
    add(l+len+1, -x);
}


int main() {
  scanf("%d", &n);
  for(int i = 0; i < n-1; i++) {
    scanf("%d %d", &av[i], &bv[i]);
    adjMat[av[i]].push_back(bv[i]);
    adjMat[bv[i]].push_back(av[i]);
  }
  scanf("%d", &m);
  for(int i = 0; i < m; i++) {
    scanf("%d %d %d", &qv[i], &dv[i], &xv[i]);
    queries[qv[i]].push_back(i);
  }
  memset(depth, 0, sizeof depth);
  memset(vis, -1, sizeof vis);
  memset(BIT, 0, sizeof BIT);
  stack<int> st;
  st.push(1);
  depth[1] = 1;
  vis[1] = 0;
  while(!st.empty()) {
    int u = st.top();
    //printf("vis %d with %d\n", u, vis[u]);
    if(vis[u] == 0) {
      for(int j = 0; j < queries[u].size(); j++) {
	int qi = queries[u][j];
	add(depth[u], dv[qi], xv[qi]);
      }
      //printf("query %d\n", u);
      ans[u] = query(depth[u]);
      for(int i = 0; i < adjMat[u].size(); i++) {
	int v = adjMat[u][i];
	if(vis[v] == -1) {
	  st.push(v);
	  vis[v] = 0;
	  depth[v] = depth[u] + 1;
	}
      }
      vis[u] = 1;
    } else {
      for(int j = 0; j < queries[u].size(); j++) {
	int qi = queries[u][j];
	add(depth[u], dv[qi], -xv[qi]);
      }
      st.pop();
    }
  }
  for(int i = 1; i <= n; i++) {
    if(i > 1)
      printf(" ");
    printf("%lld", ans[i]);
  }
  printf("\n");
  return 0;
}
