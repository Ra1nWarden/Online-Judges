#include <cstdio>
#include <string>
#include <queue>
#include <utility>
#include <set>

using namespace std;

typedef pair<string, int> Node;

int main() {
  int tc;
  scanf("%d", &tc);
  int mod;
  while(tc--) {
    scanf("%d", &mod);
    queue<Node> q;
    q.push(make_pair("1", 1 % mod));
    set<int> vis;
    vis.insert(1 % mod);
    while(!q.empty()) {
      Node u = q.front();
      q.pop();
      if(u.second == 0) {
	printf("%s\n", u.first.c_str());
	break;
      }
      int u1 = (u.second * 10) % mod;
      if(!vis.count(u1)) {
	q.push(make_pair(u.first + "0", u1));
	vis.insert(u1);
      }
      int u2 = (u.second * 10 + 1) % mod;
      if(!vis.count(u2)) {
	q.push(make_pair(u.first + "1", (u.second * 10 + 1) % mod));
	vis.insert(u2);
      }
    }
  }
  return 0;
}
