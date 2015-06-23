#include <cstdio>
#include <cstring>
#include <algorithm>
#define MAXN 505
#define INF 2000000000

using namespace std;

int v[MAXN];
int vc[MAXN];
int iv[MAXN];
int ivc[MAXN];
int n;

int main() {
  while(scanf("%d", &n) != EOF && n) {
    for(int i = 1; i <= n; i++) {
      scanf("%d", &v[i]);
      iv[v[i]] = i;
    }
    int ans = INF;
    for(int i = 1; i <= n; i++) {
      memcpy(vc, v, sizeof v);
      memcpy(ivc, iv, sizeof iv);
      int subres = 0;
      int idx = i;
      for(int j = 1; j <= n; j++) {
	int target = j;
	if(vc[idx] != target) {
	  int swapval = vc[idx];
	  swap(ivc[swapval], ivc[target]);
	  swap(vc[ivc[swapval]], vc[ivc[target]]);
	  subres++;
	}
	idx--;
	if(idx == 0)
	  idx = n;
      }
      memcpy(vc, v, sizeof v);
      memcpy(ivc, iv, sizeof iv);
      ans = min(ans, subres);
      subres = 0;
      idx = i;
      for(int j = 1; j <= n; j++) {
	int target = j;
	if(vc[idx] != target) {
	  int swapval = vc[idx];
	  swap(ivc[swapval], ivc[target]);
	  swap(vc[ivc[swapval]], vc[ivc[target]]);
	  subres++;
	}
	idx++;
	if(idx == n+1)
	  idx = 1;
      }
      ans = min(ans, subres);
    }
    printf("%d\n", ans);
  }
  return 0;
}
