#include <cstdio>
#include <algorithm>
#include <cstring>
#define LEFT(x) (x<<1)
#define RIGHT(x) (x<<1)|1
#define MID(x, y) ((x+y)>>1)

using namespace std;

const int MAXN = 30000 + 5;

struct Node {
  int l, r, v;
  Node() {};
};

struct SegmentTree {
  Node segTree[MAXN * 4]; // 4 is enough
  int addv[MAXN * 4]; // An array to keep track of adding array (needed for range add)
  int setv[MAXN * 4]; // An array to keep track of update array (needed for range update)
  SegmentTree();
  // i start from 1 (node index)
  // l and r are the left/right-most index for the node
  void build(int i, int l, int r);
  // i is the node index starting from 1
  // k is the element index
  // val is the new value
  void update(int i, int k, int val);

  // Range add and update queries
  // Add val at node i from l to r
  void add_range(int i, int l, int r, int val);
  // Query at index i from l to r and add is the sum of addv array so far
  int query(int i, int l, int r, int add);
};

char str[MAXN];
int n;

SegmentTree tree;

int main() {
  int kase = 1;
  while(scanf("%d\n", &n) != EOF) {
    scanf("%s\n", str);
    tree.build(1, 0, n - 1);
    int sum = 0;
    for(int i = 0; i < n; i++) {
      if(str[i] == '(') {
	sum++;
      } else {
	sum--;
      }
      tree.update(1, i, sum);
    }
    int queries;
    scanf("%d", &queries);
    printf("Test %d:\n", kase++);
    while(queries--) {
      int idx;
      scanf("%d", &idx);
      if(idx == 0) {
	bool ok = tree.query(1, 0, n - 1, 0) == 0 && tree.query(1, n-1, n-1, 0) == 0;
	printf("%s\n", ok ? "YES" : "NO");
      } else {
	if(str[idx-1] == '(') {
	  str[idx-1] = ')';
	  tree.add_range(1, idx-1, n-1, -2);
	} else if(str[idx-1] == ')') {
	  str[idx-1] = '(';
	  tree.add_range(1, idx-1, n-1, 2);
	}
      }
    }
  }
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

void SegmentTree::add_range(int i, int l, int r, int val) {
  if(l == segTree[i].l && r == segTree[i].r) {
    addv[i] += val;
    segTree[i].v += val;
  } else {
    int mid = MID(segTree[i].l, segTree[i].r);
    if(r <= mid)
      add_range(LEFT(i), l, r, val);
    else if(l > mid)
      add_range(RIGHT(i), l, r, val);
    else {
      add_range(LEFT(i), l, mid, val);
      add_range(RIGHT(i), mid+1, r, val);
    }
    segTree[i].v = min(segTree[LEFT(i)].v, segTree[RIGHT(i)].v);
    // If a sum is needed, do addv[i] * (segTree[i].r - segTree[i].l + 1);
    segTree[i].v += addv[i];
  }
}

int SegmentTree::query(int i, int l, int r, int add) {
  if(l == segTree[i].l && r == segTree[i].r)
    return segTree[i].v + add;
  int mid = MID(segTree[i].l, segTree[i].r);
  if(r <= mid)
    return query(LEFT(i), l, r, addv[i]+add);
  else if(l > mid)
    return query(RIGHT(i), l, r, addv[i]+add);
  else
    return min(query(LEFT(i), l, mid, addv[i]+add), query(RIGHT(i), mid+1, r, addv[i]+add));
}
