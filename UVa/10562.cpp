#include <cstdio>
#include <cctype>
#include <cstring>
#define MAXN 210

using namespace std;

int n;
char buff[MAXN][MAXN];

void dfs(int r, int c) {
  printf("%c(", buff[r][c]);
  if(r+1 < n && buff[r+1][c] == '|') {
    int i = c;
    while(i-1 >= 0 && buff[r+2][i-1] == '-')
      i--;
    while(buff[r+2][i] == '-' && buff[r+3][i] != '\0') {
      if(!isspace(buff[r+3][i]))
	dfs(r+3, i);
      i++;
    }
  }
  printf(")");
}

void solve() {
  n = 0;
  while(true) {
    fgets(buff[n], MAXN, stdin);
    if(buff[n][0] == '#')
      break;
    else
      n++;
  }
  printf("(");
  if(n) {
    for(int i = 0; i < strlen(buff[0]); i++) {
      if(buff[0][i] != ' ') {
	dfs(0, i);
	break;
      }
    }
  }
  printf(")\n");
}

int main() {
  int tc;
  fgets(buff[0], MAXN, stdin);
  sscanf(buff[0], "%d", &tc);
  while(tc--) {
    solve();
  }
  return 0;
}
