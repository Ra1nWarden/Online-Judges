#include <cstdio>
#include <cstring>

using namespace std;

const int maxn = 100;
char str[maxn+5];
bool used[maxn+5];
int len;

int main() {
  scanf("%s", str);
  len = strlen(str);
  int ans = 0;
  memset(used, false, sizeof used);
  for(int i = 0; i < len - 1; i++) {
    if(str[i] == 'V' && str[i+1] == 'K') {
      ans++;
      used[i] = true;
      used[i+1] = true;
    }
  }
  for(int i = 0; i < len - 1; i++) {
    if(!used[i] && !used[i+1] && str[i] == str[i+1]) {
      ans++;
      break;
    }
  }
  printf("%d\n", ans);
  return 0;
}
