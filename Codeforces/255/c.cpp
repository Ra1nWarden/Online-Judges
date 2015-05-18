#include <cstdio>
#include <cstring>
#include <algorithm>
#define MAXN 100005

using namespace std;

int v[MAXN];
bool change[MAXN];
bool inc[MAXN];
int f[MAXN];
int b[MAXN];
int n;

int main() {
  scanf("%d", &n);
  for(int i = 0; i < n; i++)
    scanf("%d", &v[i]);
  memset(change, false, sizeof change);
  if(v[0] > v[1])
    change[0] = true;
  if(n > 1 && v[n-1] < v[n-2])
    change[n-1] = true;
  for(int i = 1; i < n - 1; i++) {
    if((!(v[i] > v[i-1] && v[i+1] > v[i])) && v[i+1] > v[i-1] + 1)
      change[i] = true;
  }
  memset(inc, false, sizeof inc);
  for(int i = 0; i < n - 1; i++) {
    if(v[i] < v[i+1])
      inc[i] = true;
  }
  inc[n-1] = true;
  memset(f, 0, sizeof f);
  memset(b, 0, sizeof b);
  int r = 1;
  int maxi = 0;
  for(int i = 0; i < n; i++) {
    f[i] = r;
    maxi = max(maxi, min(r+1, n));
    if(!inc[i]) {
      r = 1;
    } else {
      r++;
    }
  }
  r = 0;
  for(int i = n - 1; i > -1; i--) {
    if(!inc[i]) {
      r = 1;
    } else {
      r++;
    }
    b[i] = r;
  }
  int ans = 0;
  for(int i = 0; i < n; i++) {
    if(change[i]) {
      int next = 1;
      if(i > 0)
	next += f[i-1];
      if(i < n - 1)
	next += b[i+1];
      // printf("i=%d next=%d f[i-1]=%d b[i+1]=%d\n", i, next, f[i-1], b[i+1]);
      ans = max(ans, next);
    }
  }
  printf("%d\n", max(ans, maxi));
  return 0;
}
