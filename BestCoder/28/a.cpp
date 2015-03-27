#include <cstdio>
#include <cstring>

using namespace std;

int numbers[1001];

int main() {
  int tc;
  scanf("%d", &tc);
  for(int et = 0; et < tc; et++) {
    int n;
    scanf("%d", &n);
    memset(numbers, false, sizeof numbers);
    for(int i = 0; i < n; i++) {
      int x;
      scanf("%d", &x);
      numbers[x] = true;
    }
    int printed = 0;
    for(int i = 1; i <= 1000; i++) {
      if(!numbers[i]) {
	if(printed == 0) {
	  printf("%d ", i);
	  printed++;
	} else {
	  printf("%d\n", i);
	  break;
	}
      }
    }
  }
  return 0;
}
