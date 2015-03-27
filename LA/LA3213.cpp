#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#define MAXL 105
#define SIGMA 26

using namespace std;

char str1[MAXL], str2[MAXL];
int count1[SIGMA], count2[SIGMA];

int main() {
  while(scanf("%s\n%s\n", str1, str2) != EOF) {
    memset(count1, 0, sizeof count1);
    memset(count2, 0, sizeof count2);
    int n = strlen(str1);
    for(int i = 0; i < n; i++) {
      count1[str1[i] - 'A']++;
      count2[str2[i] - 'A']++;
    }
    sort(count1, count1 + SIGMA);
    sort(count2, count2 + SIGMA);
    bool ok = true;
    for(int i = 0; i < SIGMA; i++) {
      if(count1[i] != count2[i]) {
	ok = false;
	break;
      }
    }
    printf("%s\n", ok ? "YES" : "NO");
  }
  return 0;
}
