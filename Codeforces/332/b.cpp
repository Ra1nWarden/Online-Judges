#include <cstdio>
#include <cstring>

using namespace std;

const int maxn = 100000;
int f[maxn+1], a[maxn+1], finv[maxn+1];
bool r[maxn+1];
int n, m;

int main() {
  memset(finv, -1, sizeof finv);
  memset(r, false, sizeof r);
  scanf("%d%d", &n, &m);
  for(int i = 1; i <= n; i++) {
    scanf("%d", &f[i]);
    if(finv[f[i]] == -1) {
      finv[f[i]] = i;
    } else {
      r[f[i]] = true;
    }
  }
  bool possible = true;
  bool ambiguous = false;
  for(int i = 0; i < m; i++) {
    int num;
    scanf("%d", &num);
    if(finv[num] == -1) {
      possible = false;
    }
    if(r[num]) {
      ambiguous = true;
    }
    a[i] = finv[num];
  }
  if(!possible) {
    printf("Impossible\n");
  } else if(ambiguous) {
    printf("Ambiguity\n");
  } else {
    printf("Possible\n");
    for(int i = 0; i < m; i++) {
      if(i > 0)
	printf(" ");
    printf("%d", a[i]);
    }
    printf("\n");
  }
  return 0;
}
