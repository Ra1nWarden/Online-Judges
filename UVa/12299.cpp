#include <cstdio>
#include <cstring>
#include <cctype>
#include <algorithm>
#define LEFT(x) (x<<1)
#define RIGHT(x) (x<<1)|1
#define MID(x, y) ((x+y)>>1)

using namespace std;

const int maxn = 100000;

struct Node {
  // For each node
  // the leftmost index, rightmost index and v
  // v can be max/min/sum etc
  int l, r, v;
  Node() {};
};

// Everything in this struct can be global
struct SegmentTree {
  Node segTree[maxn * 4]; // 4 is enough
  SegmentTree();
  // i start from 1 (node index)
  // l and r are the left/right-most index for the node
  void build(int i, int l, int r);
  // i is the node index starting from 1
  // k is the element index
  // val is the new value
  void update(int i, int k, int val);
  // i is the node index starting from 1
  // l and r are the query range (inclusive)
  int query(int i, int l, int r);
};

const int maxl = 30;
SegmentTree tree;
char buffer[maxl+5];
int rv[maxl];
int ri;
int v[maxn+5];
int vp[maxn+5];

int main() {
  int n, q;
  scanf("%d%d", &n, &q);
  tree.build(1, 1, n);
  for(int i = 1; i <= n; i++) {
    int num;
    scanf("%d", &v[i]);
    tree.update(1, i, v[i]);
  }
  scanf("\n");
  for(int i = 0; i < q; i++) {
    scanf("%s\n", buffer);
    if(buffer[0] == 'q') {
      int a, b;
      sscanf(buffer, "query(%d,%d)\n", &a, &b);
      printf("%d\n", tree.query(1, a, b));
    } else if(buffer[0] == 's') {
      int len = strlen(buffer);
      int num = 0;
      ri = 0;
      for(int j = 6; j < len; j++) {
	if(!isdigit(buffer[j])) {
	  rv[ri++] = num;
	  num = 0;
	} else {
	  int digit = buffer[j] - '0';
	  num *= 10;
	  num += digit;
	}
      }
      for(int j = 0; j < ri; j++) {
	tree.update(1, rv[j], v[rv[(j+1) % ri]]);
      }
      memcpy(vp, v, sizeof v);
      for(int j = 0; j < ri; j++) {
	v[rv[j]] = vp[rv[(j+1) % ri]];
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
