#include <cstdio>
#include <vector>
#include <utility>
#include <cstring>
#define MAXL 200005

using namespace std;

char s[MAXL];
char t[MAXL];
int n;
int change[26][26];

int main() {
  scanf("%d\n", &n);
  scanf("%s\n", s);
  scanf("%s\n", t);
  int diff = 0;
  memset(change, -1, sizeof change);
  for(int i = 0; i < n; i++) {
    if(s[i] != t[i]) {
      change[s[i] - 'a'][t[i] - 'a'] = i;
      diff++;
    }
  }
  if(diff == 0) {
    printf("0\n");
    printf("-1 -1\n");
  } else {
    for(int i = 0; i < 26; i++) {
      for(int j = i+1; j < 26; j++) {
	if(change[i][j] > -1 && change[j][i] > -1) {
	  printf("%d\n", diff-2);
	  printf("%d %d\n", change[i][j] + 1, change[j][i] + 1);
	  return 0;
	}
      }
    }
    
    for(int i = 0; i < 26; i++) {
      for(int j = 0; j < 26; j++) {
	if(change[i][j] > -1) {
	  for(int k = 0; k < 26; k++) {
	    if(change[j][k] > -1) {
	      printf("%d\n", diff-1);
	      printf("%d %d\n", change[i][j] + 1, change[j][k] + 1);
	      return 0;
	    }
	  }
	}
      }
    }
    printf("%d\n", diff);
    printf("-1 -1\n");
  }
  return 0;
}
