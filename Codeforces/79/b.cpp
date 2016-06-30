#include <cstdio>
#include <cstring>

using namespace std;

const int maxl = 100000;

char str[maxl+5];
int n;

int main() {
  scanf("%s", str);
  n = strlen(str);
  if(n == 1) {
    printf("0\n");
    return 0;
  }
  int num = 0;
  int ans = 1;
  for(int i = 0; i < n; i++)
    num += str[i] - '0';
  while(num >= 10) {
    int new_num = 0;
    while(num) {
      new_num += num % 10;
      num /= 10;
    }
    num = new_num;
    ans++;
  }
  printf("%d\n", ans);
  return 0;
}
