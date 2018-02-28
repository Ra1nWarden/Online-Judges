#include <cstdio>
#include <algorithm>

using namespace std;

int v[2][3];
const int inf = 2000000000;

int main() {
  int tc = 1;
  int m;
  while(scanf("%d", &m)) {
    if(!m)
      break;
    for(int i = 0; i < m; i++) {
      int cur = i&1;
      scanf("%d%d%d", &v[cur][0], &v[cur][1], &v[cur][2]);
      if(i == 0) {
	v[cur][0] = inf;
	v[cur][2] = v[cur][1] + v[cur][2];
      } else {
	v[cur][0] += min(v[cur^1][0], v[cur^1][1]);
	v[cur][1] += min(min(v[cur][0], v[cur^1][0]), min(v[cur^1][1], v[cur^1][2]));
	v[cur][2] += min(v[cur][1], min(v[cur^1][1], v[cur^1][2]));
      }
    }
    printf("%d. %d\n", tc++, v[(m-1)&1][1]);
  }
  return 0;
}
