#include <cstdio>
#include <utility>
#include <algorithm>

using namespace std;

const int maxn = 100000;
typedef pair<int, int> Node;
Node v[maxn+5];
int n;

bool cmp(Node a, Node b) {
  if(a.second != b.second)
    return a.second < b.second;
  return a.first >= b.first;
}

int main() {
  int tc;
  scanf("%d", &tc);
  while(tc--) {
    scanf("%d", &n);
    for(int i = 0; i < n; i++)
      scanf("%d%d", &v[i].first, &v[i].second);
    sort(v, v + n, cmp);
    int cur = 0;
    int ans = 0;
    for(int i = 0; i < n; i++) {
      if(v[i].first >= cur) {
	ans++;
	cur = v[i].second;
      }
    }
    printf("%d\n", ans);
  }
  return 0;
}
