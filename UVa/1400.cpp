#include <cstdio>
#include <algorithm>
#define LEFT(x) (x << 1)
#define RIGHT(x) (x << 1) | 1
#define MID(x,y) ((x + y) >> 1)

using namespace std;

const int maxn = 500005;
int v[maxn];
long long prefix_sum[maxn];
int n, m;

struct Value {
  long long sum;
  int i, j;
  Value() {}
  Value(long long a, int b, int c) : sum(a), i(b), j(c) {}
  bool operator<(const Value& rhs) const {
    if(sum != rhs.sum) {
      return sum < rhs.sum;
    }
    if(i != rhs.i) {
      return i > rhs.i;
    }
    return j > rhs.j;
  }
};

struct Item {
  Value pre, suff, sub;
  Item() {}
  Item(Value a, Value b, Value c) : pre(a), suff(b), sub(c) {}
};

struct Node {
  int l, r;
  Item v;
  Node() {}
};

Node combine(const Node& a, const Node& b) {
  Item ans;
  ans.pre = max(a.v.pre, Value(prefix_sum[a.r] - prefix_sum[a.l - 1] + b.v.pre.sum, a.l, b.v.pre.j));

  ans.suff = max(b.v.suff, Value(prefix_sum[b.r] - prefix_sum[b.l - 1] + a.v.suff.sum, a.v.suff.i, b.r));
  
  Value third(a.v.suff.sum + b.v.pre.sum, a.v.suff.i, b.v.pre.j);
  Value orig = max(a.v.sub, b.v.sub);
  ans.sub = max(third, orig);
  ans.sub = max(ans.sub, ans.pre);
  ans.sub = max(ans.sub, ans.suff);
  Node ret;
  ret.l = a.l;
  ret.r = b.r;
  ret.v = ans;
  return ret;
}

struct SegmentTree {
  Node segTree[maxn * 4];
  SegmentTree() {}
  void build(int i, int l, int r) {
    segTree[i].l = l;
    segTree[i].r = r;
    if(l == r) {
      Value val(v[l], l, r);
      Item item(val, val, val);
      segTree[i].v = item;
      return;
    } else {
      int l_idx = LEFT(i);
      int r_idx = RIGHT(i);
      build(l_idx, l, MID(l, r));
      build(r_idx, MID(l, r) + 1, r);
      segTree[i] = combine(segTree[l_idx], segTree[r_idx]);
    }
  }
  Node query(int i, int l, int r) {
    if(segTree[i].l == l && segTree[i].r == r) {
      return segTree[i];
    }
    int mid = MID(segTree[i].l, segTree[i].r);
    if(r <= mid)
      return query(LEFT(i), l, r);
    else if(l > mid)
      return query(RIGHT(i), l, r);
    else {
      return combine(query(LEFT(i), l, mid), query(RIGHT(i), mid+1, r));
    }
  }
};

SegmentTree tree;

int main() {
  int kase = 1;
  while(scanf("%d%d", &n, &m) != EOF) {
    prefix_sum[0] = 0;
    for(int i = 1; i <= n; i++) {
      scanf("%d", &v[i]);
      prefix_sum[i] = prefix_sum[i-1] + v[i];
    }
    tree.build(1, 1, n);
    printf("Case %d:\n", kase++);
    for(int i = 0; i < m; i++) {
      int l, r;
      scanf("%d%d", &l, &r);
      Node ans = tree.query(1, l, r);
      printf("%d %d\n", ans.v.sub.i, ans.v.sub.j);
    }
  }
  return 0;
}
