#include <cstdio>

using namespace std;

int main() {
  int cnt = 1;
  for(int i = 1; i <= 1000000000; i++) {
    int ic = i;
    bool ok =true;
    while(ic > 0) {
      if(ic % 10 != 4 && ic % 10 != 7) {
	ok = false;
	break;
      }
      ic /= 10;
    }
    if(ok)
      printf("m[%d]=%d;\n", i, cnt++);
  }
}
