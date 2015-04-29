#include <cstdio>
#define MAXL 100

using namespace std;

int n, l, cnt;
int S[MAXL];

bool dfs(int cur) {
  if(cnt++ == n) {
    for(int i = 0; i < cur; i++) {
      if(i % 64 == 0 && i > 0)
	printf("\n");
      else if(i % 4 == 0 && i > 0)
	printf(" ");
      printf("%c", 'A' + S[i]);
    }
    printf("\n%d\n", cur);
    return true;
  }
  for(int i = 0; i < l; i++) {
    S[cur] = i;
    bool ok = true;
    for(int j = 1; j*2 <= cur + 1; j++) {
      bool equal = true;
      for(int k = 0; k < j; k++) {
	if(S[cur - k] != S[cur - k - j]) {
	  equal = false;
	  break;
	}
      }
      if(equal) {
	ok = false;
	break;
      }
    }
    if(ok) {
      if(dfs(cur+1))
	return true;
    }
  }
  return false;
}

int main() {
  while(scanf("%d %d", &n, &l) != EOF && (n || l)) {
    cnt = 0;
    dfs(0);
  }
  return 0;
}
