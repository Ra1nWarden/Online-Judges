#include <cstdio>
#include <algorithm>
#define MAXN 5005
#define INF 2000000000

using namespace std;

int v[MAXN];
int n;

int solve(int begin, int end) {
  int minVal = INF;
  int minCnt = 0;
  bool done = true;
  for(int i = begin; i < end; i++) {
    if(v[i] != 0)
      done = false;
    if(v[i] == minVal) {
      minCnt++;
    } else if(v[i] < minVal) {
      minVal = v[i];
      minCnt = 1;
    }
  }
  if(done)
    return 0;
  int ans = minVal;
  int start = -1;
  int finish = -1;
  for(int i = begin; i < end; i++) {
    v[i] -= minVal;
    if(v[i] > 0) {
      if(start == -1) {
	start = i;
      }
    } else if(v[i] == 0) {
      if(start != -1) {
	finish = i;
	ans += solve(start, finish);
	start = -1;
	finish = -1;
      }
    }
  }
  if(start != -1)
    ans += solve(start, end);
  return min(ans, end - begin);
}

int main() {
  scanf("%d", &n);
  for(int i = 0; i < n; i++)
    scanf("%d", &v[i]);
  printf("%d\n", solve(0, n));
  return 0;
}
