#include <cstdio>
#include <iostream>
#define MAXN 200005

using namespace std;

struct Node {
  int l, r, m;
  Node() {};
};

Node segTree[3 * MAXN];
int n, m;

void build(int i, int l, int r) {
  segTree[i].l = l;
  segTree[i].r = r;
  segTree[i].m = 0;
  if(l == r)
    return;
  int mid = (l + r) / 2;
  build(i << 1, l, mid);
  build((i << 1) | 1, mid+1, r);
}

void update(int i, int k, int val) {
  if(segTree[i].l == k && segTree[i].r == k) {
    segTree[i].m = val;
    return;
  }
  int mid = (segTree[i].l + segTree[i].r) / 2;
  if(k <= mid)
    update(i<<1, k, val);
  else
    update((i<<1)|1, k, val);
  segTree[i].m = max(segTree[i<<1].m, segTree[(i<<1)|1].m);
}

int query(int i, int l, int r) {
  if(segTree[i].l == l && segTree[i].r == r) {
    return segTree[i].m;
  }
  int mid = (segTree[i].l+segTree[i].r) / 2;
  if(r <= mid)
    return query(i<<1, l, r);
  else if (l > mid)
    return query((i << 1) | 1, l, r);
  else
    return max(query(i<<1, l, mid), query((i<<1)|1, mid+1, r));
}

int main() {
  while(scanf("%d %d", &n, &m) != EOF) {
    build(1, 1, n);
    for(int i = 1; i <= n; i++) {
      int x;
      scanf("%d", &x);
      update(1, i, x);
    }
    for(int i = 0; i < m; i++) {
      char q;
      int l, r;
      scanf("\n%c %d %d", &q, &l, &r);
      //printf("Query = %c for i = %d l = %d r = %d\n", q, i, l, r);
      if(q == 'Q') {
	printf("%d\n", query(1, l, r));
      }
      else if(q == 'U')
	update(1, l, r);
    }
  }
  return 0;
}
