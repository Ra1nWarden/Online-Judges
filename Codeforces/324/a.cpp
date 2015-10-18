#include <cstdio>
#include <sstream>

using namespace std;

int main() {
  int n, t;
  scanf("%d%d", &n, &t);
  stringstream ss;
  ss << t;
  while(ss.tellp() < n) {
    ss << 0;
  }
  if(ss.tellp() == n) {
    printf("%s\n", ss.str().c_str());
  } else {
    printf("-1\n");
  }
  return 0;
}
