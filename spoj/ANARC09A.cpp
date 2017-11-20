#include <cstdio>
#include <cstring>

using namespace std;

const int maxl = 2000;
char str[maxl+5];
int dp[maxl+5][maxl+5];
int l;

int main() {
  int kase = 1;
  while(scanf("%s\n", str) != EOF) {
    if(str[0] == '-')
      break;
    l = strlen(str);
    int s = 0;
    int ans = 0;
    for(int i = 0; i < l; i++) {
      if(str[i] == '{') {
	if(s == l - i) {
	  ans++;
	  s--;
	} else {
	  s++;
	}
      } else if(str[i] == '}') {
	if(s == 0) {
	  ans++;
	  s++;
	} else {
	  s--;
	}
      }
    }
    printf("%d. %d\n", kase++, ans);
  }
  return 0;
}
