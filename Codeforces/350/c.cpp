#include <cstdio>
#include <utility>
#include <map>

using namespace std;

const int maxn = 200000;
int subs[maxn+5];
int auds[maxn+5];
map<int, int> understand;
int n, m;

int main() {
  scanf("%d", &n);
  for(int i = 0; i < n; i++) {
    int l;
    scanf("%d", &l);
    if(understand.count(l)) {
      understand[l]++;
    } else {
      understand[l] = 1;
    }
  }
  scanf("%d", &m);
  for(int i = 0; i < m; i++) {
    scanf("%d", &auds[i]);
  }
  for(int i = 0; i < m; i++) {
    scanf("%d", &subs[i]);
  }
  pair<int, int> ans = make_pair(-1, -1);
  int idx = -1;
  for(int i = 0; i < m; i++) {
    pair<int, int> cur = make_pair(understand[auds[i]], understand[subs[i]]);
    if(cur > ans) {
      ans = cur;
      idx = i;
    }
  }
  printf("%d\n", idx+1);
  return 0;
}
