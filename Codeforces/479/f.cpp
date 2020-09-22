#include <cstdio>
#include <map>
#include <stack>

using namespace std;

const int maxn = 200000;
int n;
int v[maxn+5];
int pre[maxn+5];
map<int, int> pos;
map<int, int> len;

int main() {
  scanf("%d", &n);
  int ans = 0;
  int cur = 0;
  for(int i = 1; i <= n; i++) {
    scanf("%d", &v[i]);
    pre[i] = 0;
    if(len.count(v[i] - 1)) {
      len[v[i]] = len[v[i] - 1] + 1;
      pre[i] = pos[v[i] - 1];
    } else {
      len[v[i]] = 1;
    }
    pos[v[i]] = i;
    if(len[v[i]] > ans) {
      ans = len[v[i]];
      cur = i;
    }
  }
  
  printf("%d\n", ans);
  stack<int> seq;
  for(int i = 0; i < ans; i++) {
    seq.push(cur);
    cur = pre[cur];
  }
  bool start = true;
  while(!seq.empty()) {
    if(!start)
      printf(" ");
    printf("%d", seq.top());
    seq.pop();
    start = false;
  }
  printf("\n");
  return 0;
}
