#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
#define LEFT(x) (x<<1)
#define RIGHT(x) (x<<1)|1
#define MID(x, y) ((x+y)>>1)

using namespace std;

struct Item {
  int r, h, i;
  Item() {}
};

const int maxn = 100000;
Item v[maxn+5];
int ranks[maxn+5];
int n;

bool cmp(int a, int b) {
  long long vol1 = v[a].r * 1LL * v[a].r * v[a].h;
  long long vol2 = v[b].r * 1LL * v[b].r * v[b].h;
  if(vol1 != vol2)
    return vol1 < vol2;
  else
    return a > b;
}

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
  Node segTree[maxn * 4 + 5]; // 4 is enough
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
};

const double pi = acos(-1);

int main() {
  scanf("%d", &n);
  for(int i = 0; i < n; i++) {
    scanf("%d %d", &v[i].r, &v[i].h);
    ranks[i] = i;
  }
  sort(ranks, ranks+n, cmp);
  for(int i = 0; i < n; i++)
    v[ranks[i]].i = i;
  SegmentTree tree;
  tree.build(1, 0, n-1);
  long long ans = 0;
  for(int i = 0; i < n ; i++) {
    int r = v[i].i;
    long long now = tree.query(1, 0, r) + v[i].r * 1LL * v[i].r * v[i].h;
    ans = max(ans, now);
    tree.update(1, r, now);
  }
  printf("%.9lf\n", pi * ans);
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
