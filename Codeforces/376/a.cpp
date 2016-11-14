#include <cstdio>
#include <algorithm>

using namespace std;

const int maxn = 100;
char str[maxn+5];

int diff(char a, char b) {
  int ans = a - b;
  if(ans < 0)
    ans += 26;
  return ans;
}

int main() {
  scanf("%s", str);
  int ans = 0;
  char cur = 'a';
  for(int i = 0; i >= 0; i++) {
    if(str[i] == '\0')
      break;
    char next = str[i];
    ans += min(diff(cur, next), diff(next, cur));
    cur = next;
  }
  printf("%d\n", ans);
  return 0;
}
