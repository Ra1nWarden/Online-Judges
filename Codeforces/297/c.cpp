#include <queue>
#include <cstdio>
#include <algorithm>
#include <cstdlib>
#include <cstring>

using namespace std;

int main() {
  int n;
  scanf("%d", &n);
  priority_queue<int> pq;
  for(int i =0; i < n; i++) {
    int x;
    scanf("%d\n", &x);
    pq.push(x);
  }
  int prev = -1;
  int v[2];
  v[0] = -1;
  v[1] = -1;
  int index = 0;
  long long ans = 0;
  while(!pq.empty()) {
    int next = pq.top();
    pq.pop();
    if(prev == -1) {
      prev = next;
      continue;
    }
    if(next == prev || next == prev - 1) {
      v[index++] = min(prev, next);
      prev = -1;
      if(index == 2) {
	ans += v[0] * 1LL * v[1];
	v[0] = v[1] = -1;
	index = 0;
      }
    } else
      prev = next;
  }
  printf("%I64d\n", ans);
  return 0;
}
