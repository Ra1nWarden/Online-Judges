#include <cstdio>
#include <cstring>
#include <vector>

using namespace std;

const int maxn = 10000000;
int nv[maxn+5];
vector<int> mv[maxn+5];
int n, m, k;

bool check(int x) {
  int y = m - x;
  long long total = 0;
  for(int i = 0; i <= 10000000; i++) {
    if(nv[i]) {
      total += nv[i];
    }
    if(!mv[i].empty()) {
      if(y == 0) {
	total += mv[i].size();
      } else {
	y -= mv[i].size();
	if(y < 0) {
	  total -= y;
	  y = 0;
	}
      }
    }
    if(total > (i + 1) * 1LL * k) {
      return false;
    }
  }
  return true;
}

int main() {
  scanf("%d%d%d", &n, &m, &k);
  memset(nv, 0, sizeof nv);
  for(int i = 0; i < n; i++) {
    int x;
    scanf("%d", &x);
    nv[x]++;
  }
  for(int i = 1; i <= m; i++) {
    int x;
    scanf("%d", &x);
    mv[x].push_back(i);
  }
  if(!check(0)) {
    printf("-1\n");
    return 0;
  }
  int left = 0, right = m;
  while(left != right) {
    int mid = ((left + right) >> 1) + 1;
    if(check(mid)) {
      left = mid;
    } else {
      right = mid - 1;
    }
  }
  printf("%d\n", left);
  for(int i = 10000000; i >= 0; i--) {
    if(mv[i].empty())
      continue;
    int pn;
    if(left > mv[i].size()) {
      pn = mv[i].size();
    } else {
      pn = left;
    }
    for(int j = 0; j < pn; j++) {
      if(left != right || j != 0) {
	printf(" ");
      }
      printf("%d", mv[i][j]);
    }
    left -= pn;
    if(left == 0)
      break;
  }
  printf("\n");
  return 0;
}
