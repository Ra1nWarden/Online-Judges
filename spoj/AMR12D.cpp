#include <cstdio>
#include <cstring>

using namespace std;

const int maxn = 10;
char str[maxn+5];
int len;

int main() {
  int tc;
  scanf("%d\n", &tc);
  while(tc--) {
    scanf("%s\n", str);
    len = strlen(str);
    bool check = true;
    for(int i = 0; i < len / 2; i++) {
      if(str[i] != str[len - 1 - i]) {
	check = false;
	break;
      }
    }
    printf("%s\n", check ? "YES" : "NO");
  }
  return 0;
}
