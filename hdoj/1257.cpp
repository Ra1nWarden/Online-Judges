#include <cstdio>
#include <cstring>
#include <algorithm>
#define MAXN 100010

using namespace std;

int v[MAXN];
int n;
int lis[MAXN];
int li;

int main() {
  while(~scanf("%d", &n)) {
    for(int i = 0; i < n; i++) {
      scanf("%d", &v[i]);
    }
    li = 0;
    for(int i = 0; i < n; i++) {
      int idx = lower_bound(lis, lis+li, v[i]) - lis;
      lis[idx] = v[i];
      if(idx == li)
	li++;
    }
    printf("%d\n", li);
  }
  return 0;
}
