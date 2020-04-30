#include <cstdio>
#include <cstring>
#define LEFT(x) (x<<1)
#define RIGHT(x) ((x<<1)|1)
#define MID(x, y) ((x+y)>>1)

using namespace std;

const int maxn = 100000;

struct Node {
  int l, r, v[3];
};

Node tree[maxn * 4];
int add[maxn * 4];

void build(int i, int l, int r) {
  tree[i].l = l;
  tree[i].r = r;
  tree[i].v[0] = r - l + 1;
  tree[i].v[1] = tree[i].v[2] = 0;
  if(l == r)
    return;
  build(LEFT(i), l, MID(l, r));
  build(RIGHT(i), MID(l, r) + 1, r);
  if(i == 1)
    memset(add, 0, sizeof add);
}

void update(int i, int l, int r) {
  if(tree[i].l == l && tree[i].r == r) {
    add[i] = (add[i] + 1) % 3;
  } else {
    int mid = MID(tree[i].l, tree[i].r);
    add[LEFT(i)] = (add[LEFT(i)] + add[i]) % 3;
    add[RIGHT(i)] = (add[RIGHT(i)] + add[i]) % 3;
    add[i] = 0;
    if(r <= mid) {
      update(LEFT(i), l, r);
    } else if(l > mid) {
      update(RIGHT(i), l, r);
    } else {
      update(LEFT(i), l, mid);
      update(RIGHT(i), mid+1, r);
    }
    tree[i].v[0] = tree[i].v[1] = tree[i].v[2] = 0;
    for(int idx = 0; idx < 3; idx++) {
      tree[i].v[(add[LEFT(i)] + idx) % 3] += tree[LEFT(i)].v[idx];
      tree[i].v[(add[RIGHT(i)] + idx) % 3] += tree[RIGHT(i)].v[idx];
    }
  }
}

int query(int i, int l, int r, int mod) {
  if(tree[i].l == l && tree[i].r == r) {
    return tree[i].v[(mod + 3 - add[i]) % 3];
  } else {
    int mid = MID(tree[i].l, tree[i].r);
    if(r <= mid) {
      return query(LEFT(i), l, r, (mod + 3 - add[i]) % 3);
    } else if(l > mid) {
      return query(RIGHT(i), l, r, (mod + 3 - add[i]) % 3);
    } else {
      return query(LEFT(i), l, mid, (mod + 3 - add[i]) % 3) + query(RIGHT(i), mid+1, r, (mod + 3 - add[i]) % 3);
    }
  }
}

int main() {
  int n, q;
  scanf("%d %d", &n, &q);
  build(1, 0, n-1);
  while(q--) {
    int op, a, b;
    scanf("%d%d%d", &op, &a, &b);
    if(op) {
      printf("%d\n", query(1, a, b, 0));
    } else {
      update(1, a, b);
    }
  }
  return 0;
}
