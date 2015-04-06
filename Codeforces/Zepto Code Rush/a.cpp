#include <cstdio>
#define MAXL 105

using namespace std;

char str[MAXL];
int l;

int main() {
  scanf("%d\n", &l);
  scanf("%s\n", str);
  for(int i = 0; i < l; i++) {
    if(str[i] == '*') {
      for(int j = i+1; j < l; j++) {
	if(str[j] == '*') {
	  int diff = j - i;
	  if(j + diff >= l || j+diff + diff >= l || j+diff+diff >= l)
	    break;
	  if(str[j+diff] == '*' && str[j+diff+diff] == '*' && str[j+diff+diff+diff] == '*') {
	    printf("yes\n");
	    return 0;
	  }
	}
      }
    }
  }
  printf("no\n");
  return 0;
}
