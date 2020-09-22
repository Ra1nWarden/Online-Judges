#include <cstdio>
#include <set>
#include <map>
#include <queue>
#include <cstring>

using namespace std;

const int maxn = 100000;
int n;
int v[maxn+5];
set<int> indices;
map<int, int> cnt, pos;
priority_queue<int> pq;

int main() {
  scanf("%d", &n);
  for(int i = 1; i <= n; i++) {
    scanf("%d", &v[i]);
    pq.push(v[i]);
    pos[v[i]] = i;
  }
  indices.insert(0);
  indices.insert(n+1);
  cnt[n] = 1;
  int loc = 1;
  int ans = 0;
  int removed = 0;

  while(!pq.empty()) {
    int u = pq.top();
    int mid = pos[u];
    pq.pop();
    set<int>::iterator itr = indices.lower_bound(mid);
    int up = *itr;
    itr--;
    int down = *itr;
    int len = up - down - 1;
    cnt[len]--;
    if(cnt[len] == 0) {
      cnt.erase(len);
    }

    int new_up = up - mid - 1;
    int new_down = mid - down - 1;

    if(new_down != 0) {
      if(cnt.count(new_down)) {
	cnt[new_down]++;
      } else {
	cnt[new_down] = 1;
      }
    }

    if(new_up != 0) {
      if(cnt.count(new_up)) {
	cnt[new_up]++;
      } else {
	cnt[new_up] = 1;
      }
    }
    
    removed++;

    if(cnt.size() == 1 && (cnt.begin()->first * cnt.begin()->second + removed == n) && cnt.begin()->second >= loc) {
      loc = cnt.begin()->second;
      ans = u;
    }
  
    indices.insert(mid);
  }

  printf("%d\n", ans);
  return 0;
}
