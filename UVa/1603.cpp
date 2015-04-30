#include <cstdio>
#include <cstring>
#define MAXN 65

using namespace std;

int best, n, m, s;
bool exists[MAXN], contains[MAXN][MAXN];

int size[MAXN]; // sizes of all squares starting from side 1 to side n
int fullsize[MAXN];

int row_match(int x, int y) {
  return (2 * n + 1) * x + y + 1;
}

int col_match(int x, int y) {
  return (2 * n + 1) * x + n + y + 1;
}

int find_square() {
  for(int i = 0; i < s; i++) {
    //printf("size is %d fullsize is %d for i=%d\n", size[i], fullsize[i], i);
    if(size[i] == fullsize[i])
      return i;
  }
  return -1;
}

void dfs(int d) {
  if(d >= best)
    return;
  int k = find_square();
  if(k == -1) {
    best = d;
    return;
  }

  for(int i = 1; i <= 2*n*(n+1); i++)
    if(contains[k][i]) {
      for(int j = 0; j < s; j++) {
	if(contains[j][i])
	  size[j]--;
      }
      dfs(d+1);
      for(int j = 0; j < s; j++) {
	if(contains[j][i])
	  size[j]++;
      }
    }
}


int main() {
  int tc;
  scanf("%d", &tc);
  while(tc--) {
    scanf("%d %d", &n, &m);
    memset(exists, true, sizeof exists);
    while(m--) {
      int x;
      scanf("%d", &x);
      exists[x] = false;
    }
    
    s = 0;
    memset(contains, false, sizeof contains);
    for(int side = 1; side <= n; side++) {
      for(int x = 0; x <= n - side; x++) {
	for(int y = 0; y <= n - side; y++) {
	  size[s] = 0;
	  fullsize[s] = 4 * side;
	  for(int i = 0; i < side; i++) {
	    int a = row_match(x, y+i);
	    int b = row_match(x+side, y+i);
	    int c = col_match(x+i, y);
	    int d = col_match(x+i, y+side);
	    contains[s][a] = true;
	    contains[s][b] = true;
	    contains[s][c] = true;
	    contains[s][d] = true;
	    if(exists[a])
	      size[s]++;
	    if(exists[b])
	      size[s]++;
	    if(exists[c])
	      size[s]++;
	    if(exists[d])
	      size[s]++;
	  }
	  s++;
	}
      }
    }
    
    best = n * n;
    dfs(0);
    printf("%d\n", best);
  }
  return 0;
}
