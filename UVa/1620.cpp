#include <cstring>
#include <cstdio>
#define MAXN 1010

using namespace std;

int tree[MAXN];
int n;

int lowbit(int x) {
  return x & (-x);
}

int sum(int x) {
  int ret = 0;
  while(x > 0) {
    ret += tree[x];
    x -= lowbit(x);
  }
  return ret;
}

int add(int x, int d) {
  while(x <= n) {
    tree[x] += d;
    x += lowbit(x);
  }
}

int v[MAXN*2];

int main() {
  int tc;
  scanf("%d", &tc);
  while(tc--) {
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
      scanf("%d", &v[i]);
      v[i+n] = v[i];
    }
    bool possible = false;
    for(int i = 0; i < n; i++) {
      int inv = 0;
      memset(tree, 0, sizeof tree);
      for(int j = i; j < i + n; j++) {
	inv += j - i - sum(v[j]);
	add(v[j], 1);
      }
      if(inv % 2 == 0) {
	possible = true;
	break;
      }
    }
    if(possible) 
      printf("possible\n");
    else
      printf("impossible\n");
  }
  return 0;
}
