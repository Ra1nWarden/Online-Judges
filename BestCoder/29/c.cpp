#include <cstdio>
#include <map>
#define LEFT(x) (x<<1)
#define RIGHT(x) ((x<<1)|1)
#define MID(x, y) ((x+y)>>1)
#define MAXN 1000005

using namespace std;

struct Node {
  int l, r, val;
  Node() {};
};

Node segTree[MAXN * 4];
int v[MAXN];
int prevv[MAXN];
int prefix_sum[MAXN];
int n, m;
map<int, int> prevm;

void build(int i, int l, int r) {
  segTree[i].l = l;
  segTree[i].r = r;
  if(l == r) {
    //printf("writing %d to %d\n", prevv[i], i);
    segTree[i].val = prevv[l];
    return;
  }
  build(LEFT(i), l, MID(l, r));
  build(RIGHT(i), MID(l, r) + 1, r);
  segTree[i].val = max(segTree[LEFT(i)].val, segTree[RIGHT(i)].val);
}

int query(int i, int l, int r) {
  //printf("querying %d %d\n", l, r);
  if(segTree[i].l == l && segTree[i].r == r) {
    return segTree[i].val;
  }
  int mid = MID(segTree[i].l, segTree[i].r);
  if(r <= mid)
    return query(LEFT(i), l, r);
  else if (l > mid)
    return query(RIGHT(i), l, r);
  else
    return max(query(LEFT(i), l, mid), query(RIGHT(i), mid+1, r));
}

int main() {
  while(scanf("%d %d", &n, &m) != EOF) {
    prefix_sum[0] = 0;
    prevm.clear();
    for(int i = 1; i <= n; i++) {
      scanf("%d", &v[i]);
      prefix_sum[i] = prefix_sum[i-1] + v[i];
      if(prevm.count(v[i]) == 0) {
	prevv[i] = 0;
      }
      else {
	prevv[i] = prevm[v[i]];
      }
      prevm[v[i]] = i;
    }

    build(1, 1, n);
    for(int i = 0; i < m; i++) {
      int l, r;
      scanf("%d %d", &l, &r);
      int sum = prefix_sum[r] - prefix_sum[l - 1];
      //printf("prefix sum is %d\n", sum);
      //printf("query result is %d\n", query(1, l, r));
      if(sum == (1 + (r - l + 1)) * (r - l + 1) / 2 && query(1, l, r) < l) {
	printf("YES\n");
      } else {
	printf("NO\n");
      }
    }
  }
  return 0;
}
