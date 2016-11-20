#include <cstdio>
#include <cstring>

using namespace std;

const int maxm = 13;
const int maxn = 27;
char str[maxn+5];
int cnt[maxn+5];
char ans[2][15];

int main() {
  scanf("%s", str);
  memset(cnt, 0, sizeof cnt);
  char ch;
  for(int i = 0; i < maxn; i++) {
    cnt[str[i] - 'A']++;
    if(cnt[str[i] - 'A'] == 2) {
      ch = str[i];
    }
  }
  int a = -1, b = -1;
  for(int i = 0; i < 27; i++) {
    if(str[i] == ch) {
      a == -1 ? a = i : b = i;
    }
  }
  if(b - a == 1) {
    printf("Impossible\n");
  } else {
    int c = (b - a + 1) >> 1;
    c--;
    int cur = a;
    int i = 0, j = c;
    while(j >= 0) {
      ans[i][j--] = str[cur++];
    }
    i++;
    j = 0;
    while(cur < b) {
      ans[i][j++] = str[cur++];
    }
    cur = b + 1;
    while(j < 13) {
      cur = cur % maxn;
      ans[i][j++] = str[cur++];
    }
    j--;
    i = 0;
    while(j > c) {
      cur %= maxn;
      ans[i][j--] = str[cur++];
    }
    ans[0][maxm] = ans[1][maxm] = '\0';
    printf("%s\n%s\n", ans[0], ans[1]);
  }
  return 0;
}
