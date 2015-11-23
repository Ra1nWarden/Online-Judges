#include <cstdio>
#include <cstring>
#include <cmath>

using namespace std;

const int mod = 76543;

int head[mod], next[mod], hs[mod], id[mod], top;

void insert(int x, int y) {
  int k = x % mod;
  hs[top] = x, id[top] = y, next[top] = head[k], head[k] = top++;
}

int find(int x) {
  int k = x % mod;
  for(int i = head[k]; i != -1; i = next[i]) {
    if(hs[i] == x) {
      return id[i];
    }
  }
  return -1;
}

int log_mod(int a, int b, int n) {
  memset(head, -1, sizeof head);
  top = 1;
  if(b == 1)
    return 0;
  int m = sqrt(n + 0.5);
  long long x = 1, p = 1;
  for(int i = 0; i < m; i++, p = p * a %n) {
    insert(p * b % n, i);
  }
  int j;
  for(long long i = m; i <= n; i += m) {
    if((j = find(x = x * p % n)) != -1) {
      return i - j;
    }
  }
  return -1;
}

int main() {
  int p,b,n;
  while(scanf("%d%d%d", &p, &b, &n) != EOF) {
    int ans = log_mod(b, n, p);
    if(ans == -1)
      printf("no solution\n");
    else
      printf("%d\n", ans);
  }
  return 0;
}
