#include <cstdio>
#include <cmath>
#include <cstring>
#define MAXN 500001
#define LEFT(x) (x << 1)
#define RIGHT(x) ((x << 1) | 1)
#define MID(a, b) ((a+b) >> 1)

using namespace std;

int n, k;

char names[MAXN][15];
int ii[MAXN];
int p[MAXN];

struct Node {
  int l, r, s;
  Node() {};
};

Node segTree[MAXN * 4];

void build(int i, int l, int r) {
  segTree[i].l = l;
  segTree[i].r = r;
  segTree[i].s = r - l + 1;
  if(l == r)
    return;
  build(LEFT(i), l, MID(l, r));
  build(RIGHT(i), MID(l, r) + 1, r);
}

int query(int i, int x) {
  if(segTree[i].l == segTree[i].r) {
    segTree[i].s = 0;
    return segTree[i].l;
  }
  int leftv = segTree[LEFT(i)].s;
  int ret;
  if(leftv >= x) {
    ret = query(LEFT(i), x);
  } else {
    ret = query(RIGHT(i), x - leftv);
  }
  segTree[i].s = segTree[LEFT(i)].s + segTree[RIGHT(i)].s;
  return ret;
}

int main() {
  memset(p, 0, sizeof p);
  for(int i = 1; i <= sqrt((MAXN - 1)*1.0); i++) {
    for(int j = i+1; j*i <= MAXN; j++) {
      p[i*j] += 2;
    }
    p[i*i]++;
  }
  while(scanf("%d %d", &n, &k) != EOF) {
    build(1, 0, n-1);
    for(int i = 0; i < n; i++) {
      scanf("%s %d", names[i], &ii[i]);
    }
    int resi = -1, maxval = -1;
    for(int i = 1; i <= n; i++) {
      //cout << "looking for " << k << endl;
      int pos = query(1, k);
      //cout << "picked " << v[pos].first << endl;
      if(p[i] > maxval) {
	maxval = p[i];
	resi = pos;
      }
      if(i == n)
	break;
      int di = ii[pos];
      if(di > 0) {
	k = (k + di - 2) % (n - i) + 1;
	//k = ((k-2+n-i) % (n-i) + di) % (n-i) + 1;
      } else {
	k = ((k + di - 1) % (n - i) + (n-i))%(n-i) + 1;
	//k = (k-1 + di) % (n-i) + 1;
      }
    }
    printf("%s %d\n", names[resi], maxval);
  }
  return 0;
}
