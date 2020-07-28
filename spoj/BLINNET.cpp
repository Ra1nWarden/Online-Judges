#include <iostream>
#include <queue>
#include <string>

using namespace std;

struct Edge {
  int a, b, c;
  Edge(int i, int j, int k) : a(i), b(j), c(k) {}
  bool operator<(const Edge& rhs) const {
    return rhs.c < c;
  }
};

const int maxn = 10000;
int n;
int fa[maxn+5];

int find_set(int a) {
  return fa[a] == a ? a : fa[a] = find_set(fa[a]);
}

void merge_set(int a, int b) {
  fa[find_set(a)] = find_set(b);
}

void init() {
  for(int i = 1; i <= n; i++)
    fa[i] = i;
}

int main() {
  ios::sync_with_stdio(false);
  int tc;
  cin >> tc;
  while(tc--) {
    cin >> n;
    priority_queue<Edge> pq;
    string name;
    for(int i = 1; i <= n; i++) {
      cin >> name;
      int m;
      cin >> m;
      int j, c;
      while(m--) {
	cin >> j >> c;
	pq.push(Edge(i, j, c));
      }
    }
    init();
    int ans = 0;
    for(int i = 0; i < n - 1; i++) {
      while(!pq.empty()) {
	Edge u = pq.top();
	pq.pop();
	if(find_set(u.a) != find_set(u.b)) {
	  ans += u.c;
	  merge_set(u.a, u.b);
	  break;
	}
      }
    }
    cout << ans << endl;
  }
  return 0;
}
