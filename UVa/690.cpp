#include <cstdio>
#include <cstring>
#include <vector>
#define MAXN 25

using namespace std;

int n;
char board[5][MAXN];
int mask[5];
int ans;
vector<int> allowed;

bool judge(int* v, int offset) {
  for(int i = 0; i < 5; i++) {
    if(mask[i] & (v[i] >> offset))
      return false;
  }
  return true;
}

void init() {
  ans = 200;
  allowed.clear();
  for(int i = 1; i <= n; i++) {
    if(judge(mask, i))
      allowed.push_back(i);
  }
}

void dfs(int depth, int start, int* v) {
  if(depth == 9) {
    ans = min(ans, start + n);
    return;
  }
  for(int i = 0; i < allowed.size(); i++) {
    if(start + allowed[i] + (9 - depth - 1) * allowed[0] + n > ans)
      return;
    if(judge(v, allowed[i])) {
      int tmp[5];
      memcpy(tmp, v, sizeof tmp);
      for(int j = 0; j < 5; j++) {
	// shift existing contraints and or it with mask for the new one.
	tmp[j] = (tmp[j] >> (allowed[i])) | mask[j];
      }
      dfs(depth+1, start + allowed[i], tmp);
    }
  }
}

int main() {
  while(scanf("%d\n", &n) != EOF && n) {
    for(int i = 0; i < 5; i++) {
      scanf("%s\n", board[i]);
      int bit_mask = 0;
      for(int j = 0; j < n; j++) {
	if(board[i][j] == 'X')
	  bit_mask = bit_mask | (1 << j);
      }
      mask[i] = bit_mask;
    }
    init();
    dfs(0, 0, mask);
    printf("%d\n", ans);
  }
  return 0;
}
