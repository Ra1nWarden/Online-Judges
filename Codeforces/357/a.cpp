#include <cstdio>

using namespace std;

const int maxl = 10;
char name[maxl+5];

int main() {
  int n;
  scanf("%d\n", &n);
  bool ans = false;
  while(n--) {
    int bef, aft;
    scanf("%s %d %d\n", name, &bef, &aft);
    if(aft > bef && bef >= 2400) {
      ans = true;
    }
  }
  printf("%s\n", ans ? "YES" : "NO");
  return 0;
}
