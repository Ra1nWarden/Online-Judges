#include <cstdio>
#include <algorithm>
#include <queue>
#define MAXN 10005
#define INF 2000000000

using namespace std;

struct Task {
  int r, d, w;
  bool operator<(const Task& rhs) const {
    return d > rhs.d;
  }
};

bool _cmp(const Task& a, const Task& b) {
  return a.r < b.r;
}

Task tasks[MAXN];
int n;

bool check(int s) {
  priority_queue<Task> pq;
  int time = 1, pi = 0;
  while(pi < n || !pq.empty()) {
    while(pi < n && tasks[pi].r == time)
      pq.push(tasks[pi++]);
    int work = s;
    while(!pq.empty() && work) {
      Task t = pq.top();
      pq.pop();
      if(work > t.w)
	work -= t.w;
      else if(work == t.w) {
	if(!pq.empty() && pq.top().d <= time + 1)
	  return false;
	work = 0;
      } else {
	if(t.d <= time + 1)
	  return false;
	t.w -= work;
	work = 0;
	pq.push(t);
      }
    }
    time++;
  }
  return true;
}

int main() {
  int tc;
  scanf("%d", &tc);
  while(tc--) {
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
      scanf("%d %d %d", &tasks[i].r, &tasks[i].d, &tasks[i].w);
    }
    sort(tasks, tasks+n, _cmp);
    int l = 1, r = INF;
    while(l != r) {
      int m = (l + r) / 2;
      if(check(m))
	r = m;
      else
	l = m+1;
    }
    printf("%d\n", l);
  }
  return 0;
}
