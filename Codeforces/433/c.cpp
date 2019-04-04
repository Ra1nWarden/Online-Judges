#include <cstdio>
#include <queue>
#include <utility>

using namespace std;

const int maxn = 300000;
int ans[maxn+5];
typedef pair<int, int> Node;

int main() {
  int n, k;
  scanf("%d%d", &n, &k);
  priority_queue<Node> pq;
  long long cost = 0LL;
  for(int i = 0; i < n + k; i++) {
    if(i < n) {
      int t;
      scanf("%d", &t);
      pq.push(make_pair(t, i));
    }
    if(i >= k) {
      Node u = pq.top();
      pq.pop();
      ans[u.second] = i + 1;
      cost += u.first * 1LL * (i - u.second);
    }
  }
  printf("%I64d\n", cost);
  for(int i = 0; i < n; i++) {
    if(i)
      printf(" ");
    printf("%d", ans[i]);
  }
  printf("\n");
  return 0;
}
