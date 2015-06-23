#include <cstdio>
#include <utility>
#include <queue>
#include <algorithm>
#define MAXN 800005

using namespace std;

typedef pair<int, int> Task;
int dp[MAXN][2];
Task tasks[MAXN];
int n;

bool cmp2(const Task& a, const Task& b) {
  return a.second < b.second;
}

struct cmp1 {
  bool operator()(const Task& a, const Task& b) {
    return a.first < b.first;
  }
};

int main() {
  int tc;
  scanf("%d", &tc);
  while(tc--) {
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
      scanf("%d %d", &tasks[i].first, &tasks[i].second);
    }
    sort(tasks, tasks+n, cmp2);
    priority_queue<Task, vector<Task>, cmp1> pq;
    int ans = 0;
    int t = 0;
    for(int i = 0; i < n; i++) {
      pq.push(tasks[i]);
      t += tasks[i].first;
      ans++;
      if(t > tasks[i].second) {
	Task r = pq.top();
	pq.pop();
	t -= r.first;
	ans--;
      }
    }
    printf("%d\n", ans);
    if(tc)
      printf("\n");
  }
  return 0;
}
