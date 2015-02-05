#include <cstdio>
#define MAXN 200005

using namespace std;

struct Node {
  int l, r, m;
};

Node segTree[MAXN*3];
int v[MAXN];
int q[MAXN][2];

void build(int i, int l, int r) {
  segTree[i].l = l;
  segTree[i].r = r;
  segTree[i].m = r - l + 1;
  if(l == r)
    return;
  int mid = (l+r)>>1;
  build(i<<1, l, mid);
  build((i<<1)|1, mid+1, r);
}

int query(int i, int val) {
  if(segTree[i].l == segTree[i].r) {
    segTree[i].m = 0;
    return segTree[i].l;
  }
  int res;
  if(segTree[i<<1].m >= val)
    res = query(i<<1, val);
  else
    res = query((i<<1)|1, val - segTree[i<<1].m);
  segTree[i].m = segTree[i<<1].m + segTree[(i<<1)|1].m;
  return res;
}

int main() {
  int n;
  while(scanf("%d", &n) != EOF) {
    build(1, 0, n-1);
    for(int i = 1; i <= n; i++) {
      scanf("%d %d", &q[i][0], &q[i][1]);
    }
    for(int i = n; i >= 1; i--) {
      int index = query(1, q[i][0]+1);
      //printf("writing %d to v[%d]\n", q[i][1], index);
      v[index] = q[i][1];
    }
    for(int i = 0; i < n; i++) {
      if(i != 0)
	printf(" ");
      printf("%d", v[i]);
    }
    printf("\n");
  }
  return 0;
}
