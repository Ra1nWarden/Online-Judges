#include <cstdio>
#include <algorithm>
#define MAXN 5005

using namespace std;

int n;

struct Node {
  int l, r, s;
  Node() {};
};

Node segTree[MAXN * 4];

void build(int i, int l, int r) {
  segTree[i].l = l;
  segTree[i].r = r;
  segTree[i].s = 0;
  if(l == r)
    return;
  int mid = (l+r) / 2;
  build(i<<1, l, mid);
  build((i<<1)|1, mid+1, r);
}

void update(int i, int k, int val) {
  segTree[i].s += val;
  if(segTree[i].l == k && segTree[i].r == k)
    return;
  int mid = (segTree[i].l + segTree[i].r) / 2;
  if(mid >= k) {
    update(i<<1, k, val);
  } else {
    update((i<<1)|1, k, val);
  }
}

int query(int i, int l, int r) {
  if(l > r)
    return 0;
  if(segTree[i].l == l && segTree[i].r == r)
    return segTree[i].s;
  int mid = (segTree[i].l + segTree[i].r) / 2;
  if(mid >= r)
    return query(i<<1, l, r);
  else if (l > mid)
    return query((i<<1)|1, l, r);
  else
    return query(i<<1, l, mid) + query((i<<1)|1, mid+1, r);
}

int v[MAXN];

int main() {
  while(scanf("%d", &n) != EOF) {
    int res = 0;
    build(1, 0, n-1);
    for(int i = 0; i < n; i++) {
      scanf("%d", &v[i]);
      update(1, v[i], 1);
      res += v[i] - query(1, 0,v[i] - 1);
      //printf("v[%d] = %d\n", i, v[i]);
    }
    int prev = res;
    //printf("res is beginning at %d\n", res);
    for(int i = 0; i < n - 1; i++) {
      prev = prev - v[i] + (n - 1 - v[i]);
      res = min(res, prev);
    }
    printf("%d\n", res);
  }
  return 0;
}
