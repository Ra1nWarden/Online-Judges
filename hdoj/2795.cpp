#include <cstdio>
#include <algorithm>
#define MAXN 200005

using namespace std;

struct Node {
  int l, r, m;
};

Node segTree[MAXN*3];
int h, w, n;

void build(int i, int l, int r) {
  segTree[i].l = l;
  segTree[i].r = r;
  segTree[i].m = w;
  if(l == r)
    return;
  int mid = (l+r)>>1;
  build(i<<1, l, mid);
  build((i<<1)|1, mid+1, r);
}

void update(int i, int k, int val) {
  if(segTree[i].l == k && segTree[i].r == k) {
    segTree[i].m = val;
    return;
  }
  int mid = (segTree[i].l + segTree[i].r)>>1;
  if(mid >= k)
    update(i<<1, k, val);
  else
    update((i<<1)|1, k, val);
  segTree[i].m = max(segTree[i<<1].m, segTree[(i<<1)|1].m);
}

int query(int i, int val) {
  //printf("querying %d\n", i);
  if(segTree[i].m < val)
    return -1;
  if(segTree[i].l == segTree[i].r) {
    //printf("found\n");
    update(1, segTree[i].l, segTree[i].m - val);
    return segTree[i].l;
  }
  //printf("here3\n");
  if(segTree[i<<1].m >= val)
    return query(i<<1, val);
  else
    return query((i<<1)|1, val);
}


int main() {
  while(scanf("%d %d %d", &h, &w, &n) != EOF) {
    build(1, 1, min(h, MAXN));
    for(int i = 0; i < n; i++) {
      int board;
      scanf("%d", &board);
      printf("%d\n", query(1, board));
    }
  }
  return 0;
}
