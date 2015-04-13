#include <cstdio>
#include <cstring>
#define MAXN 1005

using namespace std;

int addresses[MAXN][4];
int n;
int minip[4];
int mask[4];

int main() {
  while(scanf("%d", &n) != EOF) {
    for(int i = 0; i < n; i++) {
      scanf("%d.%d.%d.%d\n", &addresses[i][0], &addresses[i][1], &addresses[i][2], &addresses[i][3]);
    }
    memset(minip, 0, sizeof minip);
    memset(mask, 0, sizeof mask);
    bool term = false;
    for(int i = 0; i < 4; i++) {
      for(int j = 7; j > -1; j--) {
	int num = -1;
	for(int ii = 0; ii < n; ii++) {
	  int bitat = (addresses[ii][i] & (1 << j)) == 0 ? 0 : 1;
	  if(num != -1 && num != bitat){
	    term = true;
	    break;
	  }
	  if(num == -1)
	    num = bitat;
	}
	if(term)
	  break;
	if(num) {
	  minip[i] = minip[i] | (1 << j);
	}
	  mask[i] = mask[i] | (1 << j);
      }
      if(term)
	break;
    }
    printf("%d.%d.%d.%d\n", minip[0], minip[1], minip[2], minip[3]);
    printf("%d.%d.%d.%d\n", mask[0], mask[1], mask[2], mask[3]);
  }
  return 0;
}
