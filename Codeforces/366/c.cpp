#include <cstdio>
#include <cstring>
#include <utility>
#include <queue>

using namespace std;

const int maxn = 300000;
typedef pair<int, int> Node;
queue<int> q[maxn+5];
queue<Node> qq;
int i;
bool v[maxn+5];

int main() {
  int n, query;
  i = 0;
  scanf("%d%d", &n, &query);
  memset(v, false, sizeof v);
  int unread = 0;
  while(query--) {
    int t, tt;
    scanf("%d%d", &t, &tt);
    if(t == 1) {
      qq.push(make_pair(tt, i));
      q[tt].push(i);
      i++;
      unread++;
    } else if(t == 2) {
      queue<int>& cur_q = q[tt];
      while(!cur_q.empty()) {
	int u = cur_q.front();
	cur_q.pop();
	if(!v[u]) {
	  v[u] = true;
	  unread--;
	}
      }
    } else {
      while(!qq.empty() && qq.front().second < tt) {
	int u = qq.front().second;
	qq.pop();
	if(!v[u]) {
	  v[u] = true;
	  unread--;
	}
      }
    }
    printf("%d\n", unread);
  }
  return 0;
}
