#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
#define LEFT(x) (x<<1)
#define RIGHT(x) (x<<1)|1
#define MID(x, y) ((x+y)>>1)

using namespace std;

struct Ring {
  int a, b;
  long long h;
  bool operator<(const Ring& rhs) const {
    return b > rhs.b;
  }
};

const int maxn = 100000;
Ring rings[maxn+5];
vector<int> ranks;
int n;

struct Node {
  // For each node
  // the leftmost index, rightmost index and v
  // v can be max/min/sum etc
  int l, r;
  long long v;
  Node() {};
};

// Everything in this struct can be global
struct SegmentTree {
  Node segTree[maxn * 4]; // 4 is enough
  long long addv[maxn * 4]; // An array to keep track of adding array (needed for range add)
  long long setv[maxn * 4]; // An array to keep track of update array (needed for range update)
  SegmentTree();
  // i start from 1 (node index)
  // l and r are the left/right-most index for the node
  void build(int i, int l, int r);
  // i is the node index starting from 1
  // k is the element index
  // val is the new value
  void update(int i, int k, long long val);
  // i is the node index starting from 1
  // l and r are the query range (inclusive)
  long long query(int i, int l, int r);

  // Range add and update queries
  // Add val at node i from l to r
  void add_range(int i, int l, int r, long long val);
  // Set val to node i from l to r
  void update_range(int i, int l, int r, long long val);
  // Query at index i from l to r and add is the sum of addv array so far
  long long query(int i, int l, int r, long long add);
  // Some helper functions
  // Push down the change / update on node i
  void pushdown(int i);
  // Maintain the ith node
  void maintain(int i);
};

SegmentTree tree;

int merge() {
  int idx = 0;
  int a = rings[0].a, b = rings[0].b;
  long long h = rings[0].h;
  for(int i = 1; i < n; i++) {
    if(rings[i].b != b) {
      rings[idx].a = a;
      ranks.push_back(a);
      rings[idx].b = b;
      rings[idx].h = h;
      idx++;
      a = rings[i].a;
      b = rings[i].b;
      h = rings[i].h;
    } else {
      a = min(a, rings[i].a);
      h += rings[i].h;
    }
  }
  rings[idx].a = a;
  ranks.push_back(a);
  rings[idx].b = b;
  rings[idx].h = h;
  idx++;
  sort(ranks.begin(), ranks.end());
  return idx;
}

int main() {
  scanf("%d", &n);
  for(int i = 0; i < n; i++) {
    scanf("%d %d %I64d", &rings[i].a, &rings[i].b, &rings[i].h);
  }
  sort(rings, rings + n);
  n = merge();
  tree.build(1, 0, n - 1);
  for(int i = 0; i < n; i++) {
    int update_idx = lower_bound(ranks.begin(), ranks.end(), rings[i].a) - ranks.begin();
    int idx = lower_bound(ranks.begin(), ranks.end(), rings[i].b) - ranks.begin();
    long long val = rings[i].h;
    if(idx) {
      val += tree.query(1, 0, idx - 1);
    }
    tree.update(1, update_idx, val);
  }
  printf("%I64d\n", tree.query(1, 0, n - 1));
  return 0;
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
  segTree[i].v = 0LL; // Initialize v to 0.
  if(l == r)
    return;
  build(LEFT(i), l, MID(l, r));
  build(RIGHT(i), MID(l, r)+1, r);
  if(i == 1) { // reset the arrays only when depth is 1.
    memset(addv, 0, sizeof addv);
    memset(setv, -1, sizeof setv); // Assume -1 is never set to any range of nodes
  }
}

void SegmentTree::update(int i, int k, long long val) {
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
  segTree[i].v = max(segTree[LEFT(i)].v, segTree[RIGHT(i)].v);
}

long long SegmentTree::query(int i, int l, int r) {
  if(segTree[i].l == l && segTree[i].r == r)
    return segTree[i].v;
  int mid = MID(segTree[i].l, segTree[i].r);
  if(r <= mid)
    return query(LEFT(i), l, r);
  else if (l > mid)
    return query(RIGHT(i), l, r);
  else
    // Depending on data maintained in the tree, call min/max/add, etc
    return max(query(LEFT(i), l, mid), query(RIGHT(i), mid+1, r));
}

void SegmentTree::add_range(int i, int l, int r, long long val) {
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

long long SegmentTree::query(int i, int l, int r, long long add) {
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
    return max(query(LEFT(i), l, mid, addv[i] + add), query(RIGHT(i), mid+1, r, addv[i] + add));
  }
}

void SegmentTree::update_range(int i, int l, int r, long long val) {
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
    segTree[i].v = max(segTree[LEFT(i)].v, segTree[RIGHT(i)].v);
  }
  if(setv[i] >= 0) {
    // For sum, this should be setv[i] * (setv[i].r - setv[i].l + 1);
    segTree[i].v = setv[i];
  }
  // For sum, this should be setv[i] * (setv[i].r - setv[i].l + 1);
  segTree[i].v += addv[i];
}
