#include <cstdio>
#include <cstring>
#define MAXN 10

using namespace std;

int n, m;
bool H[MAXN][MAXN];
bool V[MAXN][MAXN];
int count[MAXN];

int main() {
  int tc = 1;
  while(scanf("%d\n%d", &n, &m) != EOF) {
    if(tc > 1)
      printf("\n**********************************\n\n");
    memset(H, false, sizeof H);
    memset(V, false, sizeof V);
    char dir;
    int x, y;
    for(int i = 0; i < m; i++) {
      scanf("%*[ \t\n]%c %d %d", &dir, &x, &y);
      if(dir == 'H') {
	H[x][y] = true;
      } else {
	V[y][x] = true;
      }
    }
    memset(count, 0, sizeof count);
    bool found = false;
    for(int i = 1; i < n; i++) {
      for(int j = 1; j < n; j++) {
	for(int k = 1; i + k <= n && j + k <= n; k++) {
	  // i, j
	  bool ok = true;
	  for(int l = 0; l < k; l++) {
	    if(!(V[i+l][j] && V[i+l][j+k] && H[i][j+l] && H[i+k][j+l])) {
	      //printf("i = %d j = %d k = %d l = %d\n", i, j, k, l);
	      //printf("%d %d %d %d\n", V[i+l][j], V[i+l][j+k], H[i][j+l], H[i+k][j+l]);
	      ok = false;
	      break;
	    }
	  }
	  if(ok) {
	    //printf("%d %d side is %d\n", i, j, k);
	    found = true;
	    count[k]++;
	  }
	}
      }
    }
    printf("Problem #%d\n\n", tc++);
    if(found) {
      for(int k = 1; k <= n - 1; k++) {
	if(count[k] != 0) {
	  printf("%d square (s) of size %d\n", count[k], k);
	}
      }
    } else {
      printf("No completed squares can be found.\n");
    }
  }
  return 0;
}
