#include <cstdio>
#include <utility>
#include <cstring>
#include <algorithm>

using namespace std;

typedef pair<int, int> II;
II v[2][15];
int ans[2][15];
int n, m;

int match(II a, II b) {
  if(min(a.first, a.second) == min(b.first, b.second) && max(a.first, a.second) == max(b.first, b.second)) {
    return 10;
  }
  if(a.first == b.first || a.first == b.second) {
    return a.first;
  } else if(a.second == b.first || a.second == b.second) {
    return a.second;
  } else {
    return 0;
  }
}

int main() {
  scanf("%d %d", &n, &m);
  for(int i = 0; i < n; i++) {
    scanf("%d %d", &v[0][i].first, &v[0][i].second);
  }
  for(int i = 0; i < m; i++) {
    scanf("%d %d", &v[1][i].first, &v[1][i].second);
  }

  memset(ans, -1, sizeof ans);

  for(int i = 0; i < n; i++) {
    II num = v[0][i];
    int cur = 0;
    for(int j = 0; j < m; j++) {
      int sub = match(num, v[1][j]);
      if(sub == 10 || sub == 0) {
	continue;
      }
      if(cur == 0) {
	cur = sub;
      } else if(cur != sub) {
	cur = 10;
	break;
      }
    }
    ans[0][i] = cur;
  }

  for(int j = 0; j < m; j++) {
    II num = v[1][j];
    int cur = 0;
    for(int i = 0; i < n; i++) {
      int sub = match(num, v[0][i]);
      if(sub == 10 || sub == 0) {
	continue;
      }
      if(cur == 0) {
	cur = sub;
      } else if(cur != sub) {
	cur = 10;
	break;
      }
    }
    ans[1][j] = cur;
  }

  bool fail = false;
  for(int i = 0; i < n; i++) {
    if(ans[0][i] == 10) {
      fail = true;
    }
  }
  for(int j = 0; j < m; j++) {
    if(ans[1][j] == 10) {
      fail = true;
    }
  }

  if(fail) {
    printf("-1\n");
    return 0;
  }

  fail = false;
  int digit = 0;
  for(int i = 0; i < n; i++) {
    if(ans[0][i] == 0)
      continue;
    if(digit == 0) {
      digit = ans[0][i];
    } else if(digit != ans[0][i]) {
      fail = true;
    }
  }
  if(fail) {
    printf("0\n");
    return 0;
  }

  for(int i = 0; i < m; i++) {
    if(ans[1][i] == 0)
      continue;
    if(digit == 0) {
      digit = ans[1][i];
    } else if(digit != ans[1][i]) {
      fail = true;
    }
  }
  if(fail) {
    printf("0\n");
  } else {
    printf("%d\n", digit);
  }
  
  return 0;
}
