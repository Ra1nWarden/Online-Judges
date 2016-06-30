#include <cstdio>
#include <algorithm>

using namespace std;

typedef unsigned long long LL;
LL v[3000];
int vi;

void init() {
  vi = 0;
  v[vi++] = 0LL;
  for(int len = 2; len <= 64; len++) {
    LL full = (1ULL << (len - 1)) | ((1ULL << (len - 1)) - 1);
    for(int idx = len - 2; idx >= 0; idx--) {
      LL num = full ^ (1ULL << idx);
      v[vi++] = num;
    }
  }
  sort(v, v+vi);
}

int f(long long num) {  
  int ans = lower_bound(v, v+vi, num) - v;
  if(v[ans] == num)
    ans++;
  return ans;
}

int main() {
  init();
  long long a, b;
  scanf("%I64d %I64d\n", &a, &b);
  printf("%d\n", f(b) - f(a-1));
  return 0;
}
