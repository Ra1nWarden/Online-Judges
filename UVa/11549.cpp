#include <bits/stdc++.h>

using namespace std;

int n, k;

int next(int num) {
  long long product = (long long) num * num;
  int buffer[30];
  int index = 0;
  long long p = product;
  while(p > 0) {
    buffer[index++] = p % 10;
    p /= 10;
  }
  if(index <= n)
    return (int) product;
  else {
    int ans = 0;
    for(int i = index - 1; i >= index - n; i--)
      ans = ans * 10 + buffer[i];
    return ans;
  }
}

int main() {
  int tc;
  scanf("%d", &tc);
  while(tc--) {
    scanf("%d %d", &n, &k);
    int tortoise = k;
    int hare = k;
    int ans = k;
    do {
      tortoise = next(tortoise);
      hare = next(hare);
      ans = max(ans, hare);
      hare = next(hare);
      ans = max(ans, hare);
    } while(tortoise != hare);
    printf("%d\n", ans);
  }
  return 0;
}
