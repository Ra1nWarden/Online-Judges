#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#define MAXN 10010

using namespace std;

int v[MAXN];
int n;

int main() {
  bool init = true;
  while(scanf("%d", &n) && n) {
    if(!init)
      printf("\n");
    for(int i = 0; i < n; i++)
      scanf("%d", &v[i]);
    sort(v, v+n);
    int ans = 0;
    int cur_size = 1;
    for(int i = 1; i < n; i++) {
      if(v[i] != v[i-1]) {
	ans = max(ans, cur_size);
	cur_size = 1;
      } else {
	cur_size++;
      }
    }
    ans = max(ans, cur_size);
    printf("%d\n", ans);
    for(int i = 0; i < ans; i++) {
      for(int j = i; j < n; j+=ans) {
	if(j != i)
	  printf(" ");
	printf("%d", v[j]);
      }
      printf("\n");
    }
    init = false;
  }
  return 0;
}
