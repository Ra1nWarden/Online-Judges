#include <cstdio>
#include <algorithm>
#include <map>
#define LEFT(x) (x<<1)
#define RIGHT(x) (x<<1)|1
#define MID(x, y) ((x+y)>>1)

using namespace std;

struct Query {
  int a, t, x;
};

const int maxn = 100000;

Query queries[maxn+5];
int n;
int buff[maxn+5];

struct Node {
  int l, r;
  map<int, int> v;
  Node() {};
};

struct SegmentTree {
  Node segTree[maxn * 4];
  SegmentTree();
  void build(int i, int l, int r);
  int query(int i, int l, int r, int val);

  void add_range(int i, int l, int r, int val);
  int query(int i, int l, int r, int add);
  // Some helper functions
  // Push down the change / update on node i
  void pushdown(int i);
  // Maintain the ith node
  void maintain(int i);
};

void change_map(map<int, int>& ma, int val, bool add) {
  if(ma.count(val)) {
    if(add)
      ma[val] = ma[val] + 1;
    else
      ma[val] = ma[val] - 1;
  } else {
    if(add)
      ma[val] = 1;
  }
}

int query_map(map<int, int>& ma, int val) {
  if(ma.count(val))
    return ma[val];
  else
    return 0;
}

SegmentTree tree;

int main() {
  scanf("%d", &n);
  for(int i = 0; i < n; i++) {
    scanf("%d%d%d", &queries[i].a, &queries[i].t, &queries[i].x);
    buff[i] = queries[i].t;
  }
  tree.build(1, 0, n-1);
  sort(buff, buff+n);
  for(int i = 0; i < n; i++) {
    int tt = lower_bound(buff, buff+n, queries[i].a) - buff;
    if(queries[i].a == 1) {
      tree.update(1, tt, queries[i].x, true);
    } else if(queries[i].a == 2) {
      tree.update(1, tt, queries[i].x, false);
    } else if(queries[i].a == 3) {
      printf("%d\n", tree.query(1, 0, tt, queries[i].x));
    }
  }
  return 0;
}

SegmentTree::SegmentTree() {};

void SegmentTree::build(int i, int l, int r) {
  segTree[i].l = l;
  segTree[i].r = r;
  if(l == r)
    return;
  build(LEFT(i), l, MID(l, r));
  build(RIGHT(i), MID(l, r)+1, r);
}

void SegmentTree::update(int i, int k, int val, bool add) {
  if(segTree[i].l == k && segTree[i].r == k) {
    change_map(segTree[i].v, val, add);
    return;
  }
  int mid = MID(segTree[i].l, segTree[i].r);
  if(k <= mid)
    update(LEFT(i), k, val, add);
  else
    update(RIGHT(i), k, val, add);
  change_map(segTree[i].v, val, add);
}

int SegmentTree::query(int i, int l, int r, int val) {
  if(segTree[i].l == l && segTree[i].r == r)
    return query_map(segTree[i].v, val);
  int mid = MID(segTree[i].l, segTree[i].r);
  if(r <= mid)
    return query(LEFT(i), l, r, val);
  else if (l > mid)
    return query(RIGHT(i), l, r, val);
  else
    return query(LEFT(i), l, mid, val) + query(RIGHT(i), mid+1, r, val);
}

SegmentTree::SegmentTree() {};

void SegmentTree::build(int i, int l, int r) {
  segTree[i].l = l;
  segTree[i].r = r;
  /*
    There are multiple ways to build the tree.
    Here, I am initializing everything to 0 and use update to insert values.
    It is also fine to initialize the tree with values in the array in build().
   */
  segTree[i].v = 0; // Initialize v to 0.
  if(l == r)
    return;
  build(LEFT(i), l, MID(l, r));
  build(RIGHT(i), MID(l, r)+1, r);
  if(i == 1) { // reset the arrays only when depth is 1.
    memset(addv, 0, sizeof addv);
    memset(setv, -1, sizeof setv); // Assume -1 is never set to any range of nodes
  }
}

void SegmentTree::update(int i, int k, int val) {
  /*
    For sum type of segment tree, it can be done with BIT.
    If segment tree is still used, update can be simplified to
    segTree[i] += val;
    where val is the offset being added which is different from
    the meaning of the val here.
   */
  if(segTree[i].l == k && segTree[i].r == k) {
    segTree[i].v = val;
    return;
  }
  int mid = MID(segTree[i].l, segTree[i].r);
  if(k <= mid)
    update(LEFT(i), k, val);
  else
    update(RIGHT(i), k, val);
  // This function can be done at the beginning of ths method.
  // Depending on data maintained in the tree, call min/max/add, etc
  segTree[i].v = min(segTree[LEFT(i)].v, segTree[RIGHT(i)].v);
}

int SegmentTree::query(int i, int l, int r) {
  if(segTree[i].l == l && segTree[i].r == r)
    return segTree[i].v;
  int mid = MID(segTree[i].l, segTree[i].r);
  if(r <= mid)
    return query(LEFT(i), l, r);
  else if (l > mid)
    return query(RIGHT(i), l, r);
  else
    // Depending on data maintained in the tree, call min/max/add, etc
    return min(query(LEFT(i), l, mid), query(RIGHT(i), mid+1, r));
}

void SegmentTree::add_range(int i, int l, int r, int val) {
  if(l == segTree[i].l && r == segTree[i].r) {
    addv[i] += val;
  } else {
    pushdown(i);
    int mid = MID(segTree[i].l, segTree[i].r);
    if(r <= mid) {
      add_range(LEFT(i), l, r, val);
      maintain(RIGHT(i));
    }
    else if(l > mid) {
      add_range(RIGHT(i), l, r, val);
      maintain(LEFT(i));
    }
    else {
      add_range(LEFT(i), l, mid, val);
      add_range(RIGHT(i), mid+1, r, val);
    }
  }
  maintain(i);
}

int SegmentTree::query(int i, int l, int r, int add) {
  if(setv[i] >= 0) {
    return setv[i] + addv[i] + add; // Need to add
  }
  if(segTree[i].l == l && segTree[i].r == r) {
    return segTree[i].v + add;
  }
  int mid = MID(segTree[i].l, segTree[i].r);
  if(r <= mid) {
    return query(LEFT(i), l, r, addv[i] + add);
  } else if(l > mid) {
    return query(RIGHT(i), l, r, addv[i] + add);
  } else {
    return min(query(LEFT(i), l, mid, addv[i] + add), query(RIGHT(i), mid+1, r, addv[i] + add));
  }
}

void SegmentTree::update_range(int i, int l, int r, int val) {
  if(l == segTree[i].l && r == segTree[i].r) {
    setv[i] = val;
    addv[i] = 0;
  } else {
    pushdown(i);
    int mid = MID(segTree[i].l, segTree[i].r);
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

void SegmentTree::pushdown(int i) {
  // Assume all set values are non-negative
  if(setv[i] >= 0) {
    setv[LEFT(i)] = setv[RIGHT(i)] = setv[i];
    setv[i] = -1;
    addv[LEFT(i)] = addv[RIGHT(i)] = 0;
  }
  addv[LEFT(i)] += addv[i];
  addv[RIGHT(i)] += addv[i];
  addv[i] = 0;
}

void SegmentTree::maintain(int i) {
  if(segTree[i].l < segTree[i].r) {
    segTree[i].v = min(segTree[LEFT(i)].v, segTree[RIGHT(i)].v);
  }
  if(setv[i] >= 0) {
    // For sum, this should be setv[i] * (setv[i].r - setv[i].l + 1);
    segTree[i].v = setv[i];
  }
  // For sum, this should be setv[i] * (setv[i].r - setv[i].l + 1);
  segTree[i].v += addv[i];
}
