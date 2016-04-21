#include <cstdio>
#include <cstring>

using namespace std;

const int maxn = 200000;

int bit[maxn+5];
int v[maxn+5];
char buffer[30];
int n;

void init() {
  memset(bit, 0, sizeof bit);
}

int lowbit(int x) {
  return x & (-x);
}

int sum(int x) {
  int ret = 0;
  while(x > 0) {
    ret += bit[x];
    x -= lowbit(x);
  }
  return ret;
}

void add(int x, int d) {
  while(x <= n) {
    bit[x] += d;
    x += lowbit(x);
  }
}

int main() {
  int kase = 1;
  while(~scanf("%d\n", &n) && n) {
    if(kase > 1)
      printf("\n");
    printf("Case %d:\n", kase++);
    init();
    for(int i = 1; i <= n; i++) {
      scanf("%d\n", &v[i]);
      add(i, v[i]);
    }
    while(fgets(buffer, sizeof buffer, stdin) != 0) {
      if(strcmp(buffer, "END\n") == 0) {
	break;
      }
      char op;
      int a, b;
      sscanf(buffer, "%c %d %d\n", &op, &a, &b);
      if(op == 'M') {
	if(a == 1) {
	  printf("%d\n", sum(b));
	} else {
	  printf("%d\n", sum(b) - sum(a-1));
	}
      } else if(op == 'S') {
	int orig = v[a];
	int diff = b - orig;
	v[a] = b;
	add(a, diff);
      }
    }
  }
  return 0;
}
