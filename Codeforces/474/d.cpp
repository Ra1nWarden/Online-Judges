#include <cstdio>
#include <cstring>

using namespace std;

const int maxn = 64;
long long t1[maxn+5];
long long t2[maxn+5];
long long base[maxn+5];

int len(long long n) {
  int ans = 0;
  for(int len = 0; len < 63; len++) {
    if((1LL << len) & n) {
      ans = len + 1;
    }
  }
  return ans;
}

long long parent(long long x) {
  //printf("parent(%I64d)\n", x);
  int idx = len(x);
  long long shift = t1[idx] + t2[idx];
  shift %= base[idx];
  //printf("idx=%d shift=%I64d\n", idx, shift);
  if(shift < 0)
    shift += base[idx];
  long long new_base = ((x - base[idx] + shift) % base[idx]) + base[idx];

  new_base >>= 1;

  //printf("new_base=%I64d\n", new_base);
  long long shift_p = t1[idx-1];
  if(shift_p < 0)
    shift_p += base[idx-1];
  new_base = new_base - base[idx-1] - shift_p;
  if(new_base < base[idx-1])
    new_base += base[idx-1];
  new_base %= base[idx-1];
  return base[idx-1] + new_base;
}

int main() {
  int q;
  scanf("%d", &q);
  memset(t1, 0, sizeof t1);
  memset(t2, 0, sizeof t2);
  for(int i = 1; i < maxn; i++) {
    base[i] = 1LL << (i - 1);
  }
  while(q--) {
    int t;
    scanf("%d", &t);
    if(t == 1) {
      long long x, k;
      scanf("%I64d %I64d", &x, &k);
      int bits = len(x);
      t1[bits] += k;
      t1[bits] %= base[bits];
    } else if(t == 2) {
      long long x, k;
      scanf("%I64d %I64d", &x, &k);
      int bits = len(x);
      t2[bits] += k;
      t2[bits] %= base[bits];
    } else {
      long long x;
      scanf("%I64d", &x);
      while(x != 1LL) {
	printf("%I64d ", x);
	x = parent(x);
      }
      printf("1\n");
    }
  }
  return 0;
}
