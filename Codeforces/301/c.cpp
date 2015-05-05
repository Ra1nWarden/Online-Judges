#include <cstdio>
#include <cstring>
#include <stack>
#define MAXN 505

using namespace std;

int n, m;
int v[MAXN][MAXN];
char buffer[MAXN];
int r1, c1, r2, c2;
int dx[] = {0, 0, -1, 1};
int dy[] = {1, -1, 0, 0};
typedef pair<int, int> Point;

bool dfs(int x, int y) {
  stack<Point> s;
  s.push(make_pair(x, y));
  while(!s.empty()) {
    Point next = s.top();
    s.pop();
    for(int i = 0; i < 4; i++) {
      int newx = next.first + dx[i];
      int newy = next.second + dy[i];
      if(newx > -1 && newx < n && newy > -1 && newy < m) {
	if(newx == r2 && newy == c2 && v[newx][newy] == 0) {
	  return true;
	}
	if(v[newx][newy] > 0) {
	  s.push(make_pair(newx, newy));
	  v[newx][newy] = 0;
	}
      }
    }
  }
  return false;
}

int main() {
  scanf("%d %d\n", &n, &m);
  memset(v, 0, sizeof v);
  for(int i = 0; i < n; i++) {
    scanf("%s", buffer);
    for(int j = 0; j < m; j++) {
      if(buffer[j] == '.')
	v[i][j] = 1;
    }
  }
  scanf("%d %d", &r1, &c1);
  r1--;
  c1--;
  scanf("%d %d", &r2, &c2);
  r2--;
  c2--;
  if(dfs(r1, c1)) {
    printf("YES\n");
  } else {
    printf("NO\n");
  }
  return 0;
}
