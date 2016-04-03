#include <cstdio>
#include <queue>
#include <set>

using namespace std;

const int maxn = 150000;
int n, k, q;
int v[maxn+5];
typedef pair<int, int> Node;

int main() {
  scanf("%d%d%d", &n, &k, &q);
  for(int i = 0; i < n; i++) {
    scanf("%d", &v[i]);
  }
  int type, query;
  priority_queue<Node, vector<Node>, greater<Node> > qu;
  set<int> inq;
  for(int i = 0; i < q; i++) {
    scanf("%d%d", &type, &query);
    if(type == 2) {
      printf("%s\n", inq.count(query) ? "YES" : "NO");
    } else {
      qu.push(make_pair(v[query - 1], query));
      inq.insert(query);
      if(qu.size() > k) {
	Node u = qu.top();
	qu.pop();
	inq.erase(u.second);
      }
    }
  }
  return 0;
}
