#include <cstdio>
#include <cstring>
#include <cmath>

using namespace std;

int dx[8] = {0, 1, 1, 1, 0, -1, -1, -1};
int dy[8] = {1, 1, 0, -1, -1, -1, 0, 1};
int cd[8];
char ct[8];
int n, x, y;

bool check(char t, int dir) {
  if(t == 'Q')
    return true;
  else if(t == 'R')
    return !(dir & 1);
  else if(t == 'B')
    return dir & 1;
  else
    return false;
}

int main() {
  scanf("%d\n%d%d\n", &n, &x, &y);
  memset(cd, -1, sizeof cd);
  memset(ct, 0, sizeof ct);
  for(int i = 0; i < n; i++) {
    char ch;
    int a, b;
    scanf("%c %d %d\n", &ch, &a, &b);
    int da = a - x;
    int db = b - y;
    bool found = false;
    int dd;
    int j;
    for(j = 0; j < 8; j++) {
      if(dx[j] * da < 0 || dy[j] * db < 0)
	continue;
      if(dx[j] == 0) {
	found = db / dy[j] * dx[j] == da;
	dd = db / dy[j];
      } else {
	found = da / dx[j] * dy[j] == db;
	dd = da / dx[j];
      }
      if(found)
	break;
    }
    if(!found)
      continue;
    if(cd[j] == -1 || dd < cd[j]) {
      cd[j] = dd;
      ct[j] = ch;
    }
  }
  bool ok = false;
  for(int i = 0; i < 8; i++) {
    if(check(ct[i], i)) {
      ok = true;
      break;
    }
  }
  printf("%s\n", ok ? "YES" : "NO");
  return 0;
}
