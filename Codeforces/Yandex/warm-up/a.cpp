#include <cstdio>
#include <cstring>
#define MAXN 1005

using namespace std;

bool isfriend[MAXN][MAXN];
int friendcount[MAXN];

int main() {
  int n, m, k;
  scanf("%d %d %d", &n, &m, &k);
  memset(isfriend, false, sizeof isfriend);
  memset(friendcount, 0, sizeof friendcount);
  for(int i = 1; i <= n; i++) {
    int idx = i+1;
    if(idx > n)
      idx = 1;
    while(friendcount[i] < k) {
      while(isfriend[i][idx] || idx == i) {
	idx++;
	if(idx > n)
	  idx = 1;
      }
      isfriend[i][idx] = isfriend[idx][i] = true;
      friendcount[i]++;
      friendcount[idx]++;
      m--;
      printf("%d %d\n", i, idx);
    }
  }
  int nextx = 1;
  int nexty = 2;
  while(m > 0) {
    if(isfriend[nextx][nexty]) {
      if(nexty == n) {
	nextx++;
	nexty = nextx + 1;
      } else {
	nexty++;
      }
    } else {
      printf("%d %d\n", nextx, nexty);
      isfriend[nextx][nexty] = isfriend[nexty][nextx] = true;
      m--;
    }
  }
  return 0;
}
