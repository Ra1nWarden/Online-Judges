#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int maxn = 1000;
char str[maxn+5];
int cnt[26];

int main() {
  while(scanf("%s\n", str) != EOF) {
    memset(cnt, 0, sizeof cnt);
    for(int i = 0; str[i] != '\0'; i++) {
      cnt[str[i] - 'a']++;
    }
    int wi = 0;
    scanf("%s\n", str);
    for(int i = 0; str[i] != '\0'; i++) {
      if(cnt[str[i] - 'a']) {
	str[wi++] = str[i];
	cnt[str[i] - 'a']--;
      }
    }
    str[wi] = '\0';
    sort(str, str + wi);
    printf("%s\n", str);
  }
  return 0;
}
