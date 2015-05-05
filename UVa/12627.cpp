#include <bits/stdc++.h>

using namespace std;

long long c(int k) {
  return k == 0 ? 1 : c(k-1) * 3;
}

long long f(int k, int i) {
  if(i == 0)
    return 0;
  if(k == 0)
    return 1;
  if(i > (1 << (k - 1))) {
    return 2 * c(k-1) + f(k - 1, i - (1 << (k - 1)));
  } else {
    return 2 * f(k - 1, i);
  }
}

int main() {
  int tc;
  scanf("%d", &tc);			       
  int kase = 1;
  while(tc--) {
    int k, a, b;
    scanf("%d %d %d", &k, &a, &b);
    printf("Case %d: %lld\n", kase++, f(k, b) - f(k, a - 1));
  }
  return 0;
}
