#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int maxn = 100000;
struct Node {
  int x, y, z, id;
  Node() {}
  Node(int a, int b, int c, int d) : x(a), y(b), z(c), id(d) {}
};
Node nodes[maxn+5];
Node v[maxn+5];
int vi;
int ans[maxn+5];
int c[maxn+5];
int n;
int maxval;

int lowbit(int x) {
  return x & (-x);
}

int sum(int x) {
  int ans = 0;
  while(x > 0) {
    ans += c[x];
    x -= lowbit(x);
  }
  return ans;
}

void add(int x, int d) {
  while(x <= maxval) {
    c[x] += d;
    x += lowbit(x);
  }
}

bool cmp(const Node& a, const Node& b) {
  if(a.x != b.x)
    return a.x < b.x;
  if(a.y != b.y)
    return a.y < b.y;
  return a.z < b.z;
}

bool cmp2(const Node& a, const Node& b) {
  if(a.y != b.y)
    return a.y < b.y;
  return a.id < b.id;
}

bool equal(const Node& a, const Node& b) {
  if(a.x != b.x || a.y != b.y || a.z != b.z)
    return false;
  return true;
}

void solve(int l, int r) {
  //printf("l=%d r=%d\n", l, r);
  if(l == r)
    return;
  int m = (l + r) >> 1;
  vi = 0;
  for(int i = l; i <= r; i++) {
    if(i <= m) {
      v[vi++] = Node(0, nodes[i].y, nodes[i].z, -1);
    } else {
      v[vi++] = Node(0, nodes[i].y, nodes[i].z, nodes[i].id);
    }
  }
  sort(v, v+vi, cmp2);
  for(int i = 0; i < vi; i++) {
    if(v[i].id < 0) {
      //printf("add %d\n", v[i].z);
      add(v[i].z, 1);
    } else {
      //printf("sum %d\n", v[i].z);
      ans[v[i].id] += sum(v[i].z);
    }
  }
  for(int i = 0; i < vi; i++) {
    if(v[i].id < 0)
      add(v[i].z, -1);
  }
  solve(l, m);
  solve(m+1, r);
}

int main() {
  int tc;
  scanf("%d", &tc);
  while(tc--) {
    scanf("%d", &n);
    maxval = 0;
    for(int i = 0; i < n; i++) {
      scanf("%d%d%d", &nodes[i].x, &nodes[i].y, &nodes[i].z);
      maxval = max(maxval, nodes[i].z);
      nodes[i].id = i;
    }
    sort(nodes, nodes+n, cmp);
    memset(ans, 0, sizeof ans);
    memset(c, 0, sizeof c);
    int add = 0;
    for(int i = n - 2; i > -1; i--) {
      if(equal(nodes[i], nodes[i+1])) {
	add++;
      } else {
	add = 0;
      }
      ans[nodes[i].id] += add;
    }
    solve(0, n-1);
    for(int i = 0; i < n; i++) {
      printf("%d\n", ans[i]);
    }
  }
  return 0;
}
