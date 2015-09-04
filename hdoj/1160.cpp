#include <algorithm>
#include <cstdio>
#include <stack>
#define MAXN 1005

using namespace std;

struct Mouse {
  int w, s, idx, prev;
  bool operator<(const Mouse& rhs) const {
    if(w != rhs.w)
      return w < rhs.w;
    return s > rhs.s;
  }
};

Mouse mice[MAXN];
int dp[MAXN];
int n;

int main() {
  n = 0;
  while(true) {
    if(scanf("%d%d", &mice[n].w, &mice[n].s) == EOF)
      break;
    mice[n].prev = -1;
    mice[n].idx = ++n;
  }
  sort(mice, mice+n);

  for(int i = 0; i < n; i++) {
    int max_v = 0;
    int max_j = -1;
    for(int j = 0; j < i; j++) {
      if(mice[j].w < mice[i].w && mice[j].s > mice[i].s) {
	if(dp[j] > max_v) {
	  max_v = dp[j];
	  max_j = j;
	}
      }
    }
    dp[i] = max_v + 1;
    mice[i].prev = max_j;
  }
  int ans = 0;
  int ans_i = -1;
  for(int i = 0; i < n; i++) {
    if(dp[i] > ans) {
      ans = dp[i];
      ans_i = i;
    }
  }

  printf("%d\n", ans);
  stack<int> seq;
  while(ans_i != -1) {
    seq.push(ans_i);
    ans_i = mice[ans_i].prev;
  }

  while(!seq.empty()) {
    printf("%d\n", mice[seq.top()].idx + 1);
    seq.pop();
  }

  return 0;
}
