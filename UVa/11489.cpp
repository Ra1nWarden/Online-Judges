#include <cstdio>
#include <cstring>

using namespace std;

const int maxn = 1000;
char digits[maxn+5];
int remainder[3];
int l;

int main() {
  int tc;
  scanf("%d\n", &tc);
  for(int kase = 1; kase <= tc; kase++) {
    scanf("%s\n", digits);
    memset(remainder, 0, sizeof remainder);
    l = strlen(digits);
    int sum = 0;
    for(int i = 0; i < l; i++) {
      int digit = digits[i] - '0';
      sum += digit;
      remainder[digit % 3]++;
    }
    bool s = true;
    if(sum % 3 == 0) {
      s = remainder[0] & 1;
    } else {
      if(remainder[sum % 3]) {
	s = !(remainder[0] & 1);
      } else {
	s = false;
      }
    }
    printf("Case %d: %c\n", kase, s ? 'S' : 'T');
  }
  return 0;
}
