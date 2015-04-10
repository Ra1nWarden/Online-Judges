#include <cstdio>
#include <cstring>
#define MAXN 25

using namespace std;

int n, k, m;
bool ppl[MAXN];

int main() {
  while(scanf("%d %d %d", &n, &k, &m) != EOF && (n || k || m)) {
    memset(ppl, true, sizeof ppl);
    bool init = true;
    int inc = -1;
    int dec = n;
    int printed = 0;
    while(printed < n) {
      if(!init)
	printf(",");

      for(int i = 0; i < k; i++) {
	inc++;
	inc %= n;
	while(!ppl[inc]) {
	  inc++;
	  inc %= n;
	}
      }
      //printf("done\n");
      printf("%3d", inc+1);

      for(int j = 0; j < m; j++) {
	dec--;
	dec = (dec+n) % n;
	while(!ppl[dec]) {
	  dec--;
	  dec = (dec + n) % n;
	}
	//printf("found a people at %d\n", dec);
      }
      if(dec != inc) {
	printf("%3d", dec+1);
	ppl[dec] = false;
	ppl[inc] = false;
	printed += 2;
      } else {
	ppl[inc] = false;
	printed += 1;
      }
      if(printed == n)
	printf("\n");
      init = false;
    }
  }
  return 0;
}
