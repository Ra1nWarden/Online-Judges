#include <cstdio>
#include <queue>
#define MAXN 105
#define MAXK 1005

using namespace std;

int n, k;
int v[MAXN];
int ans[MAXK][2];

typedef pair<int, int> II;

class GreaterII {
public:
  bool operator()(const II& a, const II& b) {
    return a.second > b.second;
  }
};

class SmallerII {
public:
  bool operator()(const II& a, const II& b) {
    return a.second < b.second;
  }
};


int main() {
  scanf("%d %d", &n, &k);
  priority_queue<II, vector<II>, GreaterII> minq;
  priority_queue<II, vector<II>, SmallerII> maxq;
  for(int i = 0; i < n; i++) {
    scanf("%d", &v[i]);
    minq.push(make_pair(i+1, v[i]));
    maxq.push(make_pair(i+1, v[i]));
  }
  int ansi = 0;
  for(int i = 0; i < k; i++) {
    II nextmax;
    while(true) {
      nextmax = maxq.top();
      maxq.pop();
      if(v[nextmax.first - 1] == nextmax.second) {
	break;
      }
      maxq.push(make_pair(nextmax.first, v[nextmax.first - 1]));
    }
    II nextmin;
    while(true) {
      nextmin = minq.top();
      minq.pop();
      if(v[nextmin.first - 1] == nextmin.second) {
	break;
      }
      minq.push(make_pair(nextmin.first, v[nextmin.first - 1]));
    }
    if(nextmax.second - nextmin.second <= 1) {
      maxq.push(nextmax);
      minq.push(nextmin);
      break;
    }
    ans[ansi][0] = nextmax.first;
    ans[ansi][1] = nextmin.first;
    ansi++;
    v[nextmax.first - 1] = nextmax.second - 1;
    v[nextmin.first - 1] = nextmin.second + 1;
    maxq.push(make_pair(nextmax.first, v[nextmax.first - 1]));
    minq.push(make_pair(nextmin.first, v[nextmin.first - 1]));
  }
  int maxval = -1;
  int minval = 2000000000;
  for(int i = 0; i < n; i++) {
    maxval = max(maxval, v[i]);
    minval = min(minval, v[i]);
  }
  printf("%d %d\n", maxval - minval, ansi);
  for(int i = 0; i < ansi; i++)
    printf("%d %d\n", ans[i][0], ans[i][1]);
  return 0;
}
