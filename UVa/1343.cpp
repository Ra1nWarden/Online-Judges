#include <cstdio>
#include <algorithm>
#define MAXL 1000

using namespace std;

/*
      00    01
      02    03
04 05 06 07 08 09 10
      11    12
13 14 15 16 17 18 19
      20    21
      22    23
*/

int moves[8][7] = {
  {0, 2, 6, 11, 15, 20, 22}, // A
  {1, 3, 8, 12, 17, 21, 23}, // B
  {10, 9, 8, 7, 6, 5, 4}, // C
  {19, 18, 17, 16, 15, 14, 13} // D
};

int rev[8] = {5, 4, 7, 6, 1, 0, 3, 2};
int square[8] = {6, 7, 8, 11, 12, 15, 16, 17};

char ans[MAXL];
int v[24];
int maxd;

bool ok() {
  for(int i = 0; i < 8; i++) {
    if(v[square[i]] != v[6])
      return false;
  }
  return true;
}

int h() {
  int ans = 10;
  for(int i = 1; i <= 3; i++) {
    int count = 0;
    for(int j = 0; j < 8; j++) {
      if(v[square[j]] != i)
	count++;
    }
    ans = min(ans, count);
  }
  return ans;
}

void move(int i) {
  int tmp = v[moves[i][0]];
  for(int idx = 0; idx < 6; idx++) {
    v[moves[i][idx]] = v[moves[i][idx+1]];
  }
  v[moves[i][6]] = tmp;
}

bool dfs(int d) {
  if(ok()) {
    ans[d] = '\0';
    return true;
  }
  if(h() > maxd - d) {
    return false;
  }
  for(int i = 0; i < 8; i++) {
    char dir = 'A' + i;
    ans[d] = dir;
    move(i);
    if(dfs(d+1))
      return true;
    move(rev[i]);
  }
  return false;
}

int main() {
  for(int i = 4; i < 8; i++) {
    for(int j = 0; j < 7; j ++)
      moves[i][j] = moves[rev[i]][6-j];
  }
  while(scanf("%d", &v[0]) != EOF && v[0]) {
    for(int i = 1; i < 24; i++)
      scanf("%d", &v[i]);
    for(maxd = 0; maxd > -1; maxd++) {
      if(dfs(0))
	break;
    }
    if(maxd == 0) {
      printf("No moves needed\n");
      printf("%d\n", v[6]);
    }
    else {
      printf("%s\n", ans);
      printf("%d\n", v[6]);
    }
  }
  return 0;
}
