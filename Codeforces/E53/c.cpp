#include <cstdio>
#include <algorithm>

using namespace std;

const int maxn = 200000;
char v[maxn+5];
int x, y, n;
int uv[maxn+5], rv[maxn+5], dv[maxn+5], lv[maxn+5];
int ui, ri, di, li;

int overlap(int* cv, int ci, int l, int r) {
  int start = lower_bound(cv, cv + ci, l) - cv;
  int end = lower_bound(cv, cv + ci, r) - cv;
  return end - start;
}

bool check(int ans) {
  //printf("check %d\n", ans);
  for(int i = 0; i + ans <= n; i++) {
    int up = ui - overlap(uv, ui, i, i + ans);
    int right = ri - overlap(rv, ri, i, i + ans);
    int down = di - overlap(dv, di, i, i + ans);
    int left = li - overlap(lv, li, i, i + ans);
    int yy = up - down;
    int xx = right - left;
    //printf("i=%d xx=%d yy=%d\n", i, xx, yy);
    if(abs(x - xx) + abs(y - yy) <= ans) {
      return true;
    }
  }
  return false;
}

int main() {
  scanf("%d\n", &n);
  scanf("%s", v);
  scanf("%d %d", &x, &y);
  ui = ri = di = li = 0;
  for(int i = 0; i < n; i++) {
    if(v[i] == 'U') {
      uv[ui++] = i;
    } else if(v[i] == 'R') {
      rv[ri++] = i;
    } else if(v[i] == 'D') {
      dv[di++] = i;
    } else {
      lv[li++] = i;
    }
  }
  int s = abs(x) + abs(y);
  if(s > n || ((n - s) & 1)) {
    printf("-1\n");
    return 0;
  }
  int l = 0, r = n;
  while(l < r) {
    int m = (l + r) >> 1;
    if(check(m)) {
      r = m;
    } else {
      l = m + 1;
    }
  }
  printf("%d\n", l);
  return 0;
}
