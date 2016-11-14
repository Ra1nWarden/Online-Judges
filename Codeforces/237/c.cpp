#include <cstdio>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;

const int maxn = 100000;
const int maxm = 1000000;
typedef pair<int, int> Edge;
Edge edges[maxm+5];
int n, k, ei;
vector<int> v[maxn+5];
int d[maxn+5];

int main() {
  scanf("%d%d", &n, &k);
  memset(d, 0, sizeof d);
  int x;
  int maxd = 0;
  for(int i = 1; i <= n; i++) {
    scanf("%d", &x);
    maxd = max(maxd, x);
    v[x].push_back(i);
  }
  if(v[0].size() != 1) {
    printf("-1\n");
    return 0;
  }
  ei = 0;
  bool ok = true;
  for(int i = 1; i <= maxd; i++) {
    int ii = 0;
    for(int j = 0; j < v[i].size(); j++) {
      int a = v[i][j];
      while(ii < v[i-1].size() && d[v[i-1][ii]] == k) {
	ii++;
      }
      if(ii == v[i-1].size()) {
	ok = false;
	break;
      }
      int b = v[i-1][ii];
      edges[ei++] = make_pair(a, b);
      d[a]++;
      d[b]++;
    }
    if(!ok)
      break;
  }
  if(!ok)
    printf("-1\n");
  else {
    printf("%d\n", ei);
    for(int i = 0; i < ei; i++)
      printf("%d %d\n", edges[i].first, edges[i].second);
  }
  return 0;
}
