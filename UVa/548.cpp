#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>
#define MAXV 10010
#define INF 2e9

using namespace std;

int in_order[MAXV], post_order[MAXV], lch[MAXV], rch[MAXV];
int n;

bool read_input() {
  string line;
  if(!getline(cin, line))
    return false;
  stringstream ss1(line);
  n = 0;
  int x;
  while(ss1 >> x)
    in_order[n++] = x;
  if(!getline(cin, line))
    return false;
  stringstream ss2(line);
  n = 0;
  while(ss2 >> x)
    post_order[n++] = x;
  return n > 0;
}

int build(int l1, int r1, int l2, int r2) {
  if(l1 > r1)
    return 0;
  int root = post_order[r2];
  int p = l1;
  while(in_order[p] != root)
    p++;
  int cnt = p - l1;
  lch[root] = build(l1, p-1, l2, l2+cnt-1);
  rch[root] = build(p+1, r1, l2+cnt, r2-1);
  return root;
}

int best, best_sum;

void dfs(int u, int sum) {
  sum += u;
  if(!lch[u] && !rch[u]) {
    if(sum < best_sum || (sum == best_sum && u < best)) {
      best = u;
      best_sum = sum;
    }
  }
  if(lch[u])
    dfs(lch[u], sum);
  if(rch[u])
    dfs(rch[u], sum);
}

int main() {
  while(read_input()) {
    build(0, n-1, 0, n-1);
    best_sum = INF;
    dfs(post_order[n-1], 0);
    cout <<best << endl;
  }
  return 0;
}
