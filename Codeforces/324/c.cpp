#include <cstdio>
#include <cstring>

using namespace std;

const int maxl = 100000;

char s1[maxl+5];
char s2[maxl+5];
char s3[maxl+5];
int n, t;

char change(char ch) {
  for(char c = 'a'; c <= 'z'; c++) {
    if(c != ch) {
      return c;
    }
  }
}

char change(char ch1, char ch2) {
  for(char c = 'a'; c <= 'z'; c++) {
    if(c != ch1 && c != ch2) {
      return c;
    }
  }
}

int main() {
  scanf("%d%d\n", &n, &t);
  scanf("%s\n", s1);
  scanf("%s\n", s2);
  int diff = 0;
  for(int i = 0; i < n; i++) {
    if(s1[i] != s2[i]) {
      diff++;
    }
  }
  if(t == 0) {
    if(diff == 0) {
      printf("%s\n", s1);
    } else {
      printf("-1\n");
    }
    return 0;
  }
  if(t <= (diff - 1) / 2 || t > n) {
    printf("-1\n");
  } else {
    memset(s3, 0, sizeof s3);
    for(int i = 0; i < n && t > diff; i++) {
      if(s1[i] == s2[i]) {
	t--;
	s3[i] = change(s1[i]);
      }
    }
    int q1 = diff - t;
    int q2 = diff - t;
    for(int i = 0; i < n; i++) {
      if(s3[i] != 0) {
	continue;
      }
      if(s1[i] == s2[i]) {
	s3[i] = s1[i];
      } else {
	if(q1) {
	  s3[i] = s1[i];
	  q1--;
	} else if(q2) {
	  s3[i] = s2[i];
	  q2--;
	} else {
	  s3[i] = change(s1[i], s2[i]);
	}
      }
    }
    printf("%s\n", s3);
  }
  return 0;
}
