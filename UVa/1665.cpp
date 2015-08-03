#include <cstdio>
#include <algorithm>
#include <vector>
#include <cstring>
#define MAXN 1005
#define MAXQ 100005

using namespace std;

int m, n;
struct Node {
  int x, y;
  int num;
  Node() {}
  Node(int a, int b, int c) : x(a), y(b), num(c) {}
  bool operator<(const Node& rhs) const {
    if(num != rhs.num) {
      return num < rhs.num;
    } else if(x != rhs.x) {
      return x < rhs.x;
    } else {
      return y < rhs.y;
    }
  }
};

Node nodes[MAXN*MAXN];
int numbers[MAXN][MAXN];
bool used[MAXN][MAXN];
int f[MAXN*MAXN];
int ans[MAXQ];
int qv[MAXQ];
int q;
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

int findParent(int num) {
  return f[num] == num ? num : f[num] = findParent(f[num]);
}

void unionSet(int a, int b) {
  f[findParent(a)] = findParent(b);
}

bool sameSet(int a, int b) {
  return findParent(a) == findParent(b);
}

int calcIndex(int a, int b) {
  return a * n + b;
}

int main() {
  int tc;
  scanf("%d", &tc);
  while(tc--) {
    scanf("%d %d", &m, &n);
    int idx = 0;
    for(int i = 0; i < m; i++) {
      for(int j = 0; j < n; j++) {
	nodes[idx].x = i;
	nodes[idx].y = j;
	scanf("%d", &nodes[idx].num);
	numbers[i][j] = nodes[idx].num;
	f[idx] = idx;
	idx++;
      }
    }
    sort(nodes, nodes+idx);
    scanf("%d", &q);
    memset(used, false, sizeof used);
    for(int i = 0; i < q; i++)
      scanf("%d", &qv[i]);
    ans[q] = 0;
    int counted = 0;
    for(int i = q - 1; i > -1; i--) {
      Node bound(-1, -1, qv[i]+1);
      int found = idx - (lower_bound(nodes, nodes+idx, bound) - nodes);
      if(found == counted){
	ans[i] = ans[i+1];
      } else {
	int newans = ans[i+1];
	for(int j = idx - found; j < idx - counted; j++) {
	  newans++;
	  Node added = nodes[j];
	  used[added.x][added.y] = true;
	  vector<int> removeSet;
	  for(int k = 0; k < 4; k++) {
	    int xx = added.x + dx[k];
	    int yy = added.y + dy[k];
	    if(xx > -1 && xx < m && yy > -1 && yy < n && used[xx][yy] && numbers[xx][yy] > qv[i]) {
	      int adjNode = calcIndex(xx, yy);
	      bool insert = true;
	      for(int l = 0; l < removeSet.size() && insert; l++) {
		if(sameSet(removeSet[l], findParent(adjNode)))
		  insert = false;
	      }
	      if(insert)
		removeSet.push_back(findParent(calcIndex(xx, yy)));
	    }
	  }
	  for(int l = 0; l < removeSet.size(); l++) {
	    unionSet(calcIndex(added.x, added.y), removeSet[l]);
	  }
	  newans -= removeSet.size();
	}
	ans[i] = newans;
      }
      counted = found;
    }
    for(int i = 0; i < q; i++) {
      printf("%d ", ans[i]);
    }
    printf("\n");
  }
  return 0;
}
