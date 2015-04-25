#include <cstdio>
#include <cstring>
#define MAXN 1030
#define MAXL 32

using namespace std;

char str[MAXN];
bool buf[MAXL][MAXL];
int cnt;

void draw(int& p, int x, int y, int w) {
  char ch = str[p++];
  if(ch == 'p') {
    draw(p, x , y + w/2, w/2);
    draw(p, x, y, w/2);
    draw(p, x + w/2, y, w/2);
    draw(p, x + w/2, y + w/2, w/2);
  } else if(ch == 'f') {
    for(int i = x; i < x + w; i++) {
      for(int j= y; j < y + w; j++) {
	if(!buf[i][j]) {
	  buf[i][j] = true;
	  cnt++;
	}
      }
    }
  }
}

int main() {
  int tc;
  scanf("%d\n", &tc);
  while(tc--) {
    memset(buf, false, sizeof buf);
    cnt = 0;
    for(int i = 0; i < 2; i++) {
      scanf("%s\n", str);
      int idx = 0;
      draw(idx, 0, 0, 32);
    }
    printf("There are %d black pixels.\n", cnt);
  }
  return 0;
}
