#include <cstdio>
#include <cstring>
#include <algorithm>
#define MAXN 20
#define MAXX (1<<17)

using namespace std;

int n;
int P[MAXN];
int cover[MAXX];
int f[MAXX];

int main() {
  int tc = 1;
  while(scanf("%d", &n) != EOF && n) {
    memset(P, 0, sizeof P);
    for(int i = 0; i < n; i++) {
      int nn;
      scanf("%d", &nn);
      P[i] |= (1 << i);
      while(nn--) {
	int neighbor;
	scanf("%d", &neighbor);
	P[i] |= (1 << neighbor);
      }
    }
    memset(cover, 0, sizeof cover);
    for(int i = 0; i < (1 << n); i++) {
      for(int j = 0; j < n; j++) {
	if(i & (1 << j)) {
	  cover[i] |= P[j];
	}
      }
      //printf("cover[%d] = %d\n", i, cover[i]);
    }

    f[0] = 0;
    int ALL = (1 << n) - 1;
    for(int S = 1; S < (1 << n); S++) {
      f[S] = 0;
      for(int S0 = S; S0; S0 = (S0 - 1) & S) {
	if(cover[S0] == ALL)
	  f[S] = max(f[S], 1 + f[S^S0]);
      }
    }

    printf("Case %d: %d\n", tc++, f[ALL]);
  }
  return 0;
}
