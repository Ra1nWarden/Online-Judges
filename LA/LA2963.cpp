#include <cstdio>
#include <vector>
#include <algorithm>
#include <cmath>
#define MAXN 1005

using namespace std;

struct Node {
  int u, v, d;
  Node(int u, int v, int d) : u(u), v(v), d(d) {}
  bool operator<(const Node& rhs) const {
    return d < rhs.d;
  }
};

struct Point {
  int x, y, z, c;
};

Point points[MAXN];
int n;
vector<Node> v;
int cnt[MAXN];
int ans;
int ans_v;
int cur;

int main() {
  while(~scanf("%d", &n)) {
    for(int i = 0; i < n; i++) {
      scanf("%d%d%d%d", &points[i].x, &points[i].y, &points[i].z, &points[i].c);
      cnt[i] = 1;
    }
    v.clear();
    for(int i = 0; i < n; i++) {
      for(int j = i + 1; j < n; j++) {
	v.push_back(Node(i, j, (points[i].x - points[j].x) * (points[i].x - points[j].x) + (points[i].y - points[j].y) * (points[i].y - points[j].y) + (points[i].z - points[j].z) * (points[i].z - points[j].z)));
      }
    }
    sort(v.begin(), v.end());
    ans = 0;
    ans_v = 0;
    cur = 0;
    for(int i = 0; i < v.size(); i++) {
      int j = i;
      for(; j < v.size(); j++) {
	if(v[j].d != v[i].d)
	  break;
	Node& node = v[j];
	if(points[node.u].c == points[node.v].c) {
	  cnt[node.u]++;
	  cnt[node.v]++;
	  if(cnt[node.u] == 0)
	    cur--;
	  if(cnt[node.v] == 0)
	    cur--;
	} else {
	  cnt[node.u]--;
	  cnt[node.v]--;
	  if(cnt[node.u] == -1)
	    cur++;
	  if(cnt[node.v] == -1)
	    cur++;
	}
      }
      if(cur > ans) {
	ans = cur;
	ans_v = v[i].d;
      }
      i = j - 1;
    }
    printf("%d\n%.4lf\n", ans, sqrt(ans_v));
  }
  return 0;
}
