#include <bits/stdc++.h>

using namespace std;

int main() {
  int n, k, p, x, y;
  scanf("%d %d %d %d %d", &n, &k, &p, &x, &y);
  int n1 = 0;
  int n2 = 0;
  int n3 = 0;
  for(int i = 0; i < k; i++) {
    int m;
    scanf("%d", &m);
    if(m < y)
      n1++;
    else if(m == y)
      n2++;
    else
      n3++;
    x -= m;
  }
  int half = n /2 ;
  if(n1 > half) {
    printf("-1\n");
    return 0;
  }
  int mid = 0;
  int one = 0;
  if(n2 + n3 < half + 1) {
    int diff = (half + 1) - (n2 + n3);
    x -= (diff * y);
    n2 += diff;
    mid += diff;
  }
  if(mid < n - k) {
    one = n - k - mid;
    x -= n - k - mid;
  }

  if(x >= 0) {
    for(int i = 0; i < n - k; i++) {
      if(i > 0)
	printf(" ");
      if(i < mid)
	printf("%d", y);
      else
	printf("1");
    }
    printf("\n");
  } else {
    printf("-1\n");
  }
  return 0;
}
