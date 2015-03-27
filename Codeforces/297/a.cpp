#include <cstdio>
#include <cstdlib>
#include <cstring>
#define MAXN 200010

using namespace std;

int n;
char str[MAXN];
int keys[26];

int main() {
  scanf("%d\n", &n);
  scanf("%s\n", str);
  memset(keys, 0, sizeof keys);
  int ans = 0;
  int l = strlen(str);
  for(int i =0; i < l; i++) {
    if(i % 2 == 0) {
      keys[str[i] - 'a']++;
    } else {
      if(keys[str[i] - 'A'] == 0)
	ans++;
      else
	keys[str[i] - 'A']--;
    }
  }
  printf("%d\n", ans);
  return 0;
}
