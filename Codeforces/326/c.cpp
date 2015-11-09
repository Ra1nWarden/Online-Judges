#include <queue>
#include <cstdio>
#include <vector>

using namespace std;

int main() {
  int n;
  scanf("%d", &n);
  priority_queue<int, vector<int>, greater<int> > pq;
  while(n--) {
    int num;
    scanf("%d", &num);
    pq.push(num);
  }
  int ans = 0;
  while(!pq.empty()) {
    int u = pq.top();
    pq.pop();
    if(pq.empty()) {
      ans++;
      break;
    }
    int v = pq.top();
    if(u == v) {
      pq.pop();
      pq.push(u + 1);
    } else {
      ans++;
    }
  }
  printf("%d\n", ans);
  return 0;
}
