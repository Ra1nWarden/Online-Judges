#include <cstdio>
#include <algorithm>
#include <cstring>
#define MAXL 75
#define INF 2000000000

using namespace std;

char str[MAXL];
int dp[MAXL][4][4][3];
char dps[MAXL][4][4][3];

// 0 up
// 1 left
// 2 right
// 3 down
int up = 0;
int left = 1;
int right = 2;
int down = 3;

// 0 not moved
// 1 left moved
// 2 right moved

int f(int n, int l, int r, int prev) {
  if(dp[n][l][r][prev] != -1)
    return dp[n][l][r][prev];
  char next = str[n];
  int lcost = INF;
  int rcost = INF;
  int staycost = INF;
  if(next == 'L') {
    if(l == up || l == down) {
      int cost = f(n+1, l, left, 2);
      if(r == up || r == down) {
	if(prev == 0 || prev == 1)
	  cost += 1;
	else
	  cost += 5;
      } else if(r == left) {
	if(prev == 0 || prev == 1)
	  cost += 1;
	else
	  cost += 3;
      } else {
	if(prev == 0 || prev == 1)
	  cost += 1;
	else
	  cost += 7;
      }
      rcost = min(rcost, cost);
      if(r != left) {
	cost = f(n+1, left, r, 1);
	if(prev == 0 || prev == 2)
	  cost += 1;
	else
	  cost += 5;
	lcost = min(lcost, cost);
      }
    } else if(l == left) {
      int cost = f(n+1, l, r, 1);
      if(prev == 0 || prev == 2)
	cost += 1;
      else
	cost += 3;
      lcost = min(lcost, cost);
    } else {
      int cost = f(n+1, left, r, 1);
      if(prev == 0 || prev == 2)
	cost += 1;
      else
	cost += 7;
      lcost = min(lcost, cost);
    }
  } else if(next == 'R') {
     if(r == up || r == down) {
      int cost = f(n+1, right, r, 1);
      if(l == up || l == down) {
	if(prev == 0 || prev == 2)
	  cost += 1;
	else
	  cost += 5;
      } else if(l == right) {
	if(prev == 0 || prev == 2)
	  cost += 1;
	else
	  cost += 3;
      } else {
	if(prev == 0 || prev == 2)
	  cost += 1;
	else
	  cost += 7;
      }
      lcost = min(lcost, cost);
      if(l != right) {
	cost = f(n+1, l, right, 2);
	if(prev == 0 || prev == 1)
	  cost += 1;
	else
	  cost += 5;
	rcost = min(rcost, cost);
      }
    } else if(r == right) {
      int cost = f(n+1, l, r, 2);
      if(prev == 0 || prev == 1)
	cost += 1;
      else
	cost += 3;
      rcost = min(rcost, cost);
    } else {
      int cost = f(n+1, l, right, 2);
      if(prev == 0 || prev == 1)
	cost += 1;
      else
	cost += 7;
      rcost = min(rcost, cost);
    }
  } else if(next == 'D') {
    if(l == down) {
      int cost = f(n+1, l, r, 1);
      if(prev == 0 || prev == 2)
	cost += 1;
      else
	cost += 3;
      lcost = min(lcost, cost);
    } else if(r == down) {
      int cost = f(n+1, l, r, 2);
      if(prev == 0 || prev == 1)
	cost += 1;
      else
	cost += 3;
      rcost = min(rcost, cost);
    } else {
      // move left
      int cost = f(n+1, down, r, 1);
      if(l == up) {
	if(prev == 0 || prev == 2)
	  cost += 1;
	else
	  cost += 7;
      } else {
	if(prev == 0 || prev == 2)
	  cost += 1;
	else
	  cost += 5;
      }
      lcost = min(lcost, cost);
      // move right
      cost = f(n+1, l, down, 2);
      if(r == up) {
	if(prev == 0 || prev == 1)
	  cost += 1;
	else
	  cost += 7;
      } else {
	if(prev == 0 || prev == 1)
	  cost += 1;
	else
	  cost += 5;
      }
      rcost = min(rcost, cost);
    }
  } else if(next == 'U') {
    if(l == up) {
      int cost = f(n+1, l, r, 1);
      if(prev == 0 || prev == 2)
	cost += 1;
      else
	cost += 3;
      lcost = min(lcost, cost);
    } else if(r == up) {
      int cost = f(n+1, l, r, 2);
      if(prev == 0 || prev == 1)
	cost += 1;
      else
	cost += 3;
      rcost = min(rcost, cost);
    } else {
      // move left
      int cost = f(n+1, up, r, 1);
      if(l == down) {
	if(prev == 0 || prev == 2)
	  cost += 1;
	else
	  cost += 7;
      } else {
	if(prev == 0 || prev == 2)
	  cost += 1;
	else
	  cost += 5;
      }
      lcost = min(lcost, cost);
      // move right
      cost = f(n+1, l, up, 2);
      if(r == down) {
	if(prev == 0 || prev == 1)
	  cost += 1;
	else
	  cost += 7;
      } else {
	if(prev == 0 || prev == 1)
	  cost += 1;
	else
	  cost += 5;
      }
      rcost = min(rcost, cost);
    }
  } else if(next == '.') {
    staycost = min(staycost, f(n+1, l, r, 0));
    if(l != up && r != up) {
      int cost = f(n+1, up, r, 1);
      if(prev == 0 || prev == 2) {
	cost += 1;
      } else {
	if(l == left || l == right)
	  cost += 5;
	else
	  cost += 7;
      }
      lcost = min(lcost, cost);

      cost = f(n+1, l, up, 2);
      if(prev == 0 || prev == 1) {
	cost += 1;
      } else {
	if(l == left || l == right)
	  cost += 5;
	else
	  cost += 7;
      }
      rcost = min(rcost, cost);
    }
    if(l != down && r != down) {
      int cost = f(n+1, down, r, 1);
      if(prev == 0 || prev == 2) {
	cost += 1;
      } else {
	if(l == left || l == right)
	  cost += 5;
	else
	  cost += 7;
      }
      lcost = min(lcost, cost);

      cost = f(n+1, l, down, 2);
      if(prev == 0 || prev == 1) {
	cost += 1;
      } else {
	if(l == left || l == right)
	  cost += 5;
	else
	  cost += 7;
      }
      rcost = min(rcost, cost);
    }
    if(l != left && r != left) {
      int cost = f(n+1, left, r, 1);
      if(prev == 0 || prev == 2) {
	cost += 1;
      } else {
	if(l == up || l == down)
	  cost += 5;
	else
	  cost += 7;
      }
      lcost = min(lcost, cost);

      cost = f(n+1, l, left, 2);
      if(prev == 0 || prev == 1) {
	cost += 1;
      } else {
	if(l == up || l == down)
	  cost += 5;
	else
	  cost += 7;
      }
      rcost = min(rcost, cost);
    } 
    if(l != right && r != right) {
      int cost = f(n+1, right, r, 1);
      if(prev == 0 || prev == 2) {
	cost += 1;
      } else {
	if(l == up || l == down)
	  cost += 5;
	else
	  cost += 7;
      }
      lcost = min(lcost, cost);

      cost = f(n+1, l, right, 2);
      if(prev == 0 || prev == 1) {
	cost += 1;
      } else {
	if(l == up || l == down)
	  cost += 5;
	else
	  cost += 7;
      }
      rcost = min(rcost, cost);
    }
  }
  if(lcost <= rcost && lcost <= staycost)
    dps[n][l][r][prev] = 'L';
  else if(rcost <= lcost && rcost <= staycost)
    dps[n][l][r][prev] = 'R';
  else
    dps[n][l][r][prev] = '.';
  return dp[n][l][r][prev] = min(min(lcost, rcost), staycost);
}

void printAns(int n, int l, int r, int prev) {
  //printf("calling %d %d %d %d\n", n, l, r, prev);
  char print = dps[n][l][r][prev];
  printf("%c", print);
  if(n+1 == strlen(str))
    return;

  int newpos = -1;
  if(str[n] == 'U') {
    newpos = up;
  } else if(str[n] == 'D') {
    newpos = down;
  } else if(str[n] == 'L') {
    newpos = left;
  } else if(str[n] == 'R') {
    newpos = right;
  }
  if(print == 'L') {
    printAns(n+1, newpos, r, 1);
  } else if(print == 'R') {
    printAns(n+1, l, newpos, 2);
  } else {
    printAns(n+1, l, r, 0);
  }
}

int main() {
  while(scanf("%s\n", str) != EOF) {
    if(str[0] == '#')
      break;
    memset(dp, -1, sizeof dp);
    f(0, left, right, 0);
    printAns(0, left, right, 0);
  }
  return 0;
}
