#include <cstdio>
#include <cstring>
#define MAXN 100005

using namespace std;

long long C[MAXN];

int lowbit(int x) {
  return x & (-x);
}

long long sum(int x) {
  long long ret = 0;
  while(x > 0) {
    ret += C[x];
    x -= lowbit(x);
  }
  return ret;
}
void add(int x, long long d) {
  while(x <= MAXN) {
    C[x] += d;
    x += lowbit(x);
  }
}

int main() {
  int tc;
  scanf("%d", &tc);
  for(int et = 0; et < tc; et++) {
    int n, m;
    scanf("%d %d", &n, &m);
    long long x;
    memset(C, 0, sizeof C);
    for(int i = 1; i <= n-1; i++) {
      scanf("%I64d", &x);
      add(i, x);
    }
    for(int i = 0; i < m; i++) {
      int start, end;
      scanf("%d %d", &start, &end);
      int bus = i % n + 1;
      long long res = 0;
      if(start < end) {
	if(bus <= start) {
	  res = sum(end - 1) - sum(bus - 1);
	} else {
	  // bus > start
	  res = 2*sum(n - 1) - sum(bus - 1) + sum(end - 1);
	}
      } else {
	// start > end
	res = 2*sum(n - 1) - sum(bus - 1) - sum(end - 1);
      }
      printf("%I64d\n", res);
    }
  }
  return 0;
}
