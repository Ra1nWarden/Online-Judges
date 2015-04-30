#include <cstdio>
#include <set>
#define MAXN 11
#define FOR_CELL(c, p) for(Polyomino::iterator c = (p).begin(); c != (p).end(); c++)

using namespace std;

int ans[MAXN][MAXN][MAXN];
int dx[] = {-1, 0, 0, 1};
int dy[] = {0, -1, 1, 0};

struct Square {
  int x, y;
  Square() {}
  Square(int x, int y) : x(x), y(y) {}
  bool operator<(const Square& rhs) const {
    if(x != rhs.x)
      return x < rhs.x;
    return y < rhs.y;
  }
};

typedef set<Square> Polyomino;
set<Polyomino> polys[MAXN];

Polyomino normalize(const Polyomino& p) {
  int minx = p.begin()->x, miny = p.begin()->y;
  FOR_CELL(c, p) {
    minx = min(minx, c->x);
    miny = min(miny, c->y);
  }
  Polyomino res;
  FOR_CELL(c, p) {
    res.insert(Square(c->x - minx, c->y - miny));
  }
  return res;
}

Polyomino rotate(const Polyomino& p) {
  Polyomino res;
  FOR_CELL(c, p)
    res.insert(Square(c->y, -(c->x)));
  return normalize(res);
}

Polyomino flip(Polyomino& p) {
  Polyomino res;
  FOR_CELL(c, p)
    res.insert(Square(c->x, -(c->y)));
  return normalize(res);
}

void check_polyomino(const Polyomino& p0, const Square& s) {
  Polyomino p = p0;
  p.insert(s);
  p = normalize(p);
  int n = p.size();
  for(int i = 0; i < 4; i++) {
    if(polys[n].count(p))
      return;
    p = rotate(p);
  }
  p = flip(p);
  for(int i = 0; i < 4; i++) {
    if(polys[n].count(p))
      return;
    p = rotate(p);
  }
  polys[n].insert(p);
}

void generate() {
  Polyomino poly;
  poly.insert(Square(0, 0));
  polys[1].insert(poly);

  for(int n = 2; n < MAXN; n++) {
    for(set<Polyomino>::iterator p = polys[n-1].begin(); p != polys[n-1].end(); p++) {
      FOR_CELL(c, *p) {
	for(int d = 0; d < 4; d++) {
	  Square news(c->x + dx[d], c->y + dy[d]);
	  if(p->count(news) == 0)
	    check_polyomino(*p, news);
	}
      }
    }
  }


  for(int n = 1; n <= 10; n++) {
    for(int w = 1; w <= 10; w++) {
      for(int h = 1; h <= 10; h++) {
	int cnt = 0;
	for(set<Polyomino>::iterator p = polys[n].begin(); p != polys[n].end(); p++) {
	  int maxx = 0, maxy = 0;
	  FOR_CELL(c, *p) {
	    maxx = max(maxx, c->x);
	    maxy = max(maxy, c->y);
	  }
	  if(min(maxx, maxy) < min(h, w) && max(maxx, maxy) < max(h, w))
	    cnt++;
	}
	ans[n][w][h] = cnt;
      }
    }
  }
}

int main() {
  generate();
  int n, w, h;
  while(scanf("%d %d %d", &n, &w, &h) != EOF) {
    printf("%d\n", ans[n][w][h]);
  }
  return 0;
}
