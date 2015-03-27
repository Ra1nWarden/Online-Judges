#include <cstdio>
#include <algorithm>
#define MAXN 500005

using namespace std;

int n;
int pos[MAXN];
int neg[MAXN];

int main() {
  int tc;
  scanf("%d", &tc);
  while(tc--) {
    scanf("%d", &n);
    int posi = 0;
    int negi = 0;
    int x;
    for(int i = 0; i < n; i++) {
      scanf("%d", &x);
      if(x > 0) {
	pos[posi++] = x;
      } else {
	neg[negi++] = -x;
      }
    }
    if(posi == 0 || negi == 0) {
      printf("1\n");
      continue;
    }
    sort(pos, pos + posi);
    sort(neg, neg + negi);
    int negstart = 1;
    int prev = neg[0];
    bool next = true;
    while(true) {
      if(next) {
	int nexti = upper_bound(pos, pos+posi, prev) - pos;
	if(nexti == posi)
	  break;
	prev = pos[nexti];
	negstart++;
	next = false;
      } else {
	int nexti = upper_bound(neg, neg+negi, prev) - neg;
	if(nexti == negi)
	  break;
	prev = neg[nexti];
	negstart++;
	next = true;
      }
    }
    int posstart = 1;
    prev = pos[0];
    next = false;
    while(true) {
      if(next) {
	int nexti = upper_bound(pos, pos+posi, prev) - pos;
	if(nexti == posi)
	  break;
	prev = pos[nexti];
	posstart++;
	next = false;
      } else {
	int nexti = upper_bound(neg, neg+negi, prev) - neg;
	if(nexti == negi)
	  break;
	prev = neg[nexti];
	posstart++;
	next = true;
      }
    }
    printf("%d\n", max(posstart, negstart));
  }
  return 0;
}
