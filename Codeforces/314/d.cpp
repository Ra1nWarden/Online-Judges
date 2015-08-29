#include <cstdio>
#include <set>
#define MAXN 200005

using namespace std;

int v[MAXN];

int main() {
  int n, k, a;
  scanf("%d%d%d", &n, &k, &a);
  int m;
  scanf("%d", &m);
  set<int> s;
  s.insert(0);
  s.insert(n+1);
  int total = (n+1) / (a+1);
  int ans = -1;
  for(int i = 1; i <= m; i++) {
    scanf("%d", &v[i]);
  }
  for(int i = 1; i <= m; i++) {
    int hit = v[i];
    if(s.count(hit))
      continue;
    set<int>::iterator upper_itr = s.upper_bound(hit);
    set<int>::iterator lower_itr = upper_itr;
    lower_itr--;
    int up = *upper_itr;
    int low = *lower_itr;
    int orig = (up - low) / (a + 1);
    int new_cnt = (hit - low) / (a + 1) + (up - hit) / (a + 1);
    total += (new_cnt - orig);
    s.insert(hit);
    if(total < k) {
      ans = i;
      break;
    }
  }
  printf("%d\n", ans);
  return 0;
}
