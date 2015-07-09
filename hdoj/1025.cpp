#include <algorithm>
#include <cstdio>
#define MAXN 500005

using namespace std;

int n;
int v[MAXN];
int arr[MAXN];

int main() {
  int kase = 1;
  while(scanf("%d", &n) != EOF) {
    for(int i = 1; i <= n; i++) {
      int a, b;
      scanf("%d %d", &a, &b);
      arr[a] = b;
    }
    int ans;
    int end = 0;
    for(int i = 1; i <= n; i++) {
      int b = arr[i];
      if(i == 1) {
	v[end++] = b;
	ans = 1;
      } else {
	int idx = lower_bound(v, v+end, b) - v;
	if(idx == end) {
	  v[end++] = b;
	} else {
	  v[idx] = b;
	}
      }
    }
    printf("Case %d:\n", kase++);
    if(end == 1) {
      printf("My king, at most 1 road can be built.\n");
    } else {
      printf("My king, at most %d roads can be built.\n", end);
    }
    printf("\n");
  }
  return 0;
}
