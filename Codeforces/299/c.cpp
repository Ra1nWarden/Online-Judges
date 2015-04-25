#include <cstdio>

using namespace std;

int a, b, n;
int l, t, m;
long long start;

int solve(int lt, int rt, long long total) {
  if(lt == rt)
    return lt;
  int mid = (lt + rt) / 2 + 1;
  long long sum = (2*start + (long long) (mid - l) * b) * (mid - l + 1) / 2;
  if(sum <= total) {
    return solve(mid, rt, total);
  } else {
    return solve(lt, mid - 1, total);
  }
}

int main() {
  scanf("%d %d %d", &a, &b, &n);
  for(int i =0; i < n; i++) {
    scanf("%d %d %d", &l, &t, &m);
    start = (long long) a + (long long) (l - 1) * b;
    if(start > t) {
      printf("-1\n");
      continue;
    }
    int maxi1 = (t - (int) start) / b + l;
    printf("%d\n", solve(l, maxi1, (long long) m*t));
  }
  return 0;
}
