#include <cstdio>
#include <stack>
#include <cstring>

using namespace std;

const int maxn = 100;
int v[maxn+5];
int memo[maxn+5][3];
int n;

struct State {
  int cur, prev, ans;
};

int main() {
  scanf("%d", &n);
  for(int i = 0; i < n; i++)
    scanf("%d", &v[i]);
  int ans = 1000000000;
  memset(memo, -1, sizeof memo);
  stack<State> s;
  if(v[0] & 1) {
    s.push(State{1, 1, 0});
    memo[1][1] = 0;
  }
  if(v[0] & 2) {
    s.push(State{1, 2, 0});
    memo[1][2] = 0;
  }
  s.push(State{1, 0, 1});
  memo[1][0] = 1;
  while(!s.empty()) {
    State u = s.top();
    s.pop();
    if(u.cur == n) {
      ans = min(ans, u.ans);
      continue;
    }
    if(u.prev == 0) {
      if(v[u.cur] & 1) {
	if(memo[u.cur+1][1] == -1 || u.ans < memo[u.cur+1][1]) {
	  memo[u.cur+1][1] = u.ans;
	  s.push(State{u.cur+1, 1, u.ans});
	}
      }
      if(v[u.cur] & 2) {
	if(memo[u.cur+1][2] == -1 || u.ans < memo[u.cur+1][2]) {
	  memo[u.cur+1][2] = u.ans;
	  s.push(State{u.cur+1, 2, u.ans});
	}
      }
      if(u.ans + 1 < ans) {
	if(memo[u.cur+1][0] == -1 || u.ans + 1 < memo[u.cur+1][0]) {
	  memo[u.cur+1][0] = u.ans+1;
	  s.push(State{u.cur+1, 0, u.ans+1});
	}
      }
    } else if(u.prev == 1) {
      if(v[u.cur] & 2) {
	if(memo[u.cur+1][2] == -1 || u.ans < memo[u.cur+1][2]) {
	  memo[u.cur+1][2] = u.ans;
	  s.push(State{u.cur+1, 2, u.ans});
	}
      }
      if(u.ans + 1 < ans) {
	if(memo[u.cur+1][0] == -1 || u.ans+1 < memo[u.cur+1][0]) {
	  memo[u.cur+1][0] = u.ans+1;
	  s.push(State{u.cur+1, 0, u.ans+1});
	}
      }
    } else if(u.prev == 2) {
      if(v[u.cur] & 1) {
	if(memo[u.cur+1][1] == -1 || u.ans < memo[u.cur+1][1]) {
	  memo[u.cur+1][1] = u.ans;
	  s.push(State{u.cur+1, 1, u.ans});
	}
      }
      if(u.ans + 1 < ans) {
	if(memo[u.cur+1][0] == -1 || u.ans + 1 < memo[u.cur+1][0]) {
	  memo[u.cur+1][0] = u.ans + 1;
	  s.push(State{u.cur+1, 0, u.ans+1});
	}
      }
    }
  }
  printf("%d\n", ans);
  return 0;
}
