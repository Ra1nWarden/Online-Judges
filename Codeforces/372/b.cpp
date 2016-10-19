#include <cstdio>
#include <cstring>

using namespace std;

const int alpha = 26;
const int maxn = 50000;
char str[maxn+5];
int check[alpha];

int main() {
  scanf("%s", str);
  int s = 0, u = 0, v = 0;
  memset(check, 0, sizeof check);
  for(int i = 0; i < 26; i++) {
    if(str[i] == '\0') {
      printf("-1\n");
      return 0;
    }
    char c = str[i];
    if(c == '?') {
      u++;
    } else if(check[c - 'A'] == 0) {
      v++;
      check[c - 'A']++;
    } else {
      check[c - 'A']++;
    }
  }
  while(true) {
    //printf("s = %d u + v = %d\n", s, u + v);
    if(u + v == 26) {
      int ci = 0;
      for(int i = 0; i >= 0; i++) {
	if(str[i] == '\0') {
	  printf("\n");
	  break;
	}
	if(i < s || i >= s + 26) {
	  if(str[i] == '?')
	    printf("A");
	  else
	    printf("%c", str[i]);
	  continue;
	}
	if(str[i] == '?') {
	  while(check[ci] > 0)
	    ci++;
	  printf("%c", 'A' + ci);
	  check[ci]++;
	} else
	  printf("%c", str[i]);
      }
      return 0;
    } else if(str[s + 26] != '\0'){
      if(str[s] == '?') {
	u--;
      } else {
	check[str[s] - 'A']--;
	if(check[str[s] - 'A'] == 0) {
	  v--;
	}
      }
      if(str[s + 26] == '?') {
	u++;
      } else if(check[str[s + 26] - 'A'] == 0){
	check[str[s + 26] - 'A']++;
	v++;
      } else {
	check[str[s + 26] - 'A']++;
      }
      s++;
    } else {
      break;
    }
  }
  printf("-1\n");
  return 0;
}
