#include <cstdio>
#include <algorithm>

using namespace std;

const int maxn = 500000;
char str[maxn+5];
int total[maxn+5];
int n, a, b, t;

int main() {
  scanf("%d%d%d%d\n", &n, &a, &b, &t);
  scanf("%s", str);
  total[0] = str[0] == 'w' ? b + 1 : 1;
  for(int i = 1; i < n; i++) {
    total[i] = str[i] == 'w' ? a + b + 1 : a + 1;
  }
  // for(int i = 0; i < n; i++)
  //   printf("total[%d]=%d\n", i, total[i]);
  int l = 0, r = 0;
  int time = 0, ans = 0;
  for(r = 0; r < n; r++) {
    if(time + total[r] <= t) {
      time += total[r];
    } else {
      break;
    }
  }
  if(r == 0 || r == n) {
    printf("%d\n", r);
    return 0;
  }
  ans = max(ans, r);
  //printf("before loop ans = %d time=%d\n", ans, time);
  r--;
  l = n - 1;
  time += a * r;
  //printf("ans = %d\n", ans);
  while(r > 0) {
    while(time + total[l] <= t) {
      time += total[l];
      l--;
    }
    //printf("l=%d r=%d time=%d\n", l, r, time);
    if(time <= t)
      ans = max(ans, r + n - l);
    time -= total[r];
    time -= a;
    r--;
  }
  while(time + total[l] <= t) {
    time += total[l];
    l--;
  }
  //printf("l=%d r=%d time=%d\n", l, r, time);
  if(time <= t)
    ans = max(ans, r + n - l);
  l++;
  r = 1;
  time += (n - l) * a;
  //printf("ans = %d    time=%d\n", ans, time);
  while(l < n) {
    while(time + total[r] <= t) {
      time += total[r];
      r++;
    }
    //printf("l=%d r=%d time=%d\n", l, r, time);
    if(time <= t) {
      ans = max(ans, r + n - l);
    }
    time -= total[l];
    time -= a;
    l++;
  }
  printf("%d\n", ans);
  return 0;
}
