#include <cstdio>
#include <algorithm>
#include <map>
#include <vector>
#include <algorithm>
#define MAXN 1005

using namespace std;

int v[MAXN];
int n;
typedef pair<int, int> Point;
map<int, vector<Point> > m;

int main() {
  while(scanf("%d", &n) && n) {
    for(int i = 0; i < n; i++)
      scanf("%d", &v[i]);
    sort(v, v+n);
    m.clear();
    for(int i = 0; i < n; i++) {
      for(int j = i+1; j < n; j++) {
	m[v[i] + v[j]].push_back(make_pair(i, j));
      }
    }
    int ans;
    bool found = false;
    for(int i = 0; i < n; i++) {
      for(int j = 0; j < n; j++) {
	if(i == j)
	  continue;
	int left = v[i] - v[j];
	for(int k = 0; k < m[left].size(); k++) {
	  if(m[left][k].first == i || m[left][k].second == i || m[left][k].first == j || m[left][k].second == j)
	    continue;
	  else if(!found) {
	    found = true;
	    ans = v[i];
	  } else {
	    ans = max(ans, v[i]);
	  }
	}
      }
    }
    if(found)
      printf("%d\n", ans);
    else
      printf("no solution\n");
  }
  return 0;
}
