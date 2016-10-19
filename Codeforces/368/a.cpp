#include <cstdio>

using namespace std;

int main() {
  int n, m;
  char c;
  scanf("%d%d\n", &n, &m);
  bool bw = true;
  for(int i = 0; i < n; i++) {
    for(int j = 0; j < m; j++) {
      if(j)
	scanf(" %c\n", &c);
      else
	scanf("%c", &c);
      if(c == 'C' || c == 'M' || c == 'Y') {
	bw = false;
	break;
      }
    }
    if(!bw)
      break;
  }
  printf("%s\n", bw ? "#Black&White" : "#Color");
  return 0;
}
