#include <cstdio>
#include <cstring>

using namespace std;

const int maxn = 10;
int v[maxn+5];
int vi;

int main() {
  int tc;
  scanf("%d", &tc);
  int base;
  while(tc--) {
    int a, b;
    scanf("%d%d", &a, &b);
    if(b == 0) {
      printf("1\n");
      continue;
    }
    memset(v, -1, sizeof v);
    vi = 0;
    base = 1;
    for(int i = 0; i < b; i++) {
      base = (base * a) % 10;
      if(base == v[0]) {
	break;
      }
      v[vi++] = base;
    }
    int idx = (b % vi) - 1;
    if(idx < 0)
      idx += vi;
    printf("%d\n", v[idx]);
  }
  return 0;
}
