#include <cstdio>

using namespace std;

char num[20];

int gcd(int a, int b) {
  if(b == 0)
    return a;
  return gcd(b, a%b);
}

int main() {
  int tc;
  scanf("%d", &tc);
  while(tc--) {
    scanf("%s", num);
    int numer = 0;
    int denom = 1;
    bool dot = false;
    for(int i = 0; num[i] != '\0'; i++) {
      if(num[i] == '.') {
	dot = true;
	continue;
      }
      if(!dot)
	continue;
      int dig = num[i] - '0';
      numer = numer * 10 + dig;
      denom *= 10;
    }
    printf("%d\n", denom / gcd(denom, numer));
  }
  return 0;
}
