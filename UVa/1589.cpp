#include <cstdio>
#include <cstring>
#include <cmath>
#define MAXN 10
#define MAXL 12

using namespace std;

int n, bx, by;

struct Node {
  char t;
  int x, y;
};

Node nodes[MAXN];

int dx[] = {-1,1,0,0};
int dy[] = {0,0,-1,1};
bool occupied[MAXL][MAXL];

int main() {
  while(scanf("%d %d %d\n", &n, &bx, &by) != EOF && (n || bx || by)) {
    memset(occupied, false, sizeof occupied);
    for(int i = 0; i < n; i++) {
      scanf("%c %d %d\n", &nodes[i].t, &nodes[i].x, &nodes[i].y);
      occupied[nodes[i].x][nodes[i].y] = true;
    }
    bool checked = true;
    for(int j = 0; j < 4; j++) {
      bool dead = false;
      int xx = bx + dx[j];
      int yy = by + dy[j];
      if(xx > 0 && xx < 4 && yy > 3 && yy < 7) {
	for(int i = 0; i < n; i++) {
	  Node next = nodes[i];
	  if(next.x == xx && next.y == yy)
	    continue;
	  char kind = next.t;
	  bool killed = false;
	  if(kind == 'G' || kind == 'C' || kind == 'R') {
	    if(next.x != xx && next.y != yy)
	      continue;
	    if(next.y == yy) {
	      int cnt = 0;
	      int diff = (next.x > xx) ? -1 : 1;
	      for(int ii = next.x + diff; abs(ii - xx) >= 1; ii += diff) {
		if(occupied[ii][yy]) {
		  cnt++;
		}
	      }
	      if(kind == 'C') {
		killed = cnt == 1;
	      } else {
		killed = cnt == 0;
	      }
	    } else {
	      int cnt = 0;
	      int diff = (next.y > yy) ? -1 : 1;
	      for(int jj = next.y + diff; abs(jj - yy) >= 1; jj += diff) {
		if(occupied[xx][jj]) {
		  cnt++;
		}
	      }
	      if(kind == 'C') {
		killed = cnt == 1;
	      } else {
		killed = cnt == 0;
	      }
	    }

	  } else if(kind == 'H') {
	    if(next.x == xx+1) {
	      killed = (next.y == yy+2 && !occupied[xx+1][yy+1]) || (next.y == yy-2 && !occupied[xx+1][yy-1]);
	    }
	    if(next.x == xx-1) {
	      killed = (next.y == yy+2 && !occupied[xx-1][yy+1]) || (next.y == yy-2 && !occupied[xx-1][yy-1]);
	    }
	    if(next.y == yy+1) {
	      killed = (next.x == xx+2 && !occupied[xx+1][yy+1]) || (next.x = xx-2 && !occupied[xx-1][yy+1]);
	    }
	    if(next.y == yy-1) {
	      killed = (next.x == xx+2 && !occupied[xx+1][yy-1]) || (next.x == xx-2 && !occupied[xx-1][yy-1]);
	    }
	  }
	  
	  if(killed) {
	    dead = true;
	    break;
	  }
	}
	if(!dead) {
	  checked = false;
	  break;
	}
      }
    }
    if(checked)
      printf("YES\n");
    else
      printf("NO\n");
    
    scanf("\n");
  }
  return 0;
}
