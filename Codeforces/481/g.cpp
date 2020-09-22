#include <cstdio>
#include <algorithm>
#include <vector>
#include <cstring>

using namespace std;

const int maxn = 100;
int n, m;
bool started[maxn+5];

struct Exam {
  int s, d, c;
};

Exam exams[maxn+5];

typedef pair<int, int> II;
II sv[maxn+5], dv[maxn+5];

int main() {
  scanf("%d%d", &n, &m);
  for(int i = 0; i < m; i++) {
    scanf("%d %d %d", &exams[i].s, &exams[i].d, &exams[i].c);
    sv[i] = make_pair(exams[i].s, i);
    dv[i] = make_pair(exams[i].d, i);
  }
  sort(sv, sv + m);
  sort(dv, dv + m);
  memset(started, false, sizeof started);
  int si = 0, di = 0;
  vector<int> ans;
  bool ok = true;
  for(int day = 1; day <= n; day++) {
    if(di == m) {
      ans.push_back(0);
      continue;
    }
    while(si < m && day >= sv[si].first) {
      started[sv[si].second] = true;
      si++;
    }
    if(dv[di].first == day) {
      if(exams[dv[di].second].c > 0) {
	ok = false;
	break;
      }
      ans.push_back(m + 1);
      di++;
    } else {
      int idx = 0;
      for(int i = 0; i < m; i++) {
	if(exams[dv[i].second].c && started[dv[i].second]) {
	  idx = dv[i].second + 1;
	  break;
	}
      }
      ans.push_back(idx);
      if(idx)
	exams[idx-1].c--;
    }
  }
  if(ok) {
    for(int i = 0; i < ans.size(); i++) {
      if(i)
	printf(" ");
      printf("%d", ans[i]);
    }
    printf("\n");
  } else {
    printf("-1\n");
  }
  return 0;
}
