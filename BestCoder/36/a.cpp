#include <cstdio>
#include <cstdlib>
#include <cstring>
#define MAXL 15

using namespace std;

char name[MAXL];
int counter[26];

int main() {
  while(scanf("%s", name) != EOF) {
    char prev = -1;
    int diff = 0;
    memset(counter, 0, sizeof counter);
    for(int i = 0; i < strlen(name); i++) {
      if(name[i] != prev) {
	diff++;
	prev = name[i];
      }
      counter[name[i]-'a']++;
    }
    if(diff == 3) {
      int n = -1;
      bool ok = true;
      for(int i = 0; i < 26; i++) {
	if(counter[i] != 0) {
	  if(n == -1)
	    n = counter[i];
	  else {
	    if(counter[i] != n) {
	      ok = false;
	      break;
	    }
	  }
	}
      }
      if(ok)
	printf("YES\n");
      else
	printf("NO\n");
    }
    else
      printf("NO\n");
  }
  return 0;
}
