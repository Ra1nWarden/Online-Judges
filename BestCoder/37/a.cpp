#include <cstdio>
#define MAXN 1005

using namespace std;

int n;
char str[MAXN];
int ques[MAXN];
int qi;

bool fill(int i) {
  if(i == qi) {
    bool palin = true;
    for(int ii = 0; ii < n / 2; ii++) {
      if(str[ii] != str[n-1-ii]) {
	palin = false;
	break;
      }
    }
    return !palin;
  }
  int ii = ques[i];
  for(int f = 0; f < 26; f++) {
    char next = 'a' + f;
    str[ii] = next;
    if(fill(i+1)) {
      return true;
    }
  }
  return false;
}

int main() {
  while(scanf("%d\n", &n) != EOF) {
    scanf("%s\n", str);
    qi = 0;
    for(int i = 0; i < n; i++) {
      if(str[i] == '?') {
	ques[qi++] = i;
      }
    }
    if(qi == 0) {
      bool palin = true;
      for(int i = 0; i < n / 2; i++) {
	if(str[i] != str[n-1-i]) {
	  palin = false;
	  break;
	}
      }
      if(palin) {
	printf("QwQ\n");
      } else {
	printf("%s\n", str);
      }
    } else {
      if(fill(0)) {
	printf("%s\n", str);
      } else {
	printf("QwQ\n");
      }
    }
  }
  return 0;
}
