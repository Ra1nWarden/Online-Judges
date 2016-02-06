#include <cstdio>
#include <cstring>

using namespace std;

const int maxn = 500;
bool adjMat[maxn+5][maxn+5];
int n, m;
int ans[maxn+5];

bool fill(int i, int x) {
  if(ans[i] != -1) {
    return ans[i] == x;
  } else {
    ans[i] = x;
    bool ret = true;
    for(int j = 1; j <= n && ret; j++) {
      if(j == i)
	continue;
      if(!adjMat[i][j]) {
	ret = fill(j, !x);
      } else {
	if(ans[j] != -1 && ans[j] == !x)
	  ret = false;
      }
    }
    return ret;
  }
}

int main() {
  memset(adjMat, false, sizeof adjMat);
  memset(ans, -1, sizeof ans);
  scanf("%d%d", &n, &m);
  for(int i = 0; i < m; i++) {
     int a, b;
     scanf("%d%d", &a, &b);
     adjMat[a][b] = adjMat[b][a] = true;
  }
  bool ok = true;
  for(int i = 1; i <= n && ok; i++) {
    if(ans[i] != -1)
      continue;
    bool all = true;
    for(int j = 1; j <= n; j++) {
      if(j == i)
	continue;
      if(!adjMat[i][j]) {
	all = false;
	break;
      }
    }
    if(all)
      ans[i] = 2;
    else
      ok = fill(i, 0);
  }

  if(ok) {
    printf("Yes\n");
    for(int i = 1; i <= n; i++) {
      if(ans[i] == 2)
	printf("b");
      else
	printf("%c", ans[i] ? 'a' : 'c');
    }
    printf("\n");
  } else {
    printf("No\n");
  }
  return 0;
}
