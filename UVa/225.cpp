#include <bits/stdc++.h>
#define MAXL 25

using namespace std;

int l;
int counter;
char ans[MAXL];
bool visited[3000][3000];

int dx[] = {-1, 0, 0, 1};
int dy[] = {0, -1, 1, 0};
char dir[] = "wsne";
int basex = 1500;
int basey = 1500;

bool opposite(int i, int j) {
  if(i == -1)
    return false;
  switch(i) {
  case 0:
    return j == 3;
    break;
  case 1:
    return j == 2;
    break;
  case 2:
    return j == 1;
    break;
  default:
    return j == 0;
  }
}

void dfs(int x, int y, int prev, int prev_d) {
  if(prev == l) {
    if(x == 0 && y == 0) {
      counter++;
      ans[prev] = '\0';
      printf("%s\n", ans);
    }
    return;
  }
  for(int i = 0; i < 4; i++) {
    if(i == prev_d || opposite(i, prev_d))
      continue;
    int newx = x + (prev + 1) * dx[i];
    int newy = y + (prev + 1) * dy[i];
    if(visited[basex+newx][basey+newy]) {
      if(!(newx == 0 && newy == 0))
	continue;
    }
    bool ok = true;
    if(i == 0) {
      for(int xx = x - 1; xx > newx; xx--) {
	if(visited[basex + xx][basey + newy]) {
	  ok = false;
	  break;
	}
      }
    } else if(i == 1) {
      for(int yy = y - 1; yy > newy; yy--) {
	if(visited[basex + newx][basey + yy]) {
	  ok = false;
	  break;
	}
      }
    } else if(i == 2) {
      for(int yy = y + 1; yy < newy; yy++) {
	if(visited[basex + newx][basey + yy]) {
	  ok = false;
	  break;
	}
      }
    } else {
      for(int xx = x + 1; xx < newx; xx++) {
	if(visited[basex + xx][basey + newy]) {
	  ok = false;
	  break;
	}
      }
    }
    if(ok) {
      ans[prev] = dir[i];
      visited[basex+newx][basey+newy] = true;
      dfs(newx, newy, prev+1, i);
      visited[basex+newx][basey+newy] = false;
    }
  }
}

int main() {
  int tc;
  scanf("%d", &tc);
  while(tc--) {
    scanf("%d", &l);
    int cnt;
    scanf("%d", &cnt);
    memset(visited, false, sizeof visited);
    while(cnt--) {
      int x, y;
      scanf("%d %d", &x, &y);
      visited[basex+x][basey+y] = true;
    }
    counter = 0;
    visited[basex][basey] = true;
    dfs(0, 0, 0, -1);
    printf("Found %d golygon(s).\n\n", counter);
  }
  return 0;
}
