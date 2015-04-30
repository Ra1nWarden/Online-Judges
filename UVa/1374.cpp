#include <cstdio>
#include <cstring>
#include <algorithm>
#define MAXN 1001
#define INF 2000000000

using namespace std;

int maxd, target;
int v[MAXN];

bool dfs(int d) {
  if(v[d] == target)
    return true;
  if(d == maxd)
    return false;
  int maxv = v[0];
  for(int i = 1; i <= d; i++)
    maxv = max(maxv, v[i]);
  if((maxv << (maxd - d)) < target)
    return false;
  
  for(int i = d; i >= 0; i--) {
    if(v[d] + v[i] != 0) {
      v[d+1] = v[d] + v[i];
      if(dfs(d+1))
	return true;
    }
    if(v[d] - v[i] != 0) {
      v[d+1] = v[d] - v[i];
      if(dfs(d+1))
	return true;
    }
  }
  return false;
}

int solve() {
  if(target == 1)
    return 0;
  v[0] = 1;
  for(maxd = 1; maxd > -1; maxd++) {
    if(dfs(0))
      return maxd;
  }
  return INF;
}

int main() {  
  int q;
  while(scanf("%d", &target) != EOF && target) {
    printf("%d\n", solve());
  }
  return 0;
}
