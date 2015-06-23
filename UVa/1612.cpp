#include <cstdio>
#include <cmath>
#include <algorithm>
#define MAXN 16400

using namespace std;

int v[MAXN];
int scores[MAXN][3];
int n;

int calc(int idx, int mask) {
  int ans = 0;
  for(int i = 0; i < 3; i++) {
    if(((1 << i) & mask) != 0) {
      ans += scores[idx][i];
    }
  }
  return ans;
}

int main() {
  int kase = 1;
  while(scanf("%d", &n) != EOF && n) {
    for(int i = 1; i <= n; i++) {
      double a, b, c;
      scanf("%lf %lf %lf", &a, &b, &c);
      scores[i][0] = (int) round(a*100.0);
      scores[i][1] = (int) round(b*100.0);
      scores[i][2] = (int) round(c*100.0);
    }
    for(int i = 1; i <= n; i++)
      scanf("%d", &v[i]);
    int score = scores[v[1]][0] + scores[v[1]][1] + scores[v[1]][2];
    int prev = v[1];
    bool ok = true;
    for(int i = 2; i <= n; i++) {
      int idx = v[i];
      int nextscore = -1;
      for(int mask = 0; mask < 8; mask++) {
	int subscore = calc(idx, mask);
	if(idx > prev) {
	  if(subscore <= score)
	    nextscore = max(nextscore, subscore);
	} else {
	  if(subscore < score)
	    nextscore = max(nextscore, subscore);
	}
      }
      score = nextscore;
      prev = idx;
      if(score == -1) {
	ok = false;
	break;
      }
    }
    if(ok)
      printf("Case %d: %.2lf\n", kase++, score / 100.0);
    else
      printf("Case %d: No solution\n", kase++);
  }
  return 0;
}
