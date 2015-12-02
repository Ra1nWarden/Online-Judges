#include <cstdio>

using namespace std;

const int maxn = 10;
int digit[maxn+1];

int main() {
  int na, ba, nb, bb;
  long long a = 0;
  scanf("%d%d", &na, &ba);
  for(int i = na-1; i > -1; i--)
    scanf("%d", &digit[i]);
  long long base = 1;
  for(int i = 0; i < na; i++) {
    a += base * digit[i];
    base = base * ba;
  }
  scanf("%d%d", &nb, &bb);
  long long b = 0;
  for(int i = nb-1;i >-1; i--)
    scanf("%d", &digit[i]);
  base = 1;
  for(int i = 0; i < nb; i++) {
    b += base * digit[i];
    base = base * bb;
  }
  if(a == b) {
    printf("=\n");
  } else if(a < b) {
    printf("<\n");
  } else {
    printf(">\n");
  }
  
  return 0;
}
