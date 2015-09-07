#include <cstdio>
#define MAXN 11

using namespace std;

char view[6][MAXN][MAXN];
char pos[MAXN][MAXN][MAXN];
int n;

char read_char() {
  char ch;
  while(true) {
    ch = getchar();
    if((ch >= 'A' && ch <= 'Z') || ch == '.') {
      return ch;
    }
  }
}

void get(int i, int j, int k, int d, int& x, int& y, int& z) {
  switch(i) {
  case 0:
    x = d; y = k; z = j;
    break;
  case 1:
    x = n - 1 - k; y = d; z = j;
    break;
  case 2:
    x = n - 1 - d; y = n - 1 - k; z = j;
    break;
  case 3:
    x = k; y = n - 1 - d; z = j;
    break;
  case 4:
    x = n - 1 - j; y = k; z = d;
    break;
  case 5:
    x = j; y = k; z = n - 1 - d;
    break;
  }
}

int main() {
  while(~scanf("%d", &n) && n) {
    for(int j = 0; j < n; j++) {
      for(int i = 0; i < 6; i++) {
	for(int k = 0; k < n; k++) {
	  view[i][j][k] = read_char();
	}
      }
    }
    for(int i = 0; i < n; i++) {
      for(int j = 0; j < n; j++) {
	for(int k = 0; k < n; k++) {
	  pos[i][j][k] = '#';
	}
      }
    }
    for(int i = 0; i < 6; i++) {
      for(int j = 0; j < n; j++) {
	for(int k = 0; k < n; k++) {
	  if(view[i][j][k] == '.') {
	    for(int d = 0; d < n; d++) {
	      int x, y, z;
	      get(i, j, k, d, x, y, z);
	      pos[x][y][z] = '.';
	    }
	  }
	}
      }
    }

    while(true) {
      bool done = true;
      for(int i = 0; i < 6; i++) {
	for(int j = 0; j < n; j++) {
	  for(int k = 0; k < n; k++) {
	    if(view[i][j][k] != '.') {
	      for(int d = 0; d < n; d++) {
		int x, y, z;
		get(i, j, k, d, x, y, z);
		if(pos[x][y][z] == '.')
		  continue;
		if(pos[x][y][z] == '#') {
		  pos[x][y][z] = view[i][j][k];
		  break;
		}
		if(pos[x][y][z] == view[i][j][k])
		  break;
		pos[x][y][z] = '.';
		done = false;
	      }
	    }
	  }
	}
      }
      if(done)
	break;
    }

    int ans = 0;
    for(int i = 0; i < n; i++) {
      for(int j = 0; j < n; j++) {
	for(int k = 0; k < n; k++) {
	  if(pos[i][j][k] != '.')
	    ans++;
	}
      }
    }

    printf("Maximum weight: %d gram(s)\n", ans);
    
  }
  return 0;
}
