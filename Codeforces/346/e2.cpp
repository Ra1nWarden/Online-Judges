#include <cstdio>
#include <vector>
#include <queue>
#include <cstring>
#include <list>

using namespace std;

const int maxn = 100000;
const int maxm = 100000;
typedef pair<int, int> Edge;
Edge edges[maxm+5];
int n, m;
vector<int> adjList[maxn+5];
bool avail[maxn+5];
bool done[maxn+5];
list<int> cnt[maxn+5];
int degrees[maxn+5];

int main() {
  scanf("%d%d", &n, &m);
  memset(degrees, 0, sizeof degrees);
  for(int i = 0; i < m; i++) {
    scanf("%d%d", &edges[i].first, &edges[i].second);
    adjList[edges[i].first].push_back(i);
    adjList[edges[i].second].push_back(i);
    degrees[edges[i].first]++;
    degrees[edges[i].second]++;
  }
  memset(done, false, sizeof done);
  memset(avail, true, sizeof avail);
  priority_queue<int, vector<int>, greater<int> > pq;
  for(int i = 1; i <= n; i++) {
    pq.push(adjList[i].size());
    cnt[adjList[i].size()].push_back(i);
  }
  int ans = 0;
  while(!pq.empty()) {
    int node_cnt = pq.top();
    pq.pop();
    if(cnt[node_cnt].empty())
      continue;
    int node = cnt[node_cnt].front();
    cnt[node_cnt].pop_front();
    if(done[node] || degrees[node] != node_cnt)
      continue;
    //printf("dealing %d with %d\n", node, node_cnt);
    bool have_done = false;
    int least_idx = -1;
    int largest_pool = -1;
    int least_edge_idx = -1;
    for(int i = 0; i < adjList[node].size(); i++) {
      int edge_idx = adjList[node][i];
      if(avail[edge_idx]) {
	int other = edges[edge_idx].first == node ? edges[edge_idx].second : edges[edge_idx].first;
	if(done[other]) {
	  have_done = true;
	  break;
	} else if(degrees[other] > largest_pool) {
	  largest_pool = degrees[other];
	  least_idx = other;
	  least_edge_idx = edge_idx;
	}
      }
    }
    if(!have_done) {
      if(least_edge_idx == -1) {
	ans++;
      }
      else {
	//printf("connecting %d and %d\n", node, least_idx);
	avail[least_edge_idx] = false;
	degrees[least_idx]--;
	pq.push(degrees[least_idx]);
	cnt[degrees[least_idx]].push_back(least_idx);
      }
    }
    //printf("marking %d as done\n", node);
    done[node] = true;
  }
  printf("%d\n", ans);
  return 0;
}
