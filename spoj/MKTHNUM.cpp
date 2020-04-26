#include <cstdio>
#include <map>
#include <algorithm>
#include <cstring>

using namespace std;

const int maxn = 100000;
const int sqrtn = 1000;
int pre[maxn/sqrtn+5][maxn+5];
int n, m;
int v[maxn+5];
int vv[maxn+5];
int ra[maxn+5];
map<int, int> pos;

int main() {
  scanf("%d%d", &n, &m);
  for(int i = 1; i <= n; i++) {
    scanf("%d", &v[i]);
    vv[i] = v[i];
    pos[v[i]] = i;
  }
  sort(vv+1, vv+1+n);
  
  for(int i = 1; i <= n; i++)
    ra[i] = pos[vv[i]];

  memset(pre, 0, sizeof pre);
  
  for(int i = 1; i <= n; i++) {
    pre[i/sqrtn][ra[i]]++;
  }

  for(int i = 0; i <= n / sqrtn; i++) {
    for(int j = 1; j <= n; j++) {
      pre[i][j] += pre[i][j-1];
    }
  }

  while(m--) {
    int l, r, k;
    scanf("%d%d%d", &l, &r, &k);
    int i;
    int add = 0;
    for(i = 0; i <= n / sqrtn; i++) {
      if (add + pre[i][r] - pre[i][l-1] >= k) {
	break;
      }
      add += pre[i][r] - pre[i][l-1];
    }

    i *= sqrtn;
    if(i == 0)
      i++;

    for(; i <= n; i++) {
      
      if(ra[i] >= l && ra[i] <= r)
	add++;
      if(add == k) {
	break;
      }
    }
    printf("%d\n", v[ra[i]]);
  }
  
  return 0;
}
