#include <cstdio>
#include <set>
#include <algorithm>
#include <queue>
#define MAXN 55

using namespace std;

int v[MAXN];
int n;
set<int> ans;
int max_val;

struct State {
  int mask;
  set<int> s;
};

int main() {
  int kase = 1;
  while(scanf("%d", &n) && n) {
    max_val = 0;
    ans.clear();
    for(int i = 0; i < n; i++) {
      scanf("%d", &v[i]);
      max_val = max(max_val, v[i]);
    }
    sort(v, v+n);
    n = unique(v, v+n) - v;
    State start;
    start.mask = 0;
    start.s.insert(0);
    queue<State> q;
    q.push(start);
    while(!q.empty()) {
      State u = q.front();
      q.pop();
      if(u.mask == ((1 << n) - 1)) {
	if(ans.empty() || u.s.size() < ans.size()) {
	  ans = u.s;
	}
	continue;
      }
      if(!ans.empty() && u.s.size() >= ans.size())
	continue;
      if(u.s.size() > 7)
	continue;
      for(int i = 0; i < n; i++) {
	int target = v[i];
	if((u.mask & (1 << i)) == 0) {
	  for(set<int>::iterator itr = u.s.begin(); itr != u.s.end(); itr++) {
	    int cur = *itr;
	    if(cur >= target) {
	      State uu = u;
	      int new_num = cur - target;
	      for(int j = 0; j < n; j++) {
		if((uu.mask & (1 << j)) == 0) {
		  int missing = v[j];
		  if(uu.s.count(missing + new_num) || uu.s.count(new_num - missing)) {
		    uu.mask |= (1 << j);
		  }
		}
	      }
	      uu.s.insert(new_num);
	      q.push(uu);
	    }
	    if(cur + target <= max_val) {
	      State uu = u;
	      int new_num = cur + target;
	      for(int j = 0; j < n; j++) {
		if((uu.mask & (1 << j)) == 0) {
		  int missing = v[j];
		  if(uu.s.count(missing + new_num) || uu.s.count(new_num - missing)) {
		    uu.mask |= (1 << j);
		  }
		}
	      }
	      uu.s.insert(new_num);
	      q.push(uu);
	    }
	  }
	}
      }
    }
    printf("Case %d:\n", kase++);
    printf("%d\n", ans.size());
    bool init = true;
    for(set<int>::iterator itr = ans.begin(); itr != ans.end(); itr++) {
      if(!init)
	printf(" ");
      printf("%d", *itr);
      init = false;
    }
    printf("\n");
  }
  return 0;
}
