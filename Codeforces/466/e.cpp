#include <cstdio>
#include <queue>
#include <map>

using namespace std;

const int maxn = 100000;
int v[maxn+5];
int min_val[maxn+5];
long long dp[maxn+5];
int n, c;

int find_min(priority_queue<int, vector<int>, greater<int> >& pq, map<int, int>& m) {
  while(!pq.empty()) {
    int u = pq.top();
    if(m.count(u) && m[u] > 0) {
      return u;
    } else {
      pq.pop();
    }
  }
  return 0;
}

int main() {
  scanf("%d%d", &n, &c);
  int i;
  long long sum = 0;
  for(i = 0; i < n; i++) {
    scanf("%d", &v[i]);
    sum += v[i];
  }
  priority_queue<int, vector<int>, greater<int> > pq;
  map<int, int> m;
  for(i = 0; i < c - 1; i++) {
    min_val[i] = 0;
    pq.push(v[i]);
    if(m.count(v[i])) {
      m[v[i]]++;
    } else {
      m[v[i]] = 1;
    }
  }
  for(i = c - 1; i < n; i++) {
    pq.push(v[i]);
    if(m.count(v[i])) {
      m[v[i]]++;
    } else {
      m[v[i]] = 1;
    }
    if(i >= c) {
      m[v[i-c]]--;
    }
    min_val[i] = find_min(pq, m);
  }

  long long max_val = 0;

  for(i = 0; i < c - 1; i++) {
    dp[i] = 0LL;
  }

  for(i = c - 1; i < n; i++) {
    dp[i] = max(max_val,(long long) min_val[i] + (i >= c ? dp[i-c] : 0));
    max_val = max(max_val, dp[i]);
  }

  printf("%I64d\n", sum - max_val);
  
  return 0;
}
