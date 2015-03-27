#include <cstdio>
#include <cstring>
#include <cctype>
#define MAXN 105

using namespace std;

char str[MAXN];
bool alph[26];
int n;

int main() {
  scanf("%d\n", &n);
  scanf("%s\n", str);
  memset(alph, false, sizeof alph);
  for(int i = 0; i < n; i++) {
    alph[tolower(str[i]) - 'a'] = true;
  }
  for(int i = 0; i < 26; i++) {
    if(!alph[i]) {
      printf("NO\n");
      return 0;
    }
  }
  printf("YES\n");
  return 0;
}
