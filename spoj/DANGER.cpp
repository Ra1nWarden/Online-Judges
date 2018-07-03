#include <cstdio>
#include <sstream>
#include <cstdlib>

using namespace std;

char str[5];

int main() {
  while(scanf("%s\n", str) != EOF) {
    stringstream ss;
    ss << str[0] << str[1];
    int zero = str[3] - '0';
    while(zero--)
      ss << '0';
    int number = atoi(ss.str().c_str());
    if(!number)
      break;
    int base = 1;
    while(base * 2 <= number)
      base <<= 1;
    int left = number - base;
    printf("%d\n", 2 * left + 1);
  }
  return 0;
}
