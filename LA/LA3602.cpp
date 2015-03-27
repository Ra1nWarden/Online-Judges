#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

int n, l;
char str[55][1005];

int main() {
  int tc;
  scanf("%d\n", &tc);
  while(tc--) {
    scanf("%d %d\n", &n, &l);
    for(int i = 0; i < n; i++) {
      scanf("%s\n", str[i]);
    }
    int cv[26];
    char ans[1005];
    int anscount = 0;
    for(int i = 0; i < l; i++) {
      memset(cv, 0, sizeof cv);
      int maxcount = 0;
      char maxchar = ' ';
      for(int j= 0; j < n; j++) {
	cv[str[j][i] - 'A']++;
	if(cv[str[j][i] - 'A'] > maxcount) {
	  maxcount = cv[str[j][i] - 'A'];
	  maxchar = str[j][i];
	} else if(cv[str[j][i] - 'A'] == maxcount) {
	  maxchar = min(maxchar, str[j][i]);
	}
      }
      ans[i] = maxchar;
      anscount += (n - maxcount);
    }
    ans[l] = '\0';
    printf("%s\n%d\n", ans, anscount);
  }
  return 0;
}
