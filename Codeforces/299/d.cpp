#include <cstdio>
#include <cstdlib>
#include <cstring>
#define MAXL 1000005
#define MOD 1000000007

using namespace std;

char p[MAXL];
int f[MAXL];

void kmp_init() {
  int len = strlen(p);
  f[0] = f[1] = 0;
  for(int i = 1; i < len; i++) {
    int j = f[i];
    while(j && p[i] != p[j])
      j = f[j];
    f[i+1] = p[i] == p[j] ? j+1 : 0;
  }
}

int main() {
  int n, m;
  scanf("%d %d\n", &n, &m);
  scanf("%s\n", p);
  kmp_init();

  int nn = n;
  int pn = strlen(p);
  int prev;
  bool ok = true;
  for(int i = 0; i < m; i++) {
    int pos;
    scanf("%d", &pos);
    if(!ok)
      continue;
    if(i == 0) {
      prev = pos;
      nn -= pn;
      continue;
    } else {
      if(pos - prev >= pn) {
	prev = pos;
	nn -= pn;
      } else{
	int fail = prev + pn - pos;
	int nextfail = f[pn];
	while(nextfail != fail && nextfail > 0) {
	  nextfail = f[nextfail];
	}
	ok = nextfail == fail;
	if(ok) {
	  nn -= pn;
	  nn += (pn - pos + prev);
	  prev = pos;
	}
      }
    }
  }
  if(!ok)
    printf("0\n");
  else {
    int ans = 1;
    for(int i = 0; i < nn; i++) {
      ans = ((long long) ans * 26) % MOD;
    }
    printf("%d\n", ans);
  }
  return 0;
}
