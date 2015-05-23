#include <cstdio>
#include <cstring>
#define MAXN 100005

using namespace std;

char s[MAXN], t[MAXN], p[MAXN];
int l;

int main() {
  scanf("%s\n", s);
  scanf("%s\n", t);
  l = strlen(s);
  int diff = 0;
  for(int i =0; i < l; i++) {
    if(s[i] != t[i]) {
      diff++;
    }
  }
  if(diff % 2)
    printf("impossible\n");
  else {
    int side = 0;
    for(int i = 0; i < l; i++) {
      if(s[i] == t[i])
	p[i] = s[i];
      else {
	if(side < diff / 2) {
	  p[i] = s[i];
	  side++;
	} else {
	  p[i] = t[i];
	}
      }
    }
    printf("%s\n", p);
  }
  return 0;
}
