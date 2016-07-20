#include <cstdio>
#include <cstring>

using namespace std;

const int maxl = 10;
char str[maxl];
char yes[] = "yes";
int v[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47};

int main() {
  int prime = 0;
  int div = -1;
  for(int i = 0; i < 15; i++) {
    printf("%d\n", v[i]);
    fflush(stdout);
    scanf("%s", str);
    if(strcmp(yes, str) == 0) {
      prime++;
      div = v[i];
      if(prime > 1)
	break;
    }
  }
  if(prime == 1 && div * div <= 100) {
    printf("%d\n", div * div);
    fflush(stdout);
    scanf("%s", str);
    if(strcmp(yes, str) == 0) {
      prime++;
    }
  }
  printf("%s\n", prime <= 1 ? "prime" : "composite");
  return 0;
}
