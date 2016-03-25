#include <cstdio>
#include <queue>
#include <algorithm>
#include <functional>

using namespace std;

const int maxn = 200000;
int v[maxn+5];
int trans[maxn+5];
bool forwar[maxn+5];
int ans[maxn+5];
int valid[maxn+5];
int vi, ai;
int n, m;
typedef pair<int, int> II;

int main() {
  scanf("%d%d", &n, &m);
  for(int i = 0; i < n; i++) {
    scanf("%d", &v[i]);
  }
  priority_queue<II> pq;
  for(int i = 0; i < m; i++) {
    int flag;
    scanf("%d%d", &flag, &trans[i]);
    forwar[i] = flag == 1;
    pq.push(make_pair(trans[i], i));
  }
  vi = 0;
  while(!pq.empty()) {
    II u = pq.top();
    pq.pop();
    if(vi == 0) {
      valid[vi++] = u.second;
    } else {
      int prev = valid[vi-1];
      if(u.second > prev) {
	valid[vi++] = u.second;
      }
    }
  }
  if(forwar[valid[0]]) {
    sort(v, v+trans[valid[0]]);
  } else {
    sort(v, v+trans[valid[0]], greater<int>());
  }
  ai = n - 1;
  int li = 0, ri = n - 1;
  bool rev = true;
  int prev = n;
  for(int i = 1; i < vi; i++) {
    int cnt = prev - trans[valid[i]];
    prev = trans[valid[i]];
    while(cnt--) {
      if(rev) {
	ans[ai--] = v[ri--];
      } else {
	ans[ai--] = v[li++];
      }
    }
    if(forwar[valid[i]] != forwar[valid[i-1]])
      rev = !rev;
  }
  while(ai > -1) {
    if(rev) {
      ans[ai--] = v[ri--];
    } else {
      ans[ai--] = v[li++];
    }
  }
  for(int i = 0; i < n; i++) {
    if(i)
      printf(" ");
    printf("%d", ans[i]);
  }
  printf("\n");
  return 0;
}
