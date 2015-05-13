#include <cstdio>
#define MAXL 105

using namespace std;

char pic[MAXL][MAXL];
int h, w;

int main() {
  while(scanf("%d %d\n", &h, &w) != EOF) {
    for(int i = 0; i < h; i++) {
      scanf("%s\n", pic[i]);
    }
    int cnt = 0;
    bool inside = false;
    for(int i = 0; i < h; i++) {
      for(int j = 0; j < w; j++) {
	if(pic[i][j] == '.') {
	  if(inside)
	    cnt += 2;
	} else {
	  cnt += 1;
	  inside = !inside;
	}
      }
    }
    if(cnt % 2)
      printf("%.1f\n", cnt / 2.0);
    else
      printf("%.0f\n", cnt / 2.0);
  }
  return 0;
}
