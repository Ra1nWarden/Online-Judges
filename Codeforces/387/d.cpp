#include <cstdio>
#include <queue>
#include <functional>

using namespace std;

const int maxn = 200000;
int n, k, vi;
int v[maxn+5];

int main() {
  scanf("%d%d", &n, &k);
  int cnt = 0;
  int x;
  vi = 0;
  for(int i = 0; i < n; i++) {
    scanf("%d", &x);
    if(x < 0) {
      if(cnt > 0) {
	v[vi++] = cnt;
	cnt = -1;
      } else {
	cnt--;
      }
    } else {
      if(cnt >= 0) {
	cnt++;
      } else {
	v[vi++] = cnt;
	cnt = 1;
      }
    }
  }
  v[vi++] = cnt;
  int snow = 0;
  for(int i = 0; i < vi; i++) {
    if(v[i] < 0)
      snow -= v[i];
  }
  if(snow > k) {
    printf("-1\n");
    return 0;
  }
  bool f = true;
  int total = 0;
  for(int i = 0; i < vi; i++) {
    if(f && v[i] < 0) {
      total++;
      f = false;
    } else if(!f && v[i] > 0) {
      total++;
      f = true;
    }
  }
  int left = k - snow;
  priority_queue<int, vector<int>, greater<int> > pq;
  for(int i = 1; i < vi - 1; i++) {
    if(v[i] > 0) {
      pq.push(v[i]);
    }
  }
  while(!pq.empty() && left) {
    int u = pq.top();
    pq.pop();
    if(left >= u) {
      left -= u;
      total -= 2;
    } else {
      break;
    }
  }
  if(vi > 1 && v[vi-1] > 0 && left >= v[vi-1]) {
    total--;
  }
  printf("%d\n", total);
  return 0;
}
