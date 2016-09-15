#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int maxl = 100000;
char str[maxl+5];
int cnt[4];

int diff(int a, int b) {
  return max(a, b) - min(a, b);
}

int main() {
  scanf("%s", str);
  memset(cnt, 0, sizeof cnt);
  for(int i = 0; i >= 0; i++) {
    if(str[i] == '\0')
      break;
    switch(str[i]) {
    case 'L':
      cnt[0]++;
      break;
    case 'R':
      cnt[3]++;
      break;
    case 'U':
      cnt[1]++;
      break;
    case 'D':
      cnt[2]++;
      break;
    }
  }
  if((cnt[0] + cnt[1] + cnt[2] + cnt[3]) & 1) {
    printf("-1\n");
  } else {
    if((cnt[0] + cnt[3]) & 1) {
      printf("%d\n", diff(cnt[0] , cnt[3]) / 2 + diff(cnt[1] , cnt[2]) / 2 + 1);
    } else {
      printf("%d\n", diff(cnt[0] , cnt[3]) / 2 + diff(cnt[1] , cnt[2]) / 2);
    }
  }
  return 0;
}
