#include <cstdio>
#include <algorithm>
#define LEFT(x) (x << 1)
#define RIGHT(x) (x << 1) | 1
#define MID(x, y) ((x + y) >> 1)

using namespace std;

const int maxn = 50000;
int n;

struct Node {
  int l, r;
  long long sum, lm, rm, mm;
};

struct SegmentTree {
  Node segTree[maxn * 4];
  void build(int i, int l, int r) {
    segTree[i].l = l;
    segTree[i].r = r;
    if(l == r)
      return;
    build(LEFT(i), l, MID(l, r));
    build(RIGHT(i), MID(l, r) + 1, r);
  }

  void update(int i, int k, int val) {
    if(segTree[i].l == k && segTree[i].r == k) {
      segTree[i].sum = val;
      segTree[i].lm = val;
      segTree[i].rm = val;
      segTree[i].mm = val;
      return;
    }
    int mid = MID(segTree[i].l, segTree[i].r);
    if(k <= mid) {
      update(LEFT(i), k, val);
    } else {
      update(RIGHT(i), k, val);
    }
    segTree[i].sum = segTree[LEFT(i)].sum + segTree[RIGHT(i)].sum;
    segTree[i].lm = max(segTree[LEFT(i)].lm, segTree[LEFT(i)].sum + segTree[RIGHT(i)].lm);
    segTree[i].rm = max(segTree[RIGHT(i)].rm, segTree[RIGHT(i)].sum + segTree[LEFT(i)].rm);
    segTree[i].mm = max(segTree[LEFT(i)].rm + segTree[RIGHT(i)].lm, max(segTree[LEFT(i)].mm, segTree[RIGHT(i)].mm));
  }

  long long query_s(int i, int l, int r) {
    if(segTree[i].l == l && segTree[i].r == r) {
      return segTree[i].sum;
    }
    int mid = MID(segTree[i].l, segTree[i].r);
    if(r <= mid)
      return query_s(LEFT(i), l, r);
    else if(l > mid)
      return query_s(RIGHT(i), l, r);
    else {
      return query_s(LEFT(i), l, mid) + query_s(RIGHT(i), mid + 1, r);
    }
  }

  long long query_l(int i, int l, int r) {
    if(segTree[i].l == l && segTree[i].r == r) {
      return segTree[i].lm;
    }
    int mid = MID(segTree[i].l, segTree[i].r);
    if(r <= mid)
      return query_l(LEFT(i), l, r);
    else if(l > mid)
      return query_l(RIGHT(i), l, r);
    else {
      return max(query_l(i, l, mid), query_s(i, l, mid) + query_l(i, mid + 1, r));
    }
  }

  long long query_r(int i, int l, int r) {
    if(segTree[i].l == l && segTree[i].r == r) {
      return segTree[i].rm;
    }
    int mid = MID(segTree[i].l, segTree[i].r);
    if(r <= mid)
      return query_r(LEFT(i), l, r);
    else if(l > mid)
      return query_r(RIGHT(i), l, r);
    else {
      return max(query_r(i, mid + 1, r), query_r(i, l, mid) + query_s(i, mid + 1, r));
    }
  }
  
  long long query_m(int i, int l, int r) {
    if(segTree[i].l == l && segTree[i].r == r) {
      return segTree[i].mm;
    }
    int mid = MID(segTree[i].l, segTree[i].r);
    if(r <= mid)
      return query_m(LEFT(i), l, r);
    else if(l > mid)
      return query_m(RIGHT(i), l, r);
    else {
      return max(query_r(i, l, mid) + query_l(i, mid+1, r), max(query_m(i, l, mid), query_m(i, mid+1, r)));
    }
  }
};

SegmentTree tree;

int main() {
  scanf("%d", &n);
  tree.build(1, 1, n);
  int v;
  for(int i = 1; i <= n; i++) {
    scanf("%d", &v);
    tree.update(1, i, v);
  }
  int qc;
  scanf("%d", &qc);
  while(qc--) {
    int l, r;
    scanf("%d %d", &l, &r);
    printf("%lld\n", tree.query_m(1, l, r));
  }
  return 0;
}
