#include <bits/stdc++.h>

using namespace std;

int gcd(int a, int b) {
  return b == 0 ? a : gcd(b, a%b);
}

int main() {
  int n, m;
  scanf("%d %d", &n, &m);
  int f = gcd(n, m);
  bool picked[f];
  memset(picked, false, sizeof picked);
  for(int i = 0; i < 2; i++) {
    int cnt;
    scanf("%d", &cnt);
    for(int j = 0; j < cnt; j++) {
      int x;
      scanf("%d", &x);
      picked[x % f] = true;
    }
  }
  for(int i = 0; i < f; i++) {
    if(!picked[i]) {
      printf("No\n");
      return 0;
    }
  }
  printf("Yes\n");
  return 0;
}
