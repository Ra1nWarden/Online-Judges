#include <cstdio>
#include <stack>
#include <utility>
#include <algorithm>

using namespace std;

typedef pair<int, int> Node;

const int maxn = 100000;
int v[maxn+5];
int left[maxn+5];
int n;

int main() {
  while(true) {
    scanf("%d", &n);
    if(!n)
      break;
    for(int i = 1; i <= n; i++) {
      scanf("%d", &v[i]);
    }
    stack<Node> s;
    s.push(make_pair(0, 0));
    for(int i = 1; i <= n; i++) {
      while(!s.empty() && s.top().second >= v[i]) {
	s.pop();
      }
      left[i] = s.empty() ? 0 : s.top().first;
      s.push(make_pair(i, v[i]));
    }
    while(!s.empty())
      s.pop();
    s.push(make_pair(n + 1, 0));
    long long ans = 0;
    for(int i = n; i >= 1; i--) {
      while(!s.empty() && s.top().second >= v[i]) {
	s.pop();
      }
      if(!s.empty())
	ans = max(ans, v[i] * 1LL * (s.top().first - left[i] - 1));
      s.push(make_pair(i, v[i]));
    }
    printf("%lld\n", ans);
  }
  return 0;
}
