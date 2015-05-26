#include <cstdio>
#include <cstring>
#define MAXN 105

using namespace std;

char s[MAXN], t[MAXN];
bool qmv[MAXN];

int main() {
  int tc;
  scanf("%d\n", &tc);
  for(int kase = 1; kase <= tc; kase++) {
    scanf("%s\n%s\n", s, t);
    memset(qmv, false, sizeof qmv);
    int s1 = 0, t1 = 0, qm = 0;
    for(int i = 0; i < strlen(s); i++) {
      if(s[i] == '1')
	s1++;
      if(s[i] == '?') {
	qmv[i] = true;
	qm++;
      }
      if(t[i] == '1')
	t1++;
    }
    if(s1 > t1) {
      printf("Case %d: -1\n", kase);
    } else {
      int ans = qm;
      qm = t1 - s1;
      for(int i = 0; i < strlen(s); i++) {
	if(s[i] == '?') {
	  if(t[i] == '1' && qm) {
	    s[i] = '1';
	    qm--;
	  } else {
	    s[i] = '0';
	  }
	}
      }
      if(qm) {
	for(int i = 0; i < strlen(s); i++) {
	  if(qmv[i] && t[i] == '0' && qm) {
	    s[i] = '1';
	    qm--;
	  }
	}
      }
      if(qm) {
	for(int i = 0; i < strlen(s); i++) {
	  if(s[i] == '0' && t[i] == '1' && qm) {
	    s[i] = '1';
	    qm--;
	    ans++;
	  }
	}
      }
      for(int i = 0; i < strlen(s); i++) {
	if(s[i] == '1' && t[i] == '0') {
	  ans++;
	}
      }
      printf("Case %d: %d\n", kase, ans);
    }
  }
  return 0;
}
