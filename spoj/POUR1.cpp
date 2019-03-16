#include <cstdio>
#include <map>
#include <utility>
#include <queue>

using namespace std;

int a, b, c;
typedef pair<int, int> Node;

int main() {
  int tc;
  scanf("%d", &tc);
  while(tc--) {
    scanf("%d%d%d", &a, &b, &c);
    if(c == 0) {
      printf("0\n");
      continue;
    }
    map<Node, int> m;
    m[make_pair(0, 0)] = 0;
    queue<Node> q;
    q.push(make_pair(0, 0));
    int ans = -1;
    while(!q.empty()) {
      Node u = q.front();
      q.pop();
      int cur = m[u];

      Node v = make_pair(0, u.second);
      if(!m.count(v)) {
	m[v] = cur + 1;
	q.push(v);
	if(v.first == c || v.second == c) {
	  ans = cur + 1;
	  break;
	}
      }

      v = make_pair(u.first, 0);
      if(!m.count(v)) {
	m[v] = cur + 1;
	q.push(v);
	if(v.first == c || v.second == c) {
	  ans = cur + 1;
	  break;
	}
      }

      v = make_pair(a, u.second);
      if(!m.count(v)) {
	m[v] = cur + 1;
	q.push(v);
	if(v.first == c || v.second == c) {
	  ans = cur + 1;
	  break;
	}
      }

      v = make_pair(u.first, b);
      if(!m.count(v)) {
	m[v] = cur + 1;
	q.push(v);
	if(v.first == c || v.second == c) {
	  ans = cur + 1;
	  break;
	}
      }

      int diff = b - u.second;
      v = make_pair(u.first - min(u.first, diff), u.second + min(u.first, diff));
      if(!m.count(v)) {
	m[v] = cur + 1;
	q.push(v);
	if(v.first == c || v.second == c) {
	  ans = cur + 1;
	  break;
	}
      }

      diff = a - u.first;
      v = make_pair(u.first + min(u.second, diff), u.second - min(u.second, diff));
      if(!m.count(v)) {
	m[v] = cur + 1;
	q.push(v);
	if(v.first == c || v.second == c) {
	  ans = cur + 1;
	  break;
	}
      }
    }
    printf("%d\n", ans);
  }
  return 0;
}
