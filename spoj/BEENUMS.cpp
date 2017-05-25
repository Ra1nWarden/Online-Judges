#include <cstdio>
#include <set>

using namespace std;

set<int> s;

void init() {
  s.insert(1);
  int prev = 1;
  for(int num = 6; prev + num <= 1000000000; num += 6) {
    prev += num;
    s.insert(prev);
  }
}

int main() {
  init();
  int num;
  while(scanf("%d", &num) != EOF) {
    if(num == -1)
      break;
    printf("%c\n", s.count(num) ? 'Y' : 'N');
  }
  return 0;
}
