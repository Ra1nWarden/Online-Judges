#include <cstdio>
#include <algorithm>

using namespace std;

const int maxn = 100000;
int a[maxn+5];
int b[maxn+5];
int n, k;

bool ok(int num) {
  long long kk = k;
  for(int i = 0; i < n; i++) {
    kk += min((long long)b[i] - a[i] * 1LL * num, 0LL);
    if(kk < 0)
      break;
  }
  return kk >= 0;
}

int main() {
  scanf("%d%d", &n, &k);
  for(int i = 0; i < n; i++) {
    scanf("%d", &a[i]);
  }
  for(int i = 0; i < n; i++) {
    scanf("%d", &b[i]);
  }
  int l = 0, r = 2000000000;
  while(l != r) {
    int m = (((long long)l + (long long)r) >> 1) + 1;
    //printf("m=%d\n", m);
    if(ok(m)) {
      l = m;
    } else {
      r = m - 1;
    }
  }
  printf("%d\n", l);
  return 0;
}
