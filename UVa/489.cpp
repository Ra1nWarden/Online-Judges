#include <cstdio>
#include <cstring>
#define MAXN 100
#define SIGMA 26

using namespace std;

char ans[MAXN];
char guess[MAXN];
bool used[SIGMA];

int main() {
  int tc;
  while(scanf("%d\n", &tc) != EOF && tc != -1) {
    scanf("%s\n%s\n", ans, guess);
    memset(used, false, sizeof used);
    for(int i = 0; i < strlen(ans); i++) {
      used[ans[i] - 'a'] = true;
    }
    int chars = 0;
    for(int i = 0; i < 26; i++) {
      if(used[i])
	chars++;
    }
    int wrong = 0;
    int correct = 0;
    for(int i = 0; i < strlen(guess); i++) {
      if(used[guess[i] - 'a']) {
	correct++;
	used[guess[i] - 'a'] = false;
	if(correct == chars)
	  break;
      } else {
	wrong++;
	if(wrong > 6)
	  break;
      }
    }
    printf("Round %d\n", tc);
    if(correct == chars) {
      printf("You win.\n");
    } else if(wrong > 6) {
      printf("You lose.\n");
    } else {
      printf("You chickened out.\n");
    }
 
  }
  return 0;
}
