#include <cstdio>
#include <cstring>
#include <cctype>

using namespace std;

const int maxn = 100;
char str[maxn+5];

int main() {
  while(scanf("%s", str) != EOF) {
    int l;
    bool java = false, cpp = false;
    for(l = 0; l >= 0; l++) {
      if(l == 0 && (isupper(str[l]) || str[l] == '_')) {
	java = cpp = true;
	break;
      }
      if(str[l] == '\0') {
	break;
      }
      if(str[l] == '_') {
	cpp = true;
	if((l && str[l-1] == '_') || str[l+1] == '\0') {
	  java = true;
	  break;
	}
      } else if(isupper(str[l]))
	java = true;
    }
    if(java && cpp) {
      printf("Error!\n");
      continue;
    }
    if(java) {
      for(int i = 0; i < l; i++) {
	if(isupper(str[i])) {
	  printf("_%c", tolower(str[i]));
	} else {
	  printf("%c", str[i]);
	}
      }
    } else {
      bool upper = false;
      for(int i = 0; i < l; i++) {
	if(str[i] == '_') {
	  upper = true;
	  continue;
	}
	if(upper) {
	  printf("%c", toupper(str[i]));
	  upper = false;
	} else {
	  printf("%c", str[i]);
	}
      }
    }
    printf("\n");
  }
  return 0;
}
