#include <cstring>
#include <cstdio>
#define MAXN 35

using namespace std;

int fm[MAXN], gm[MAXN];

int g(int n);

int f(int n) {
  if(fm[n] != -1)
    return fm[n];
  if(n < 3)
    return fm[n] = 0;
  int ans = 0;
  // first three blocks of U is i, i+1, i+2
  for(int i = 0; i <= n - 3; i++) {
    int add = (1 << (n - 1 - (i + 2))); 
    if(i > 1)
      add *= g(i-1);
    //printf("i=%d n=%d add=%d\n", i, n, add);
    ans += add;
  }
  return fm[n] = ans;
}

int g(int n) {
  if(gm[n] != -1)
    return gm[n];
  return gm[n] = (1 << n) - f(n);
}

int main() {
  int n;
  memset(fm, -1, sizeof fm);
  memset(gm, -1, sizeof gm);
  while(scanf("%d", &n) != EOF && n)
    printf("%d\n", f(n));
  return 0;
}
