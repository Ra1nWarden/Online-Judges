#include <cstdio>
#include <vector>
#include <queue>
#include <cstring>
#include <algorithm>

using namespace std;

const int maxn = 200000;
vector<int> bids[maxn+5];
int maxbids[maxn+5];
bool valids[maxn+5];
int n, q;
typedef pair<int, int> Node;
int rv[maxn+5];
int ri;
bool left[maxn+5];

int main() {
  scanf("%d", &n);
  int a, b;
  memset(valids, false, sizeof valids);
  for(int i = 0; i < n; i++) {
    scanf("%d%d", &a, &b);
    bids[a].push_back(b);
    maxbids[a] = b;
    valids[a] = true;
  }
  priority_queue<Node> pq;
  for(int i = 1; i <= n; i++) {
    if(valids[i]) {
      pq.push(make_pair(maxbids[i], i));
    }
  }
  int query;
  scanf("%d", &query);
  while(query--) {
    scanf("%d", &ri);
    vector<int> removals;
    memset(left, false, sizeof left);
    for(int i = 0; i < ri; i++) {
      scanf("%d", &rv[i]);
      left[rv[i]] = true;
    }
    int winner = 0;
    while(!pq.empty()) {
      Node u = pq.top();
      removals.push_back(u.second);
      pq.pop();
      if(!left[u.second]) {
	winner = u.second;
	break;
      }
    }
    if(winner == 0) {
      printf("0 0\n");
    } else {
      int nextbid = 0;
      while(!pq.empty()) {
	Node u = pq.top();
	removals.push_back(u.second);
	pq.pop();
	if(!left[u.second]) {
	  nextbid = u.second;
	  break;
	}
      }
      if(nextbid == 0) {
	printf("%d %d\n", winner, bids[winner][0]);
      } else {
	printf("%d %d\n", winner, *upper_bound(bids[winner].begin(), bids[winner].end(), maxbids[nextbid]));
      }
    }
    for(int i = 0; i < removals.size(); i++) {
      pq.push(make_pair(maxbids[removals[i]], removals[i]));
    }
  }
  return 0;
}
