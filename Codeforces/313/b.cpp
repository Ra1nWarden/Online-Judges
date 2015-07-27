#include <cstdio>
#include <cstring>
#define MAXL 200005
#define MAXN 26

using namespace std;

char astr[MAXL];
char bstr[MAXL];
int n;

int tree[2][26][MAXL];

int lowbit(int x) {
  return x & (-x);
}

int sum(int x, int c, int t) {
  int ret = 0;
  while(x > 0) {
    ret += tree[t][c][x];
    x -= lowbit(x);
  }
  return ret;
}

void add(int x, int c, int t) {
  while(x <= 200000) {
    tree[t][c][x] += 1;
    x += lowbit(x);
  }
}

int query(int start, int end, int character, int t) {
  return sum(end, character, t) - sum(start - 1, character, t);
}

bool ok(int astart, int aend, int bstart, int bend) {
  //printf("ok(%d %d %d %d)\n", astart, aend, bstart, bend);
  int length = aend - astart + 1;
  if(length % 2) {
    int j = bstart;
    for(int i = astart; i <= aend; i++) {
      if(astr[i-1] != bstr[j-1]) {
	//printf("false\n");
	return false;
      }
      j++;
    }
    //printf("true\n");
    return true;
  }
  // sum check
  for(int i = 0; i < 26; i++) {
    int asum = query(astart, aend, i, 0);
    int bsum = query(bstart, bend, i, 1);
    if(asum != bsum) {
      //printf("false\n");
      return false;
    }
  }
  int amid = (astart + aend) >> 1;
  int bmid = (bstart + bend) >> 1;
  bool ans = (ok(astart, amid, bstart, bmid) && ok(amid + 1, aend, bmid + 1, bend)) || (ok(astart, amid, bmid + 1, bend) && ok(amid+1, aend, bstart, bmid));
  // if(ans)
  //   printf("true\n");
  // else
  //   printf("false\n");
  return ans;
}

int main() {
  scanf("%s\n", astr);
  scanf("%s\n", bstr);
  n = strlen(astr);
  memset(tree, 0, sizeof tree);
  for(int i = 1; i <= n; i++) {
    int ac = astr[i-1] - 'a';
    int bc = bstr[i-1] - 'a';
    add(i, ac, 0);
    add(i, bc, 1);
  }
  if(ok(1, n, 1, n)) {
    printf("YES\n");
  } else {
    printf("NO\n");
  }
  return 0;
}
