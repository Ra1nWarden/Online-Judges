#include <cstdio>
#include <cmath>
#include <iostream>
#define MAXN 105
#define INF 2e9

using namespace std;

int v[MAXN];

int main() {
  int n, k;
  scanf("%d %d", &n, &k);
  int minv = INF;
  int maxv = -1;
  for(int i = 0; i < n; i++) {
    scanf("%d", &v[i]);
    minv = min(minv, v[i]);
    maxv = max(maxv, v[i]);
  }
  bool legal = true;
  for(int i = 1; i <= k; i++) {
    int minc = minv / k + (minv % k >= i ? 1 : 0);
    int maxc = maxv / k + (maxv % k >= i ? 1 : 0);
    if(abs(minc - maxc) > 1) {
      legal = false;
      break;
    }
  }
  if(!legal)
    printf("NO\n");
  else {
    printf("YES\n");
    for(int i= 0; i < n; i++) {
      for(int j = 1; j <= v[i]; j++) {
	if(j != 1)
	  printf(" ");
	printf("%d", (j-1) % k + 1);
      }
      printf("\n");
    }
  }
  return 0;
}
