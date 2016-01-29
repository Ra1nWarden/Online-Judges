#include <cstdio>

using namespace std;

int main() {
  long long l, r, k;
  scanf("%I64d %I64d %I64d", &l, &r, &k);
  long long num = 1;
  bool found = true;
  while(num < l) {
    long long new_num = num * k;
    if(new_num / num != k) {
      found = false;
      break;
    }
    num = new_num;
  }
  if(!found) {
    printf("-1\n");
    return 0;
  }
  bool start = true;
  while(num >= l && num <= r) {
    if(!start)
      printf(" ");
    printf("%I64d", num);
    start = false;
    long long new_num = num * k;
    if(new_num / num != k) {
      break;
    }
    num = new_num;
  }
  if(start)
    printf("-1");
  printf("\n");
  return 0;
}
