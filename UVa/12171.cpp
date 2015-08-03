#include <cstdio>
#include <queue>
#include <algorithm>
#include <cstring>
#define MAXN 55
#define MAXC 1001

using namespace std;

int x0[MAXN], y0[MAXN], z0[MAXN], x1[MAXN], y1[MAXN], z1[MAXN];
int n;
int xd[MAXN*2], yd[MAXN*2], zd[MAXN*2];
int xn, yn, zn;
int color[MAXN*2][MAXN*2][MAXN*2];

int dx[] = {1,-1,0,0,0,0};
int dy[] = {0,0,1,-1,0,0};
int dz[] = {0,0,0,0,1,-1};

struct Cell {
  int x, y, z;
  Cell(int x = 0, int y = 0, int z = 0) : x(x), y(y), z(z) {}
  int volume() {
    return (xd[x+1] - xd[x]) * (yd[y+1] - yd[y]) * (zd[z+1] - zd[z]);
  }
  bool valid() {
    return x > -1 && x < xn-1 && y > -1 && y < yn-1 && z > -1 && z < zn-1;
  }
  Cell neighbor(int dir) {
    return Cell(x+dx[dir], y+dy[dir], z+dz[dir]);
  }
  void setVisited() {
    color[x][y][z] = 2;
  }
  bool isVisited() {
    return color[x][y][z] == 2;
  }
  bool solid() {
    return color[x][y][z] == 1;
  }
  int area(int dir) {
    if(dx[dir] != 0) {
      return (yd[y+1] - yd[y]) * (zd[z+1] - zd[z]);
    } else if(dy[dir] != 0) {
      return (zd[z+1] - zd[z]) * (xd[x+1] - xd[x]);
    } else {
      return (xd[x+1] - xd[x]) * (yd[y+1] - yd[y]);
    }
  }
};

void discretize(int* x, int& n) {
  sort(x, x+n);
  n = unique(x, x+n) - x;
}

int main() {
  int tc;
  scanf("%d", &tc);
  while(tc--) {
    scanf("%d", &n);
    xd[0] = yd[0] = zd[0] = 0;
    xd[1] = yd[1] = zd[1] = MAXC;
    xn = yn = zn = 2;
    for(int i = 0; i < n; i++) {
      scanf("%d %d %d %d %d %d", &x0[i], &y0[i], &z0[i], &x1[i], &y1[i], &z1[i]);
      x1[i] += x0[i];
      y1[i] += y0[i];
      z1[i] += z0[i];
      xd[xn++] = x0[i];
      xd[xn++] = x1[i];
      yd[yn++] = y0[i];
      yd[yn++] = y1[i];
      zd[zn++] = z0[i];
      zd[zn++] = z1[i];
    }
    discretize(xd, xn);
    discretize(yd, yn);
    discretize(zd, zn);
    memset(color, 0, sizeof color);
    for(int i = 0; i < n; i++) {
      int xs = find(xd, xd+xn, x0[i]) - xd;
      int xe = find(xd, xd+xn, x1[i]) - xd;
      int ys = find(yd, yd+yn, y0[i]) - yd;
      int ye = find(yd, yd+yn, y1[i]) - yd;
      int zs = find(zd, zd+zn, z0[i]) - zd;
      int ze = find(zd, zd+zn, z1[i]) - zd;
      for(int ii = xs; ii < xe; ii++) {
	for(int jj = ys; jj < ye; jj++) {
	  for(int kk = zs; kk < ze; kk++) {
	    color[ii][jj][kk] = 1;
	  }
	}
      }
    }
    int vol = 0;
    int s = 0;
    Cell node;
    node.setVisited();
    queue<Cell> q;
    q.push(node);
    while(!q.empty()) {
      Cell u = q.front();
      q.pop();
      vol += u.volume();
      for(int i = 0; i < 6; i++) {
	Cell v = u.neighbor(i);
	if(!v.valid())
	  continue;
	if(v.solid()) {
	  s += u.area(i);
	} else {
	  if(!v.isVisited()) {
	    v.setVisited();
	    q.push(v);
	  }
	}
      }
    }
    vol = MAXC * MAXC * MAXC - vol;
    printf("%d %d\n", s, vol);
  }
  return 0;
}
