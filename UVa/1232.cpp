#include <cstdio>
#include <algorithm>
#include <cstring>
#define LEFT(x) (x<<1)
#define RIGHT(x) (x<<1)|1
#define MID(x, y) ((x+y)>>1)

using namespace std;

const int maxn = 100000;

struct Node {
  // For each node
  // the leftmost index, rightmost index and v
  int l, r, v;
  Node() {};
};

// Everything in this struct can be global
struct SegmentTree {
  Node segTree[maxn * 4]; // 4 is enough
  int setv[maxn * 4]; // An array to keep track of update array (needed for range update)
  SegmentTree();
  // i start from 1 (node index)
  // l and r are the left/right-most index for the node
  void build(int i, int l, int r);

  // Set val to node i from l to r
  int update_range(int i, int l, int r, int val);
  // Some helper functions
  // Push down the change / update on node i
  void pushdown(int i);
  // Maintain the ith node
  void maintain(int i);
};

SegmentTree tree;
int n;

int main() {
  int tc;
  scanf("%d", &tc);
  while(tc--) {
    scanf("%d", &n);
    tree.build(1, 1, 100000);
    int ans = 0;
    for(int i = 0; i < n; i++) {
      int l, r, h;
      scanf("%d%d%d", &l, &r, &h);
      ans += tree.update_range(1, l+1, r, h);
      //printf("i=%d ans=%d\n", i, ans);
    }
    printf("%d\n", ans);
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
  if(i == 1)
    memset(setv, -1, sizeof setv); // Assume -1 is never set to any range of nodes
}

int SegmentTree::update_range(int i, int l, int r, int val) {
  //printf("update_range %d %d %d\n", l, r, val);
  int ans = 0;
  if(val < setv[i]) {
    return ans;
  }
  if(l == segTree[i].l && r == segTree[i].r) {
    //printf("range match\n");
    setv[i] = val;
    //printf("setv[%d]=%d\n", i, val);
    if(val >= segTree[i].v) {
      //printf("value bigger\n");
      ans += segTree[i].r - segTree[i].l + 1;
      maintain(i);
      return ans;
    }
  }
  if(segTree[i].l < segTree[i].r) {
    //printf("pushing down\n");
    pushdown(i);
    int mid = MID(segTree[i].l, segTree[i].r);
    if(r <= mid) {
      ans += update_range(LEFT(i), l, r, val);
      maintain(RIGHT(i));
    } else if(l > mid) {
      ans += update_range(RIGHT(i), l, r, val);
      maintain(LEFT(i));
    } else {
      ans += update_range(LEFT(i), l, mid, val);
      ans += update_range(RIGHT(i), mid+1, r, val);
    }
  }
  maintain(i);
  return ans;
}

void SegmentTree::pushdown(int i) {
  // Assume all set values are non-negative
  if(setv[i] >= 0) {
    setv[LEFT(i)] = max(setv[LEFT(i)], setv[i]);
    setv[RIGHT(i)] = max(setv[RIGHT(i)], setv[i]);
    setv[i] = -1;
  }
}

void SegmentTree::maintain(int i) {
  if(segTree[i].l < segTree[i].r) {
    segTree[i].v = max(segTree[LEFT(i)].v, segTree[RIGHT(i)].v);
  }
  if(setv[i] >= 0 && setv[i] > segTree[i].v) {
    // For sum, this should be setv[i] * (setv[i].r - setv[i].l + 1);
    segTree[i].v = setv[i];
  }
}
