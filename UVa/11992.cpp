#include <cstdio>
#include <cstring>
#include <algorithm>
#define LEFT(x) (x<<1)
#define RIGHT(x) ((x<<1)|1)
#define MID(x, y) ((x+y)>>1)

using namespace std;

const int maxm = 21;
const int maxn = 1000000 / maxm + 5;

struct Node {
  int i, l, r, minv, maxv, sum;
};

struct Ans {
  int minv, maxv, sum;
};

struct SegmentTree {
  Node nodes[maxn * 4];
  int addv[maxn * 4];
  int setv[maxn * 4];
  SegmentTree() {}
  void build(int i, int l, int r) {
    nodes[i].l = l;
    nodes[i].r = r;
    nodes[i].minv = nodes[i].maxv = nodes[i].sum = 0;
    if(l == r)
      return;
    int mid = MID(l, r);
    build(LEFT(i), l, mid);
    build(RIGHT(i), mid+1, r);
    memset(addv, 0, sizeof addv);
    memset(setv, -1, sizeof setv);
  }
  void pushdown(int i) {
    if(setv[i] >= 0) {
      setv[LEFT(i)] = setv[RIGHT(i)] = setv[i];
      setv[i] = -1;
      addv[LEFT(i)] = addv[RIGHT(i)] = 0;
    }
    if(addv[i] > 0) {
      addv[LEFT(i)] += addv[i];
      addv[RIGHT(i)] += addv[i];
      addv[i] = 0;
    }
  }
  void maintain(int i) {
    if(nodes[i].l < nodes[i].r) {
      nodes[i].sum = nodes[LEFT(i)].sum + nodes[RIGHT(i)].sum;
      nodes[i].minv = min(nodes[LEFT(i)].minv, nodes[RIGHT(i)].minv);
      nodes[i].maxv = max(nodes[LEFT(i)].maxv, nodes[RIGHT(i)].maxv);
    }
    if(setv[i] >= 0) {
      nodes[i].minv = nodes[i].maxv = setv[i];
      nodes[i].sum = setv[i] * (nodes[i].r - nodes[i].l + 1);
    }
    if(addv[i] > 0) {
      nodes[i].minv += addv[i];
      nodes[i].maxv += addv[i];
      nodes[i].sum += addv[i] * (nodes[i].r - nodes[i].l + 1);
    }
  }
  void add_range(int i, int l, int r, int val) {
    if(l == nodes[i].l && r == nodes[i].r) {
      addv[i] += val;
    } else {
      pushdown(i);
      int mid = MID(nodes[i].l, nodes[i].r);
      if(r <= mid) {
	add_range(LEFT(i), l, r, val);
	maintain(RIGHT(i));
      } else if(l > mid) {
	add_range(RIGHT(i), l, r, val);
	maintain(LEFT(i));
      } else {
	add_range(LEFT(i), l, mid, val);
	add_range(RIGHT(i), mid+1, r, val);
      }
    }
    maintain(i);
  }
  void update_range(int i, int l, int r, int val) {
    if(l == nodes[i].l && r == nodes[i].r) {
      setv[i] = val;
      addv[i] = 0;
    } else {
      pushdown(i);
      int mid = MID(nodes[i].l, nodes[i].r);
      if(r <= mid) {
	update_range(LEFT(i), l, r, val);
	maintain(RIGHT(i));
      } else if(l > mid) {
	update_range(RIGHT(i), l, r, val);
	maintain(LEFT(i));
      } else {
	update_range(LEFT(i), l, mid, val);
	update_range(RIGHT(i), mid+1, r, val);
      }
    }
    maintain(i);
  }
  Ans query(int i, int l, int r, int add) {
    Ans ans;
    if(setv[i] >= 0) {
      ans.minv = setv[i] + add + addv[i];
      ans.maxv = setv[i] + add + addv[i];
      ans.sum = (setv[i] + add + addv[i]) * (r - l + 1);
      return ans;
    }
    if(l == nodes[i].l && r == nodes[i].r) {
      ans.minv = nodes[i].minv + add;
      ans.maxv = nodes[i].maxv + add;
      ans.sum = nodes[i].sum + add * (r - l + 1);
      return ans;
    }
    int mid = MID(nodes[i].l, nodes[i].r);
    if(r <= mid) {
      ans = query(LEFT(i), l, r, addv[i] + add);
      return ans;
    } else if(l > mid) {
      ans = query(RIGHT(i), l, r, addv[i] + add);
      return ans;
    } else {
      Ans left = query(LEFT(i), l, mid, addv[i] + add);
      Ans right = query(RIGHT(i), mid+1, r, addv[i] + add);
      ans.minv = min(left.minv, right.minv);
      ans.maxv = max(left.maxv, right.maxv);
      ans.sum = left.sum + right.sum;
      return ans;
    }
  }
};

int m, n, q;
int v[maxn];
SegmentTree trees[maxm];

int main() {
  while(scanf("%d%d%d", &m, &n, &q) != EOF) {
    for(int i = 1; i <= m; i++)
      trees[i].build(1, 1, n);
    for(int i = 0; i < q; i++) {
      int query;
      scanf("%d", &query);
      int x1, y1, x2, y2, v;
      if(query == 1) {
	scanf("%d%d%d%d%d", &x1, &y1, &x2, &y2, &v);
	for(int x = x1; x <= x2; x++)
	  trees[x].add_range(1, y1, y2, v);
      } else if(query == 2) {
	scanf("%d%d%d%d%d", &x1, &y1, &x2, &y2, &v);
	for(int x = x1; x <= x2; x++)
	  trees[x].update_range(1, y1, y2, v);
      } else {
	scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
	int maxval = -1;
	int minval = 2000000000;
	int sum = 0;
	for(int x = x1; x <= x2; x++) {
	  Ans each = trees[x].query(1, y1, y2, 0);
	  maxval = max(maxval, each.maxv);
	  minval = min(minval, each.minv);
	  sum += each.sum;
	}
	printf("%d %d %d\n", sum, minval, maxval);
      }
    }
  }
  return 0;
}
