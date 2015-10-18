#include <cstdio>
#include <queue>

using namespace std;

typedef pair<int, int> II;

struct Comp {
  bool operator()(const II& a, const II& b) {
    return a.first > b.first;
  }
};

int main() {
  int n, k;
  scanf("%d%d",&n, &k);
  priority_queue<II, vector<II>, Comp> pq;
  int ans = 0;
  for(int i = 0; i < n; i++) {
    int num;
    scanf("%d", &num);
    ans += (num / 10);
    if(num < 100) {
      int next = (num / 10 + 1) * 10;
      pq.push(make_pair(next - num, next));
    }
  }
  while(!pq.empty() && k > 0) {
    II u = pq.top();
    pq.pop();
    if(u.first <= k) {
      ans++;
      k -= u.first;
      if(u.second != 100) {
	pq.push(make_pair(10, u.second + 10));
      }
    } else {
      break;
    }
  }
  printf("%d\n", ans);
  return 0;
}
