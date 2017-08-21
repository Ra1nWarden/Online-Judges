#include <cstdio>
#include <vector>
#include <map>

using namespace std;

const int maxn = 300000;
int v[maxn+5];
int n;
vector<int> adjMat[maxn+5];
map<int, vector<int> > m;
int maxV = -2000000000;

int main() {
  scanf("%d", &n);
  for(int i = 1; i <= n; i++) {
    scanf("%d", &v[i]);
    maxV = max(maxV, v[i] + 2);
    if(m.count(v[i] + 2)) {
      m[v[i] + 2].push_back(i);
    } else {
      vector<int> item;
      item.push_back(i);
      m[v[i] + 2] = item;
    }
  }
  for(int i = 0; i < n - 1; i++) {
    int a, b;
    scanf("%d %d", &a, &b);
    adjMat[a].push_back(b);
    adjMat[b].push_back(a);
  }
  int a = m[maxV].size();
  int b = m.count(maxV - 1) ? m[maxV - 1].size() : 0;
  int c = m.count(maxV - 2) ? m[maxV - 2].size() : 0;
  int ans = maxV;
  for(int u = 1; u <= n; u++) {
    int aa = a, bb = b, cc = c;
    if(v[u] + 2 == maxV) {
      aa--;
      cc++;
    } else if(v[u] + 2 == maxV - 1) {
      bb--;
    } else if(v[u] + 2 == maxV - 2) {
      cc--;
    }
    for(int j = 0; j < adjMat[u].size(); j++) {
      int uu = adjMat[u][j];
      if(v[uu] + 2 == maxV) {
	aa--;
	bb++;
      } else if(v[uu] + 2 == maxV - 1) {
	bb--;
	cc++;
      } else if(v[uu] + 2 == maxV - 2) {
	cc--;
      }
    }
    if(aa != 0) {
      ans = min(ans, maxV);
    } else if(bb != 0) {
      ans = min(ans, maxV - 1);
    } else {
      ans = min(ans, maxV - 2);
    }
  }
  printf("%d\n", ans);
  return 0;
}
