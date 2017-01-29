#include <cstdio>
#include <algorithm>

using namespace std;

const int maxn = 500;
char str[maxn+5][maxn+5];
int n, m;
int minx, miny, maxx, maxy;

int main() {
  scanf("%d%d\n", &n, &m);
  minx = n;
  miny = m;
  maxx = -1;
  maxy = -1;
  for(int i = 0; i < n; i++)
    scanf("%s\n", str[i]);
  for(int i = 0; i < n; i++) {
    for(int j = 0; j < m; j++) {
      if(str[i][j] == 'X') {
	minx = min(minx, i);
	miny = min(miny, j);
	maxx = max(maxx, i);
	maxy = max(maxy, j);
      }
    }
  }
  bool ok = true;
  for(int i = minx; i <= maxx; i++) {
    for(int j = miny; j <= maxy; j++) {
      if(str[i][j] != 'X') {
	ok = false;
	break;
      }
    }
    if(!ok)
      break;
  }
  printf("%s\n", ok ? "YES" : "NO");
  return 0;
}
