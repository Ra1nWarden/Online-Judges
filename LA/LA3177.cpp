#include <bits/stdc++.h>
#define MAXN 100005

using namespace std;

int n;
int v[MAXN], l[MAXN], r[MAXN];

bool ok(int num) {
  int x = v[0];
  int y = num - v[0];
  l[0] = x;
  r[0] = 0;
  for(int i = 1; i < n; i++) {
    if(i % 2 == 0) {
      r[i] = min(y - r[i-1], v[i]);
      l[i] = v[i] - r[i];
    } else {
      l[i] = min(x - l[i-1], v[i]);
      r[i] = v[i] - l[i];
    }
  }
  return l[n-1] == 0;
}

int main() {
  while(scanf("%d", &n) != EOF && n) {
    int maxval = 0;
    for(int i = 0; i < n; i++) {
      scanf("%d", &v[i]);
      maxval = max(maxval, v[i]);
    }
    if(n == 1) {
      printf("%d\n", v[0]);
      continue;
    }
    int res = 0;
    for(int i = 0; i < n; i++) {
      res = max(res, v[i] + v[(i+1)%n]);
    }
    if(n % 2 == 1) {
      int start = res;
      int end = maxval * 3;
      while(start < end) {
	int mid = (start + end) / 2;
	if(ok(mid)) {
	  end = mid;
	} else {
	  start = mid+1;
	}
      }
      res = start;
    }
    printf("%d\n", res);
  }
  return 0;
}
