#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int maxn = 100;
char str[maxn+5];

int main() {
  scanf("%s", str+1);
  int prev = 0;
  int ans = 0;
  for(int i = 1; i > 0; i++) {
    if(str[i] == '\0') {
      ans = max(ans, i - prev);
      break;
    } else if(str[i] == 'A' || str[i] == 'E' || str[i] == 'I' || str[i] == 'O' || str[i] == 'U' || str[i] == 'Y') {
      ans = max(ans, i - prev);
      prev = i;
    }
  }
  printf("%d\n", ans);
  return 0;
}
