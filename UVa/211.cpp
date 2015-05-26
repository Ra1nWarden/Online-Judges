#include <cstdio>
#include <map>
#include <cstring>

using namespace std;

typedef pair<int, int> II;
map<II, int> memo;
bool used[30];
bool occupied[7][8];
int v[7][8];
int ans[7][8];
int cnt;

bool read_input() {
  for(int i = 0; i < 7; i++) {
    for(int j = 0; j < 8; j++) {
      if(scanf("%d", &v[i][j]) == EOF)
	return false;
    }
  }
  return true;
}

bool solve(int i, int j) {
  if(i == 7) {
    printf("\n");
    for(int ii = 0; ii < 7; ii++) {
      for(int jj = 0; jj < 8; jj++) {
	printf("%4d", ans[ii][jj]);
      }
      printf("\n");
    }
    cnt++;
    return true;
  }
  if(occupied[i][j]) {
    if(j < 7)
      return solve(i, j+1);
    else
      return solve(i+1, 0);
  }
  bool ok = false;
  if(j < 7 && !occupied[i][j+1]) {
    II possible = make_pair(min(v[i][j], v[i][j+1]), max(v[i][j], v[i][j+1]));
    int bone = memo[possible]; 
    if(!used[bone]) {
      used[bone] = true;
      occupied[i][j] = occupied[i][j+1] = true;
      int prev1 = ans[i][j];
      int prev2 = ans[i][j+1];
      ans[i][j] = ans[i][j+1] = bone;
      ok = solve(i, j+1) || ok;
      ans[i][j] = prev1;
      ans[i][j+1] = prev2;
      occupied[i][j] = occupied[i][j+1] = false;
      used[bone] = false;
    }
  }
  if(i < 6 && !occupied[i+1][j]) {
    II possible = make_pair(min(v[i][j], v[i+1][j]), max(v[i][j], v[i+1][j]));
    int bone = memo[possible]; 
    if(!used[bone]) {
      used[bone] = true;
      occupied[i][j] = occupied[i+1][j] = true;
      int prev1 = ans[i][j];
      int prev2 = ans[i+1][j];
      ans[i][j] = ans[i+1][j] = bone;
      if(j < 7)
	ok = solve(i, j+1) || ok;
      else
	ok = solve(i+1, 0) || ok;
      ans[i][j] = prev1;
      ans[i+1][j] = prev2;
      occupied[i][j] = occupied[i+1][j] = false;
      used[bone] = false;
    }
  }
  return ok;
}

int main() {
  int num = 1;
  for(int i = 0; i < 7; i++) {
    for(int j = i; j < 7; j++) {
      memo[make_pair(i, j)] = num++;
    }
  }
  int kase = 1;
  while(read_input()) {
    if(kase > 1)
      printf("\n\n\n\n\n");
    printf("Layout #%d:\n\n\n", kase);
    for(int i = 0; i < 7; i++) {
      for(int j = 0; j < 8; j++) {
	printf("%4d", v[i][j]);
      }
      printf("\n");
    }
    printf("\nMaps resulting from layout #%d are:\n\n", kase);
    cnt = 0;
    memset(used, false, sizeof used);
    memset(occupied, false, sizeof occupied);
    memset(ans, 0, sizeof ans);
    solve(0, 0);
    printf("\nThere are %d solution(s) for layout #%d.\n", cnt, kase++);
  }
  return 0;
}
