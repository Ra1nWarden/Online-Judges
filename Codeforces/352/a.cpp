#include <cstdio>
#include <sstream>

using namespace std;

int main() {
  int n;
  scanf("%d", &n);
  stringstream ss;
  for(int i = 1; ss.tellp() < n && i <= 1000; i++) {
    ss << i;
  }
  printf("%c\n", ss.str()[n - 1]);
  return 0;
}
