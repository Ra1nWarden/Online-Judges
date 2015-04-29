#include <bits/stdc++.h>
#define MAXM 100005

using namespace std;

int n, m;
typedef pair<int, int> II;
II v[MAXM];

int main() {
  scanf("%d %d", &n, &m);
  for(int i = 0; i < m; i++) {
    scanf("%d %d", &v[i].first, &v[i].second);
  }
  int maxRes = 0;
  int prev_h = -1;
  int prev_d = -1;
  bool possible = true;
  for(int i = 0; i < m; i++) {
    if(i == 0) {
      maxRes = max(maxRes, v[i].first - 1 + v[i].second);
    } else {
      if(v[i].first - prev_d < abs(v[i].second - prev_h)) {
	possible = false;
	break;
      }
      if(v[i].second > prev_h) {
	maxRes = max(maxRes, (v[i].first - prev_d - (v[i].second - prev_h)) / 2 + v[i].second);
      } else if(v[i].second < prev_h){
	maxRes = max(maxRes, (v[i].first - prev_d - (prev_h - v[i].second)) / 2 + prev_h);
      } else {
	maxRes = max(maxRes, (v[i].first - prev_d) / 2 + prev_h);
      }
    }
    prev_h = v[i].second;
    prev_d = v[i].first;
  }
  maxRes = max(maxRes, (n - prev_d) + prev_h);
  if(!possible)
    printf("IMPOSSIBLE\n");
  else
    printf("%d\n", maxRes);
  return 0;
}
