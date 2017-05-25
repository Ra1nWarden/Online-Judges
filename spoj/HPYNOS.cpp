#include <cstdio>
#include <set>

using namespace std;

int main() {
  int num;
  scanf("%d", &num);
  set<int> s;
  while(s.count(num) == 0) {
    s.insert(num);
    int next = 0;
    while(num) {
      int dig = num % 10;
      num /= 10;
      next += dig * dig;
    }
    num = next;
  }
  if(num == 1) {
    printf("%d\n", s.size() - 1);
  } else {
    printf("-1\n");
  }
  return 0;
}
