#include <cstdio>
#include <cstring>
#include <algorithm>
#define MAXN 101

using namespace std;

char str[MAXN];
bool v[MAXN][MAXN];
int n, m;

int main() {
  while(scanf("%d %d", &n, &m) != EOF && (n != 0 && m != 0)) {
    memset(v, false, sizeof v);
    for(int i = 0; i < n; i++) {
      scanf("%*[ \t\n]%s", str);
      for(int j = 0; j < m; j++) {
	if(str[j] == '1')
	  v[i][j] = true;
      }
    }
    int res = 0;
    for(int i = 0; i < n; i++) {
      for(int j = 0; j < m; j++) {
	if(!v[i][j])
	  continue;
	int mincol = m;
	for(int k = i; k < n; k++) {
	  if(!v[k][j])
	    break;
	  for(int l = j; l < mincol; l++) {
	    if(!v[k][l]) {
	      mincol = min(mincol, l);
	      break;
	    }
	    bool ok = true;
	    if(k - 1 >= i)
	      ok = v[k-1][l];
	    if(!ok)
	      break;
	    if(l - 1 >= j)
	      ok = v[k][l-1];
	    if(!ok)
	      break;
	    res++;
	  }
	}
      }
    }
    printf("%d\n", res);
  }
  return 0;
}
