#include <cstdio>
#include <cstring>
#define LEFT(x) (x<<1)
#define RIGHT(x) ((x<<1)|1)
#define MID(x, y) ((x+y)>>1)

using namespace std;

const int maxn = 100000;

struct Node {
  int l, r, v;
};

Node tree[(maxn + 5) * 4];
bool flip[(maxn + 5) * 4];
int n;

void build(int i, int l, int r) {
  tree[i].l = l;
  tree[i].r = r;
  tree[i].v = 0;
  if(l == r)
    return;
  build(LEFT(i), l, MID(l, r));
  build(RIGHT(i), MID(l, r)+1, r);
}

void update(int i, int l, int r) {
  if(tree[i].l == l && tree[i].r == r) {
    flip[i] = !flip[i];
  } else {
    int mid = MID(tree[i].l, tree[i].r);
    if(flip[i]) {
      flip[i] = false;
      flip[LEFT(i)] = !flip[LEFT(i)];
      flip[RIGHT(i)] = !flip[RIGHT(i)];
    }
    if(r <= mid)
      update(LEFT(i), l, r);
    else if(l > mid)
      update(RIGHT(i), l, r);
    else {
      update(LEFT(i), l, mid);
      update(RIGHT(i), mid+1, r);
    }
  }
  int leftv = tree[LEFT(i)].v;
  if(flip[LEFT(i)])
    leftv = tree[LEFT(i)].r - tree[LEFT(i)].l + 1 - leftv;
  int rightv = tree[RIGHT(i)].v;
  if(flip[RIGHT(i)])
    rightv = tree[RIGHT(i)].r - tree[RIGHT(i)].l + 1 - rightv;
  tree[i].v = leftv + rightv;
}

int query(int i, int l, int r, bool f) {
  if(tree[i].l == l && tree[i].r == r) {
    int ans = tree[i].v;
    if(flip[i] ^ f)
      ans = tree[i].r - tree[i].l + 1 - ans;
    return ans;
  } else {
    int mid = MID(tree[i].l, tree[i].r);
    if(r <= mid) {
      return query(LEFT(i), l, r, flip[i] ^ f);
    } else if(l > mid) {
      return query(RIGHT(i), l, r, flip[i] ^ f);
    } else {
      return query(LEFT(i), l, mid, flip[i] ^ f) + query(RIGHT(i), mid+1, r, flip[i] ^ f);
    }
  }
}

int main() {
  int q;
  scanf("%d%d", &n, &q);
  memset(flip, false, sizeof flip);
  build(1, 1, n);
  while(q--) {
    int op, l, r;
    scanf("%d%d%d", &op, &l, &r);
    if(op == 0) {
      update(1, l, r);
    } else {
      printf("%d\n", query(1, l, r, false));
    }
  }
  return 0;
}
