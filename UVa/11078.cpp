#include <bits/stdc++.h>
#define MAXN 100005
#define INF 2e9

using namespace std;

int n;

int main() {
  int tc;
  scanf("%d", &tc);
  while(tc--) {
    scanf("%d", &n);
    int maxval;
    int res = -INF;
    for(int i = 0; i < n; i++) {
      int num;
      scanf("%d", &num);
      if(i == 0) {
	maxval = num;
      } else {
	res = max(res, maxval - num);
        maxval = max(maxval, num);
      }
    }
    printf("%d\n", res);
  }
  return 0;
}
