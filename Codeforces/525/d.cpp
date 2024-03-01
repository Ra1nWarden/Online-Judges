#include <cstdio>
#include <map>
#include <utility>

using namespace std;

typedef pair<int, int> II;

map<II, int> memo;

int query(int c, int d) {
  II k = make_pair(c, d);
  if(memo.count(k)) {
    return memo[k];
  }
  printf("? %d %d\n", c, d);
  fflush(stdout);
  int ans;
  scanf("%d", &ans);
  return memo[k] = ans;
}

int main() {
  int a = 0, b = 0;
  int c = 0, d = 0;
  int q = query(c, d);
  bool eq = false;
  for(int i = 29; i >= 0; i--) {
    if(eq || q == 0) {
      eq = true;
      c |= (1 << i);
      int qq = query(c, d);
      if(qq < 0) {
	a |= (1 << i);
	b |= (1 << i);
      }
      c = a;
      d = b;
    } else {
      c |= (1 << i);
      d |= (1 << i);
      int qq = query(c, d);
      if(qq == q) {
	d ^= (1 << i);
	int qqq = query(c, d);
	if(qqq < 0) {
	  a |= (1 << i);
	  b |= (1 << i);
	}
      } else {
	if(q < 0)
	  b |= (1 << i);
	else
	  a |= (1 << i);
      }
      c = a;
      d = b;
      q = query(c, d);
    }
  }
  printf("! %d %d\n", a, b);
  fflush(stdout);
  return 0;
}
