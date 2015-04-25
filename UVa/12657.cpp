#include <cstdio>
#include <algorithm>
#define MAXN 100005

using namespace std;

int n, left[MAXN], right[MAXN];

void link(int l, int r) {
  right[l] = r;
  left[r] = l;
}

int main() {
  int m, kase = 1;
  while(scanf("%d %d", &n, &m) != EOF) {
    for(int i = 1; i <= n; i++) {
      left[i] = i-1;
      right[i] = (i+1) % (n+1);
    }
    left[0] = n;
    right[0] = 1;
    int op, x, y, inv = 0;
    while(m--) {
      scanf("%d", &op);
      if(op == 4)
	inv = !inv;
      else {
	scanf("%d %d", &x, &y);
	if(op == 3 && right[y] == x)
	  swap(x, y);
	if(op != 3 && inv)
	  op = 3 - op;
	if(op == 1 && x == left[y])
	  continue;
	if(op == 2 && x == right[y])
	  continue;

	int lx = left[x], rx = right[x], ly = left[y], ry = right[y];
	if(op == 1) {
	  link(lx, rx);
	  link(ly, x);
	  link(x, y);
	} else if(op == 2) {
	  link(lx, rx);
	  link(y, x);
	  link(x, ry);
	} else if(op == 3) {
	  if(right[x] == y) {
	    link(lx, y);
	    link(y, x);
	    link(x, ry);
	  } else {
	    link(lx, y);
	    link(y, rx);
	    link(ly, x);
	    link(x, ry);
	  }
	}
      }
    }

    int b = 0;
    long long ans = 0;
    for(int i = 1; i <= n; i++) {
      b = right[b];
      if(i % 2 == 1)
	ans += b;
    }
    if(inv && n % 2 == 0)
      ans = (long long) n * (n+1) / 2 - ans;
    printf("Case %d: %lld\n", kase++, ans);
  }
  
}
