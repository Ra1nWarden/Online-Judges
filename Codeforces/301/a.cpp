#include <bits/stdc++.h>
#define MAXN 1005

using namespace std;

char orig[MAXN];
char target[MAXN];

int main() {
  int n;
  scanf("%d\n", &n);
  scanf("%s\n", orig);
  scanf("%s\n", target);
  int ans = 0;
  for(int i = 0; i < n; i++) {
    int a = orig[i] - '0';
    int b = target[i] - '0';
    ans += min(abs(a - b), 10 - abs(a - b));
  }
  printf("%d\n", ans);
  return 0;
}
